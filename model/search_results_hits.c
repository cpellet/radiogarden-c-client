#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "search_results_hits.h"



search_results_hits_t *search_results_hits_create(
    list_t *hits
    ) {
    search_results_hits_t *search_results_hits_local_var = malloc(sizeof(search_results_hits_t));
    if (!search_results_hits_local_var) {
        return NULL;
    }
    search_results_hits_local_var->hits = hits;

    return search_results_hits_local_var;
}


void search_results_hits_free(search_results_hits_t *search_results_hits) {
    if(NULL == search_results_hits){
        return ;
    }
    listEntry_t *listEntry;
    if (search_results_hits->hits) {
        list_ForEach(listEntry, search_results_hits->hits) {
            search_result_free(listEntry->data);
        }
        list_freeList(search_results_hits->hits);
        search_results_hits->hits = NULL;
    }
    free(search_results_hits);
}

cJSON *search_results_hits_convertToJSON(search_results_hits_t *search_results_hits) {
    cJSON *item = cJSON_CreateObject();

    // search_results_hits->hits
    if(search_results_hits->hits) {
    cJSON *hits = cJSON_AddArrayToObject(item, "hits");
    if(hits == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *hitsListEntry;
    if (search_results_hits->hits) {
    list_ForEach(hitsListEntry, search_results_hits->hits) {
    cJSON *itemLocal = search_result_convertToJSON(hitsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(hits, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

search_results_hits_t *search_results_hits_parseFromJSON(cJSON *search_results_hitsJSON){

    search_results_hits_t *search_results_hits_local_var = NULL;

    // define the local list for search_results_hits->hits
    list_t *hitsList = NULL;

    // search_results_hits->hits
    cJSON *hits = cJSON_GetObjectItemCaseSensitive(search_results_hitsJSON, "hits");
    if (hits) { 
    cJSON *hits_local_nonprimitive = NULL;
    if(!cJSON_IsArray(hits)){
        goto end; //nonprimitive container
    }

    hitsList = list_createList();

    cJSON_ArrayForEach(hits_local_nonprimitive,hits )
    {
        if(!cJSON_IsObject(hits_local_nonprimitive)){
            goto end;
        }
        search_result_t *hitsItem = search_result_parseFromJSON(hits_local_nonprimitive);

        list_addElement(hitsList, hitsItem);
    }
    }


    search_results_hits_local_var = search_results_hits_create (
        hits ? hitsList : NULL
        );

    return search_results_hits_local_var;
end:
    if (hitsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, hitsList) {
            search_result_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(hitsList);
        hitsList = NULL;
    }
    return NULL;

}
