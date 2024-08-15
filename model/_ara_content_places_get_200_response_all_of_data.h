/*
 * _ara_content_places_get_200_response_all_of_data.h
 *
 * 
 */

#ifndef __ara_content_places_get_200_response_all_of_data_H_
#define __ara_content_places_get_200_response_all_of_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _ara_content_places_get_200_response_all_of_data_t _ara_content_places_get_200_response_all_of_data_t;

#include "place.h"



typedef struct _ara_content_places_get_200_response_all_of_data_t {
    list_t *list; //nonprimitive container
    char *version; // string

} _ara_content_places_get_200_response_all_of_data_t;

_ara_content_places_get_200_response_all_of_data_t *_ara_content_places_get_200_response_all_of_data_create(
    list_t *list,
    char *version
);

void _ara_content_places_get_200_response_all_of_data_free(_ara_content_places_get_200_response_all_of_data_t *_ara_content_places_get_200_response_all_of_data);

_ara_content_places_get_200_response_all_of_data_t *_ara_content_places_get_200_response_all_of_data_parseFromJSON(cJSON *_ara_content_places_get_200_response_all_of_dataJSON);

cJSON *_ara_content_places_get_200_response_all_of_data_convertToJSON(_ara_content_places_get_200_response_all_of_data_t *_ara_content_places_get_200_response_all_of_data);

#endif /* __ara_content_places_get_200_response_all_of_data_H_ */

