#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "place_content.h"



place_content_t *place_content_create(
    list_t *content
    ) {
    place_content_t *place_content_local_var = malloc(sizeof(place_content_t));
    if (!place_content_local_var) {
        return NULL;
    }
    place_content_local_var->content = content;

    return place_content_local_var;
}


void place_content_free(place_content_t *place_content) {
    if(NULL == place_content){
        return ;
    }
    listEntry_t *listEntry;
    if (place_content->content) {
        list_ForEach(listEntry, place_content->content) {
            place_content_content_inner_free(listEntry->data);
        }
        list_freeList(place_content->content);
        place_content->content = NULL;
    }
    free(place_content);
}

cJSON *place_content_convertToJSON(place_content_t *place_content) {
    cJSON *item = cJSON_CreateObject();

    // place_content->content
    if(place_content->content) {
    cJSON *content = cJSON_AddArrayToObject(item, "content");
    if(content == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *contentListEntry;
    if (place_content->content) {
    list_ForEach(contentListEntry, place_content->content) {
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

place_content_t *place_content_parseFromJSON(cJSON *place_contentJSON){

    place_content_t *place_content_local_var = NULL;

    // define the local list for place_content->content
    list_t *contentList = NULL;

    // place_content->content
    cJSON *content = cJSON_GetObjectItemCaseSensitive(place_contentJSON, "content");
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


    place_content_local_var = place_content_create (
        content ? contentList : NULL
        );

    return place_content_local_var;
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
