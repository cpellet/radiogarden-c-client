#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_ara_content_page__place_id__get_200_response_all_of_data.h"



_ara_content_page__place_id__get_200_response_all_of_data_t *_ara_content_page__place_id__get_200_response_all_of_data_create(
    char *title,
    char *subtitle,
    char *url,
    char *map,
    int count,
    int utc_offset,
    list_t *content
    ) {
    _ara_content_page__place_id__get_200_response_all_of_data_t *_ara_content_page__place_id__get_200_response_all_of_data_local_var = malloc(sizeof(_ara_content_page__place_id__get_200_response_all_of_data_t));
    if (!_ara_content_page__place_id__get_200_response_all_of_data_local_var) {
        return NULL;
    }
    _ara_content_page__place_id__get_200_response_all_of_data_local_var->title = title;
    _ara_content_page__place_id__get_200_response_all_of_data_local_var->subtitle = subtitle;
    _ara_content_page__place_id__get_200_response_all_of_data_local_var->url = url;
    _ara_content_page__place_id__get_200_response_all_of_data_local_var->map = map;
    _ara_content_page__place_id__get_200_response_all_of_data_local_var->count = count;
    _ara_content_page__place_id__get_200_response_all_of_data_local_var->utc_offset = utc_offset;
    _ara_content_page__place_id__get_200_response_all_of_data_local_var->content = content;

    return _ara_content_page__place_id__get_200_response_all_of_data_local_var;
}


void _ara_content_page__place_id__get_200_response_all_of_data_free(_ara_content_page__place_id__get_200_response_all_of_data_t *_ara_content_page__place_id__get_200_response_all_of_data) {
    if(NULL == _ara_content_page__place_id__get_200_response_all_of_data){
        return ;
    }
    listEntry_t *listEntry;
    if (_ara_content_page__place_id__get_200_response_all_of_data->title) {
        free(_ara_content_page__place_id__get_200_response_all_of_data->title);
        _ara_content_page__place_id__get_200_response_all_of_data->title = NULL;
    }
    if (_ara_content_page__place_id__get_200_response_all_of_data->subtitle) {
        free(_ara_content_page__place_id__get_200_response_all_of_data->subtitle);
        _ara_content_page__place_id__get_200_response_all_of_data->subtitle = NULL;
    }
    if (_ara_content_page__place_id__get_200_response_all_of_data->url) {
        free(_ara_content_page__place_id__get_200_response_all_of_data->url);
        _ara_content_page__place_id__get_200_response_all_of_data->url = NULL;
    }
    if (_ara_content_page__place_id__get_200_response_all_of_data->map) {
        free(_ara_content_page__place_id__get_200_response_all_of_data->map);
        _ara_content_page__place_id__get_200_response_all_of_data->map = NULL;
    }
    if (_ara_content_page__place_id__get_200_response_all_of_data->content) {
        list_ForEach(listEntry, _ara_content_page__place_id__get_200_response_all_of_data->content) {
            place_content_content_inner_free(listEntry->data);
        }
        list_freeList(_ara_content_page__place_id__get_200_response_all_of_data->content);
        _ara_content_page__place_id__get_200_response_all_of_data->content = NULL;
    }
    free(_ara_content_page__place_id__get_200_response_all_of_data);
}

