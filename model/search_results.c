#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "search_results.h"



search_results_t *search_results_create(
    char *query,
    int took,
    search_results_hits_t *hits
    ) {
    search_results_t *search_results_local_var = malloc(sizeof(search_results_t));
    if (!search_results_local_var) {
        return NULL;
    }
    search_results_local_var->query = query;
    search_results_local_var->took = took;
    search_results_local_var->hits = hits;

    return search_results_local_var;
}


void search_results_free(search_results_t *search_results) {
    if(NULL == search_results){
        return ;
    }
    listEntry_t *listEntry;
    if (search_results->query) {
        free(search_results->query);
        search_results->query = NULL;
    }
    if (search_results->hits) {
        search_results_hits_free(search_results->hits);
        search_results->hits = NULL;
    }
    free(search_results);
}

cJSON *search_results_convertToJSON(search_results_t *search_results) {
    cJSON *item = cJSON_CreateObject();

    // search_results->query
    if(search_results->query) {
    if(cJSON_AddStringToObject(item, "query", search_results->query) == NULL) {
    goto fail; //String
    }
    }


    // search_results->took
    if(search_results->took) {
    if(cJSON_AddNumberToObject(item, "took", search_results->took) == NULL) {
    goto fail; //Numeric
    }
    }


    // search_results->hits
    if(search_results->hits) {
    cJSON *hits_local_JSON = search_results_hits_convertToJSON(search_results->hits);
    if(hits_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "hits", hits_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

search_results_t *search_results_parseFromJSON(cJSON *search_resultsJSON){

    search_results_t *search_results_local_var = NULL;

    // define the local variable for search_results->hits
    search_results_hits_t *hits_local_nonprim = NULL;

    // search_results->query
    cJSON *query = cJSON_GetObjectItemCaseSensitive(search_resultsJSON, "query");
    if (query) { 
    if(!cJSON_IsString(query) && !cJSON_IsNull(query))
    {
    goto end; //String
    }
    }

    // search_results->took
    cJSON *took = cJSON_GetObjectItemCaseSensitive(search_resultsJSON, "took");
    if (took) { 
    if(!cJSON_IsNumber(took))
    {
    goto end; //Numeric
    }
    }

    // search_results->hits
    cJSON *hits = cJSON_GetObjectItemCaseSensitive(search_resultsJSON, "hits");
    if (hits) { 
    hits_local_nonprim = search_results_hits_parseFromJSON(hits); //nonprimitive
    }


    search_results_local_var = search_results_create (
        query && !cJSON_IsNull(query) ? strdup(query->valuestring) : NULL,
        took ? took->valuedouble : 0,
        hits ? hits_local_nonprim : NULL
        );

    return search_results_local_var;
end:
    if (hits_local_nonprim) {
        search_results_hits_free(hits_local_nonprim);
        hits_local_nonprim = NULL;
    }
    return NULL;

}
