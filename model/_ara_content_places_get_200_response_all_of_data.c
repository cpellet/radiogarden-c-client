#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_ara_content_places_get_200_response_all_of_data.h"



_ara_content_places_get_200_response_all_of_data_t *_ara_content_places_get_200_response_all_of_data_create(
    list_t *list,
    char *version
    ) {
    _ara_content_places_get_200_response_all_of_data_t *_ara_content_places_get_200_response_all_of_data_local_var = malloc(sizeof(_ara_content_places_get_200_response_all_of_data_t));
    if (!_ara_content_places_get_200_response_all_of_data_local_var) {
        return NULL;
    }
    _ara_content_places_get_200_response_all_of_data_local_var->list = list;
    _ara_content_places_get_200_response_all_of_data_local_var->version = version;

    return _ara_content_places_get_200_response_all_of_data_local_var;
}


void _ara_content_places_get_200_response_all_of_data_free(_ara_content_places_get_200_response_all_of_data_t *_ara_content_places_get_200_response_all_of_data) {
    if(NULL == _ara_content_places_get_200_response_all_of_data){
        return ;
    }
    listEntry_t *listEntry;
    if (_ara_content_places_get_200_response_all_of_data->list) {
        list_ForEach(listEntry, _ara_content_places_get_200_response_all_of_data->list) {
            place_free(listEntry->data);
        }
        list_freeList(_ara_content_places_get_200_response_all_of_data->list);
        _ara_content_places_get_200_response_all_of_data->list = NULL;
    }
    if (_ara_content_places_get_200_response_all_of_data->version) {
        free(_ara_content_places_get_200_response_all_of_data->version);
        _ara_content_places_get_200_response_all_of_data->version = NULL;
    }
    free(_ara_content_places_get_200_response_all_of_data);
}

cJSON *_ara_content_places_get_200_response_all_of_data_convertToJSON(_ara_content_places_get_200_response_all_of_data_t *_ara_content_places_get_200_response_all_of_data) {
    cJSON *item = cJSON_CreateObject();

    // _ara_content_places_get_200_response_all_of_data->list
    if(_ara_content_places_get_200_response_all_of_data->list) {
    cJSON *list = cJSON_AddArrayToObject(item, "list");
    if(list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *listListEntry;
    if (_ara_content_places_get_200_response_all_of_data->list) {
    list_ForEach(listListEntry, _ara_content_places_get_200_response_all_of_data->list) {
    cJSON *itemLocal = place_convertToJSON(listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(list, itemLocal);
    }
    }
    }


    // _ara_content_places_get_200_response_all_of_data->version
    if(_ara_content_places_get_200_response_all_of_data->version) {
    if(cJSON_AddStringToObject(item, "version", _ara_content_places_get_200_response_all_of_data->version) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_ara_content_places_get_200_response_all_of_data_t *_ara_content_places_get_200_response_all_of_data_parseFromJSON(cJSON *_ara_content_places_get_200_response_all_of_dataJSON){

    _ara_content_places_get_200_response_all_of_data_t *_ara_content_places_get_200_response_all_of_data_local_var = NULL;

    // define the local list for _ara_content_places_get_200_response_all_of_data->list
    list_t *listList = NULL;

    // _ara_content_places_get_200_response_all_of_data->list
    cJSON *list = cJSON_GetObjectItemCaseSensitive(_ara_content_places_get_200_response_all_of_dataJSON, "list");
    if (list) { 
    cJSON *list_local_nonprimitive = NULL;
    if(!cJSON_IsArray(list)){
        goto end; //nonprimitive container
    }

    listList = list_createList();

    cJSON_ArrayForEach(list_local_nonprimitive,list )
    {
        if(!cJSON_IsObject(list_local_nonprimitive)){
            goto end;
        }
        place_t *listItem = place_parseFromJSON(list_local_nonprimitive);

        list_addElement(listList, listItem);
    }
    }

    // _ara_content_places_get_200_response_all_of_data->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(_ara_content_places_get_200_response_all_of_dataJSON, "version");
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }


    _ara_content_places_get_200_response_all_of_data_local_var = _ara_content_places_get_200_response_all_of_data_create (
        list ? listList : NULL,
        version && !cJSON_IsNull(version) ? strdup(version->valuestring) : NULL
        );

    return _ara_content_places_get_200_response_all_of_data_local_var;
end:
    if (listList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, listList) {
            place_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(listList);
        listList = NULL;
    }
    return NULL;

}
