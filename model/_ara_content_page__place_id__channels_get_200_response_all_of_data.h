/*
 * _ara_content_page__place_id__channels_get_200_response_all_of_data.h
 *
 * 
 */

#ifndef __ara_content_page__place_id__channels_get_200_response_all_of_data_H_
#define __ara_content_page__place_id__channels_get_200_response_all_of_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _ara_content_page__place_id__channels_get_200_response_all_of_data_t _ara_content_page__place_id__channels_get_200_response_all_of_data_t;

#include "channel_refs.h"



typedef struct _ara_content_page__place_id__channels_get_200_response_all_of_data_t {
    char *title; // string
    char *subtitle; // string
    char *url; // string
    char *map; // string
    int count; //numeric
    int utc_offset; //numeric
    list_t *content; //nonprimitive container

} _ara_content_page__place_id__channels_get_200_response_all_of_data_t;

_ara_content_page__place_id__channels_get_200_response_all_of_data_t *_ara_content_page__place_id__channels_get_200_response_all_of_data_create(
    char *title,
    char *subtitle,
    char *url,
    char *map,
    int count,
    int utc_offset,
    list_t *content
);

void _ara_content_page__place_id__channels_get_200_response_all_of_data_free(_ara_content_page__place_id__channels_get_200_response_all_of_data_t *_ara_content_page__place_id__channels_get_200_response_all_of_data);

_ara_content_page__place_id__channels_get_200_response_all_of_data_t *_ara_content_page__place_id__channels_get_200_response_all_of_data_parseFromJSON(cJSON *_ara_content_page__place_id__channels_get_200_response_all_of_dataJSON);

cJSON *_ara_content_page__place_id__channels_get_200_response_all_of_data_convertToJSON(_ara_content_page__place_id__channels_get_200_response_all_of_data_t *_ara_content_page__place_id__channels_get_200_response_all_of_data);

#endif /* __ara_content_page__place_id__channels_get_200_response_all_of_data_H_ */

