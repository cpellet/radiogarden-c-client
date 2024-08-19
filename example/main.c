#include "../include/apiClient.h"
#include "../api/SearchAPI.h"
#include "../api/GeoAPI.h"

#include <mad.h>
#include <pulse/simple.h>
#include <pulse/error.h>

#include <sys/stat.h>
#include <sys/mman.h>

pa_simple *device = NULL;
int error;

int scale(mad_fixed_t sample) {
     /* round */
     sample += (1L << (MAD_F_FRACBITS - 16));
     /* clip */
     if (sample >= MAD_F_ONE)
         sample = MAD_F_ONE - 1;
     else if (sample < -MAD_F_ONE)
         sample = -MAD_F_ONE;
     /* quantize */
     return sample >> (MAD_F_FRACBITS + 1 - 16);
}

void output(struct mad_header const *header, struct mad_pcm *pcm) {
    register int nsamples = pcm->length+1;
    mad_fixed_t const *left_ch = pcm->samples[0], *right_ch = pcm->samples[1];
    static char stream[1152*4];
    if (pcm->channels == 2) {
        while (nsamples--) {
            signed int sample;
            sample = scale(*left_ch++);
            stream[(pcm->length-nsamples)*4 ] = ((sample >> 0) & 0xff);
            stream[(pcm->length-nsamples)*4 +1] = ((sample >> 8) & 0xff);
            sample = scale(*right_ch++);
            stream[(pcm->length-nsamples)*4+2 ] = ((sample >> 0) & 0xff);
            stream[(pcm->length-nsamples)*4 +3] = ((sample >> 8) & 0xff);
        }
        if (pa_simple_write(device, stream, (size_t)1152*4, &error) < 0) {
            fprintf(stderr, "pa_simple_write() failed: %s\n", pa_strerror(error));
            return;
        }
    } else {
        printf("Mono not supported!");
    }
}

int main(int argc, char const *argv[])
{
    static const pa_sample_spec ss = { .format = PA_SAMPLE_S16LE, .rate = 44100, .channels = 2 };
    if (!(device = pa_simple_new(NULL, "radio", PA_STREAM_PLAYBACK, NULL, "playback", &ss, NULL, NULL, &error)))
    {
        fprintf(stderr, __FILE__": pa_simple_new() failed: %s\n", pa_strerror(error));
        return 1;
    }
    struct mad_stream stream;
    struct mad_frame frame;
    struct mad_synth synth;
    mad_stream_init(&stream);
    mad_synth_init(&synth);
    mad_frame_init(&frame);
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    int fd = fileno(fp);
    struct stat metadata;
    if (fstat(fd, &metadata) >= 0) {
        printf("File size %d bytes\n", (int)metadata.st_size);
    } else {
        printf("Failed to stat %s\n", filename);
        fclose(fp);
        return 254;
    }
    char *input_stream = mmap(0, metadata.st_size, PROT_READ, MAP_SHARED, fd, 0);
    mad_stream_buffer(&stream, input_stream, metadata.st_size);
    while(1) {
        if (mad_frame_decode(&frame, &stream)) {
            if (MAD_RECOVERABLE(stream.error)) {
                continue;
            } else if (stream.error == MAD_ERROR_BUFLEN) {
                continue;
            } else {
                break;
            }
        }
        mad_synth_frame(&synth, &frame);
        output(&frame.header, &synth.pcm);
    }
    fclose(fp);
    mad_synth_finish(&synth);
    mad_frame_finish(&frame);
    mad_stream_finish(&stream);
    if (device) pa_simple_free(device);
    return EXIT_SUCCESS;
    // apiClient_t* client = apiClient_create();
    // char stationName[30];
    // printf("Enter a station name to search for: ");
    // scanf("%s", stationName);
    // _search_get_200_response_t* response = SearchAPI_searchGet(client, stationName);
    // listEntry_t* entry;
    // int i = 1;
    // list_ForEach(entry, response->hits->hits)
    // {
    //     search_result_t* station = (search_result_t*)entry->data;
    //     printf("%i. %s (%s)\n", i, station->_source->title, station->_source->subtitle);
    //     i++;
    // }
    // printf("Choose a station by entering its number: ");
    // int choice;
    // scanf("%d", &choice);
    // apiClient_free(client);
    return 0;
}
