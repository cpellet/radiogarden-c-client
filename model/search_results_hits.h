/*
 * search_results_hits.h
 *
 * 
 */

#ifndef _search_results_hits_H_
#define _search_results_hits_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct search_results_hits_t search_results_hits_t;

#include "search_result.h"



typedef struct search_results_hits_t {
    list_t *hits; //nonprimitive container

} search_results_hits_t;

search_results_hits_t *search_results_hits_create(
    list_t *hits
);

void search_results_hits_free(search_results_hits_t *search_results_hits);

search_results_hits_t *search_results_hits_parseFromJSON(cJSON *search_results_hitsJSON);

cJSON *search_results_hits_convertToJSON(search_results_hits_t *search_results_hits);

#endif /* _search_results_hits_H_ */

