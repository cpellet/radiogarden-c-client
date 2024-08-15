#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_search_get_200_response.h"



_search_get_200_response_t *_search_get_200_response_create(
    int api_version,
    char *version,
    char *query,
    int took,
    search_results_hits_t *hits
    ) {
    _search_get_200_response_t *_search_get_200_response_local_var = malloc(sizeof(_search_get_200_response_t));
    if (!_search_get_200_response_local_var) {
        return NULL;
    }
    _search_get_200_response_local_var->api_version = api_version;
    _search_get_200_response_local_var->version = version;
    _search_get_200_response_local_var->query = query;
    _search_get_200_response_local_var->took = took;
    _search_get_200_response_local_var->hits = hits;

    return _search_get_200_response_local_var;
}


void _search_get_200_response_free(_search_get_200_response_t *_search_get_200_response) {
    if(NULL == _search_get_200_response){
        return ;
    }
    listEntry_t *listEntry;
    if (_search_get_200_response->version) {
        free(_search_get_200_response->version);
        _search_get_200_response->version = NULL;
    }
    if (_search_get_200_response->query) {
        free(_search_get_200_response->query);
        _search_get_200_response->query = NULL;
    }
    if (_search_get_200_response->hits) {
        search_results_hits_free(_search_get_200_response->hits);
        _search_get_200_response->hits = NULL;
    }
    free(_search_get_200_response);
}

cJSON *_search_get_200_response_convertToJSON(_search_get_200_response_t *_search_get_200_response) {
    cJSON *item = cJSON_CreateObject();

    // _search_get_200_response->api_version
    if(_search_get_200_response->api_version) {
    if(cJSON_AddNumberToObject(item, "apiVersion", _search_get_200_response->api_version) == NULL) {
    goto fail; //Numeric
    }
    }


    // _search_get_200_response->version
    if(_search_get_200_response->version) {
    if(cJSON_AddStringToObject(item, "version", _search_get_200_response->version) == NULL) {
    goto fail; //String
    }
    }


    // _search_get_200_response->query
    if(_search_get_200_response->query) {
    if(cJSON_AddStringToObject(item, "query", _search_get_200_response->query) == NULL) {
    goto fail; //String
    }
    }


    // _search_get_200_response->took
    if(_search_get_200_response->took) {
    if(cJSON_AddNumberToObject(item, "took", _search_get_200_response->took) == NULL) {
    goto fail; //Numeric
    }
    }


    // _search_get_200_response->hits
    if(_search_get_200_response->hits) {
    cJSON *hits_local_JSON = search_results_hits_convertToJSON(_search_get_200_response->hits);
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

_search_get_200_response_t *_search_get_200_response_parseFromJSON(cJSON *_search_get_200_responseJSON){

    _search_get_200_response_t *_search_get_200_response_local_var = NULL;

    // define the local variable for _search_get_200_response->hits
    search_results_hits_t *hits_local_nonprim = NULL;

    // _search_get_200_response->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(_search_get_200_responseJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsNumber(api_version))
    {
    goto end; //Numeric
    }
    }

    // _search_get_200_response->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(_search_get_200_responseJSON, "version");
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }

    // _search_get_200_response->query
    cJSON *query = cJSON_GetObjectItemCaseSensitive(_search_get_200_responseJSON, "query");
    if (query) { 
    if(!cJSON_IsString(query) && !cJSON_IsNull(query))
    {
    goto end; //String
    }
    }

    // _search_get_200_response->took
    cJSON *took = cJSON_GetObjectItemCaseSensitive(_search_get_200_responseJSON, "took");
    if (took) { 
    if(!cJSON_IsNumber(took))
    {
    goto end; //Numeric
    }
    }

    // _search_get_200_response->hits
    cJSON *hits = cJSON_GetObjectItemCaseSensitive(_search_get_200_responseJSON, "hits");
    if (hits) { 
    hits_local_nonprim = search_results_hits_parseFromJSON(hits); //nonprimitive
    }


    _search_get_200_response_local_var = _search_get_200_response_create (
        api_version ? api_version->valuedouble : 0,
        version && !cJSON_IsNull(version) ? strdup(version->valuestring) : NULL,
        query && !cJSON_IsNull(query) ? strdup(query->valuestring) : NULL,
        took ? took->valuedouble : 0,
        hits ? hits_local_nonprim : NULL
        );

    return _search_get_200_response_local_var;
end:
    if (hits_local_nonprim) {
        search_results_hits_free(hits_local_nonprim);
        hits_local_nonprim = NULL;
    }
    return NULL;

}
