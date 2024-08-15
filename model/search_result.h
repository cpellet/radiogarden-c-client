/*
 * search_result.h
 *
 * 
 */

#ifndef _search_result_H_
#define _search_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct search_result_t search_result_t;

#include "search_result__source.h"



typedef struct search_result_t {
    char *_id; // string
    float _score; //numeric
    struct search_result__source_t *_source; //model

} search_result_t;

search_result_t *search_result_create(
    char *_id,
    float _score,
    search_result__source_t *_source
);

void search_result_free(search_result_t *search_result);

search_result_t *search_result_parseFromJSON(cJSON *search_resultJSON);

cJSON *search_result_convertToJSON(search_result_t *search_result);

#endif /* _search_result_H_ */

