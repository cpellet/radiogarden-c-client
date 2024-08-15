#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "search_result.h"



search_result_t *search_result_create(
    char *_id,
    float _score,
    search_result__source_t *_source
    ) {
    search_result_t *search_result_local_var = malloc(sizeof(search_result_t));
    if (!search_result_local_var) {
        return NULL;
    }
    search_result_local_var->_id = _id;
    search_result_local_var->_score = _score;
    search_result_local_var->_source = _source;

    return search_result_local_var;
}


void search_result_free(search_result_t *search_result) {
    if(NULL == search_result){
        return ;
    }
    listEntry_t *listEntry;
    if (search_result->_id) {
        free(search_result->_id);
        search_result->_id = NULL;
    }
    if (search_result->_source) {
        search_result__source_free(search_result->_source);
        search_result->_source = NULL;
    }
    free(search_result);
}

cJSON *search_result_convertToJSON(search_result_t *search_result) {
    cJSON *item = cJSON_CreateObject();

    // search_result->_id
    if(search_result->_id) {
    if(cJSON_AddStringToObject(item, "_id", search_result->_id) == NULL) {
    goto fail; //String
    }
    }


    // search_result->_score
    if(search_result->_score) {
    if(cJSON_AddNumberToObject(item, "_score", search_result->_score) == NULL) {
    goto fail; //Numeric
    }
    }


    // search_result->_source
    if(search_result->_source) {
    cJSON *_source_local_JSON = search_result__source_convertToJSON(search_result->_source);
    if(_source_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "_source", _source_local_JSON);
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

search_result_t *search_result_parseFromJSON(cJSON *search_resultJSON){

    search_result_t *search_result_local_var = NULL;

    // define the local variable for search_result->_source
    search_result__source_t *_source_local_nonprim = NULL;

    // search_result->_id
    cJSON *_id = cJSON_GetObjectItemCaseSensitive(search_resultJSON, "_id");
    if (_id) { 
    if(!cJSON_IsString(_id) && !cJSON_IsNull(_id))
    {
    goto end; //String
    }
    }

    // search_result->_score
    cJSON *_score = cJSON_GetObjectItemCaseSensitive(search_resultJSON, "_score");
    if (_score) { 
    if(!cJSON_IsNumber(_score))
    {
    goto end; //Numeric
    }
    }

    // search_result->_source
    cJSON *_source = cJSON_GetObjectItemCaseSensitive(search_resultJSON, "_source");
    if (_source) { 
    _source_local_nonprim = search_result__source_parseFromJSON(_source); //nonprimitive
    }


    search_result_local_var = search_result_create (
        _id && !cJSON_IsNull(_id) ? strdup(_id->valuestring) : NULL,
        _score ? _score->valuedouble : 0,
        _source ? _source_local_nonprim : NULL
        );

    return search_result_local_var;
end:
    if (_source_local_nonprim) {
        search_result__source_free(_source_local_nonprim);
        _source_local_nonprim = NULL;
    }
    return NULL;

}
