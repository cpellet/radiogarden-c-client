#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "local_popular_stations.h"



local_popular_stations_t *local_popular_stations_create(
    place_ref_t *action_page,
    char *action_text,
    char *title,
    char *type,
    char *items_type,
    list_t *items
    ) {
    local_popular_stations_t *local_popular_stations_local_var = malloc(sizeof(local_popular_stations_t));
    if (!local_popular_stations_local_var) {
        return NULL;
    }
    local_popular_stations_local_var->action_page = action_page;
    local_popular_stations_local_var->action_text = action_text;
    local_popular_stations_local_var->title = title;
    local_popular_stations_local_var->type = type;
    local_popular_stations_local_var->items_type = items_type;
    local_popular_stations_local_var->items = items;

    return local_popular_stations_local_var;
}


void local_popular_stations_free(local_popular_stations_t *local_popular_stations) {
    if(NULL == local_popular_stations){
        return ;
    }
    listEntry_t *listEntry;
    if (local_popular_stations->action_page) {
        place_ref_free(local_popular_stations->action_page);
        local_popular_stations->action_page = NULL;
    }
    if (local_popular_stations->action_text) {
        free(local_popular_stations->action_text);
        local_popular_stations->action_text = NULL;
    }
    if (local_popular_stations->title) {
        free(local_popular_stations->title);
        local_popular_stations->title = NULL;
    }
    if (local_popular_stations->type) {
        free(local_popular_stations->type);
        local_popular_stations->type = NULL;
    }
    if (local_popular_stations->items_type) {
        free(local_popular_stations->items_type);
        local_popular_stations->items_type = NULL;
    }
    if (local_popular_stations->items) {
        list_ForEach(listEntry, local_popular_stations->items) {
            channel_ref_free(listEntry->data);
        }
        list_freeList(local_popular_stations->items);
        local_popular_stations->items = NULL;
    }
    free(local_popular_stations);
}

cJSON *local_popular_stations_convertToJSON(local_popular_stations_t *local_popular_stations) {
    cJSON *item = cJSON_CreateObject();

    // local_popular_stations->action_page
    if(local_popular_stations->action_page) {
    cJSON *action_page_local_JSON = place_ref_convertToJSON(local_popular_stations->action_page);
    if(action_page_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "actionPage", action_page_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // local_popular_stations->action_text
    if(local_popular_stations->action_text) {
    if(cJSON_AddStringToObject(item, "actionText", local_popular_stations->action_text) == NULL) {
    goto fail; //String
    }
    }


    // local_popular_stations->title
    if(local_popular_stations->title) {
    if(cJSON_AddStringToObject(item, "title", local_popular_stations->title) == NULL) {
    goto fail; //String
    }
    }


    // local_popular_stations->type
    if(local_popular_stations->type) {
    if(cJSON_AddStringToObject(item, "type", local_popular_stations->type) == NULL) {
    goto fail; //String
    }
    }


    // local_popular_stations->items_type
    if(local_popular_stations->items_type) {
    if(cJSON_AddStringToObject(item, "itemsType", local_popular_stations->items_type) == NULL) {
    goto fail; //String
    }
    }


    // local_popular_stations->items
    if(local_popular_stations->items) {
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (local_popular_stations->items) {
    list_ForEach(itemsListEntry, local_popular_stations->items) {
    cJSON *itemLocal = channel_ref_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
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

local_popular_stations_t *local_popular_stations_parseFromJSON(cJSON *local_popular_stationsJSON){

    local_popular_stations_t *local_popular_stations_local_var = NULL;

    // define the local variable for local_popular_stations->action_page
    place_ref_t *action_page_local_nonprim = NULL;

    // define the local list for local_popular_stations->items
    list_t *itemsList = NULL;

    // local_popular_stations->action_page
    cJSON *action_page = cJSON_GetObjectItemCaseSensitive(local_popular_stationsJSON, "actionPage");
    if (action_page) { 
    action_page_local_nonprim = place_ref_parseFromJSON(action_page); //nonprimitive
    }

    // local_popular_stations->action_text
    cJSON *action_text = cJSON_GetObjectItemCaseSensitive(local_popular_stationsJSON, "actionText");
    if (action_text) { 
    if(!cJSON_IsString(action_text) && !cJSON_IsNull(action_text))
    {
    goto end; //String
    }
    }

    // local_popular_stations->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(local_popular_stationsJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // local_popular_stations->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(local_popular_stationsJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // local_popular_stations->items_type
    cJSON *items_type = cJSON_GetObjectItemCaseSensitive(local_popular_stationsJSON, "itemsType");
    if (items_type) { 
    if(!cJSON_IsString(items_type) && !cJSON_IsNull(items_type))
    {
    goto end; //String
    }
    }

    // local_popular_stations->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(local_popular_stationsJSON, "items");
    if (items) { 
    cJSON *items_local_nonprimitive = NULL;
    if(!cJSON_IsArray(items)){
        goto end; //nonprimitive container
    }

    itemsList = list_createList();

    cJSON_ArrayForEach(items_local_nonprimitive,items )
    {
        if(!cJSON_IsObject(items_local_nonprimitive)){
            goto end;
        }
        channel_ref_t *itemsItem = channel_ref_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }
    }


    local_popular_stations_local_var = local_popular_stations_create (
        action_page ? action_page_local_nonprim : NULL,
        action_text && !cJSON_IsNull(action_text) ? strdup(action_text->valuestring) : NULL,
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        items_type && !cJSON_IsNull(items_type) ? strdup(items_type->valuestring) : NULL,
        items ? itemsList : NULL
        );

    return local_popular_stations_local_var;
end:
    if (action_page_local_nonprim) {
        place_ref_free(action_page_local_nonprim);
        action_page_local_nonprim = NULL;
    }
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            channel_ref_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    return NULL;

}
