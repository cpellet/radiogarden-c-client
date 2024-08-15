/*
 * _search_get_200_response.h
 *
 * 
 */

#ifndef __search_get_200_response_H_
#define __search_get_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _search_get_200_response_t _search_get_200_response_t;

#include "search_results_hits.h"



typedef struct _search_get_200_response_t {
    int api_version; //numeric
    char *version; // string
    char *query; // string
    int took; //numeric
    struct search_results_hits_t *hits; //model

} _search_get_200_response_t;

_search_get_200_response_t *_search_get_200_response_create(
    int api_version,
    char *version,
    char *query,
    int took,
    search_results_hits_t *hits
);

void _search_get_200_response_free(_search_get_200_response_t *_search_get_200_response);

_search_get_200_response_t *_search_get_200_response_parseFromJSON(cJSON *_search_get_200_responseJSON);

cJSON *_search_get_200_response_convertToJSON(_search_get_200_response_t *_search_get_200_response);

#endif /* __search_get_200_response_H_ */