cJSON *_ara_content_page__place_id__get_200_response_all_of_data_convertToJSON(_ara_content_page__place_id__get_200_response_all_of_data_t *_ara_content_page__place_id__get_200_response_all_of_data) {
    cJSON *item = cJSON_CreateObject();

    // _ara_content_page__place_id__get_200_response_all_of_data->title
    if(_ara_content_page__place_id__get_200_response_all_of_data->title) {
    if(cJSON_AddStringToObject(item, "title", _ara_content_page__place_id__get_200_response_all_of_data->title) == NULL) {
    goto fail; //String
    }
    }


    // _ara_content_page__place_id__get_200_response_all_of_data->subtitle
    if(_ara_content_page__place_id__get_200_response_all_of_data->subtitle) {
    if(cJSON_AddStringToObject(item, "subtitle", _ara_content_page__place_id__get_200_response_all_of_data->subtitle) == NULL) {
    goto fail; //String
    }
    }


    // _ara_content_page__place_id__get_200_response_all_of_data->url
    if(_ara_content_page__place_id__get_200_response_all_of_data->url) {
    if(cJSON_AddStringToObject(item, "url", _ara_content_page__place_id__get_200_response_all_of_data->url) == NULL) {
    goto fail; //String
    }
    }


    // _ara_content_page__place_id__get_200_response_all_of_data->map
    if(_ara_content_page__place_id__get_200_response_all_of_data->map) {
    if(cJSON_AddStringToObject(item, "map", _ara_content_page__place_id__get_200_response_all_of_data->map) == NULL) {
    goto fail; //String
    }
    }


    // _ara_content_page__place_id__get_200_response_all_of_data->count
    if(_ara_content_page__place_id__get_200_response_all_of_data->count) {
    if(cJSON_AddNumberToObject(item, "count", _ara_content_page__place_id__get_200_response_all_of_data->count) == NULL) {
    goto fail; //Numeric
    }
    }


    // _ara_content_page__place_id__get_200_response_all_of_data->utc_offset
    if(_ara_content_page__place_id__get_200_response_all_of_data->utc_offset) {
    if(cJSON_AddNumberToObject(item, "utcOffset", _ara_content_page__place_id__get_200_response_all_of_data->utc_offset) == NULL) {
    goto fail; //Numeric
    }
    }


    // _ara_content_page__place_id__get_200_response_all_of_data->content
    if(_ara_content_page__place_id__get_200_response_all_of_data->content) {
    cJSON *content = cJSON_AddArrayToObject(item, "content");
    if(content == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *contentListEntry;
    if (_ara_content_page__place_id__get_200_response_all_of_data->content) {
    list_ForEach(contentListEntry, _ara_content_page__place_id__get_200_response_all_of_data->content) {
    cJSON *itemLocal = place_content_content_inner_convertToJSON(contentListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(content, itemLocal);
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

_ara_content_page__place_id__get_200_response_all_of_data_t *_ara_content_page__place_id__get_200_response_all_of_data_parseFromJSON(cJSON *_ara_content_page__place_id__get_200_response_all_of_dataJSON){

    _ara_content_page__place_id__get_200_response_all_of_data_t *_ara_content_page__place_id__get_200_response_all_of_data_local_var = NULL;

    // define the local list for _ara_content_page__place_id__get_200_response_all_of_data->content
    list_t *contentList = NULL;

    // _ara_content_page__place_id__get_200_response_all_of_data->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(_ara_content_page__place_id__get_200_response_all_of_dataJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // _ara_content_page__place_id__get_200_response_all_of_data->subtitle
    cJSON *subtitle = cJSON_GetObjectItemCaseSensitive(_ara_content_page__place_id__get_200_response_all_of_dataJSON, "subtitle");
    if (subtitle) { 
    if(!cJSON_IsString(subtitle) && !cJSON_IsNull(subtitle))
    {
    goto end; //String
    }
    }

    // _ara_content_page__place_id__get_200_response_all_of_data->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(_ara_content_page__place_id__get_200_response_all_of_dataJSON, "url");
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }

    // _ara_content_page__place_id__get_200_response_all_of_data->map
    cJSON *map = cJSON_GetObjectItemCaseSensitive(_ara_content_page__place_id__get_200_response_all_of_dataJSON, "map");
    if (map) { 
    if(!cJSON_IsString(map) && !cJSON_IsNull(map))
    {
    goto end; //String
    }
    }

    // _ara_content_page__place_id__get_200_response_all_of_data->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(_ara_content_page__place_id__get_200_response_all_of_dataJSON, "count");
    if (count) { 
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }
    }

    // _ara_content_page__place_id__get_200_response_all_of_data->utc_offset
    cJSON *utc_offset = cJSON_GetObjectItemCaseSensitive(_ara_content_page__place_id__get_200_response_all_of_dataJSON, "utcOffset");
    if (utc_offset) { 
    if(!cJSON_IsNumber(utc_offset))
    {
    goto end; //Numeric
    }
    }

    // _ara_content_page__place_id__get_200_response_all_of_data->content
    cJSON *content = cJSON_GetObjectItemCaseSensitive(_ara_content_page__place_id__get_200_response_all_of_dataJSON, "content");
    if (content) { 
    cJSON *content_local_nonprimitive = NULL;
    if(!cJSON_IsArray(content)){
        goto end; //nonprimitive container
    }

    contentList = list_createList();

    cJSON_ArrayForEach(content_local_nonprimitive,content )
    {
        if(!cJSON_IsObject(content_local_nonprimitive)){
            goto end;
        }
        place_content_content_inner_t *contentItem = place_content_content_inner_parseFromJSON(content_local_nonprimitive);

        list_addElement(contentList, contentItem);
    }
    }


    _ara_content_page__place_id__get_200_response_all_of_data_local_var = _ara_content_page__place_id__get_200_response_all_of_data_create (
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        subtitle && !cJSON_IsNull(subtitle) ? strdup(subtitle->valuestring) : NULL,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL,
        map && !cJSON_IsNull(map) ? strdup(map->valuestring) : NULL,
        count ? count->valuedouble : 0,
        utc_offset ? utc_offset->valuedouble : 0,
        content ? contentList : NULL
        );

    return _ara_content_page__place_id__get_200_response_all_of_data_local_var;
end:
    if (contentList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, contentList) {
            place_content_content_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(contentList);
        contentList = NULL;
    }
    return NULL;

}
