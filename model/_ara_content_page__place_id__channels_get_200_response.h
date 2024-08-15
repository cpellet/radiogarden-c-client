/*
 * _ara_content_page__place_id__channels_get_200_response.h
 *
 * 
 */

#ifndef __ara_content_page__place_id__channels_get_200_response_H_
#define __ara_content_page__place_id__channels_get_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _ara_content_page__place_id__channels_get_200_response_t _ara_content_page__place_id__channels_get_200_response_t;

#include "_ara_content_page__place_id__channels_get_200_response_all_of_data.h"



typedef struct _ara_content_page__place_id__channels_get_200_response_t {
    int api_version; //numeric
    char *version; // string
    struct _ara_content_page__place_id__channels_get_200_response_all_of_data_t *data; //model

} _ara_content_page__place_id__channels_get_200_response_t;

_ara_content_page__place_id__channels_get_200_response_t *_ara_content_page__place_id__channels_get_200_response_create(
    int api_version,
    char *version,
    _ara_content_page__place_id__channels_get_200_response_all_of_data_t *data
);

void _ara_content_page__place_id__channels_get_200_response_free(_ara_content_page__place_id__channels_get_200_response_t *_ara_content_page__place_id__channels_get_200_response);

_ara_content_page__place_id__channels_get_200_response_t *_ara_content_page__place_id__channels_get_200_response_parseFromJSON(cJSON *_ara_content_page__place_id__channels_get_200_responseJSON);

cJSON *_ara_content_page__place_id__channels_get_200_response_convertToJSON(_ara_content_page__place_id__channels_get_200_response_t *_ara_content_page__place_id__channels_get_200_response);

#endif /* __ara_content_page__place_id__channels_get_200_response_H_ */

