/*
 * search_results.h
 *
 * 
 */

#ifndef _search_results_H_
#define _search_results_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct search_results_t search_results_t;

#include "search_results_hits.h"



typedef struct search_results_t {
    char *query; // string
    int took; //numeric
    struct search_results_hits_t *hits; //model

} search_results_t;

search_results_t *search_results_create(
    char *query,
    int took,
    search_results_hits_t *hits
);

void search_results_free(search_results_t *search_results);

search_results_t *search_results_parseFromJSON(cJSON *search_resultsJSON);

cJSON *search_results_convertToJSON(search_results_t *search_results);

#endif /* _search_results_H_ */

