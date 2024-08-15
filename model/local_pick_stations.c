#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "local_pick_stations.h"



local_pick_stations_t *local_pick_stations_create(
    char *title,
    char *type,
    char *items_type,
    list_t *items
    ) {
    local_pick_stations_t *local_pick_stations_local_var = malloc(sizeof(local_pick_stations_t));
    if (!local_pick_stations_local_var) {
        return NULL;
    }
    local_pick_stations_local_var->title = title;
    local_pick_stations_local_var->type = type;
    local_pick_stations_local_var->items_type = items_type;
    local_pick_stations_local_var->items = items;

    return local_pick_stations_local_var;
}


void local_pick_stations_free(local_pick_stations_t *local_pick_stations) {
    if(NULL == local_pick_stations){
        return ;
    }
    listEntry_t *listEntry;
    if (local_pick_stations->title) {
        free(local_pick_stations->title);
        local_pick_stations->title = NULL;
    }
    if (local_pick_stations->type) {
        free(local_pick_stations->type);
        local_pick_stations->type = NULL;
    }
    if (local_pick_stations->items_type) {
        free(local_pick_stations->items_type);
        local_pick_stations->items_type = NULL;
    }
    if (local_pick_stations->items) {
        list_ForEach(listEntry, local_pick_stations->items) {
            channel_place_ref_free(listEntry->data);
        }
        list_freeList(local_pick_stations->items);
        local_pick_stations->items = NULL;
    }
    free(local_pick_stations);
}

cJSON *local_pick_stations_convertToJSON(local_pick_stations_t *local_pick_stations) {
    cJSON *item = cJSON_CreateObject();

    // local_pick_stations->title
    if(local_pick_stations->title) {
    if(cJSON_AddStringToObject(item, "title", local_pick_stations->title) == NULL) {
    goto fail; //String
    }
    }


    // local_pick_stations->type
    if(local_pick_stations->type) {
    if(cJSON_AddStringToObject(item, "type", local_pick_stations->type) == NULL) {
    goto fail; //String
    }
    }


    // local_pick_stations->items_type
    if(local_pick_stations->items_type) {
    if(cJSON_AddStringToObject(item, "itemsType", local_pick_stations->items_type) == NULL) {
    goto fail; //String
    }
    }


    // local_pick_stations->items
    if(local_pick_stations->items) {
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (local_pick_stations->items) {
    list_ForEach(itemsListEntry, local_pick_stations->items) {
    cJSON *itemLocal = channel_place_ref_convertToJSON(itemsListEntry->data);
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

local_pick_stations_t *local_pick_stations_parseFromJSON(cJSON *local_pick_stationsJSON){

    local_pick_stations_t *local_pick_stations_local_var = NULL;

    // define the local list for local_pick_stations->items
    list_t *itemsList = NULL;

    // local_pick_stations->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(local_pick_stationsJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // local_pick_stations->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(local_pick_stationsJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // local_pick_stations->items_type
    cJSON *items_type = cJSON_GetObjectItemCaseSensitive(local_pick_stationsJSON, "itemsType");
    if (items_type) { 
    if(!cJSON_IsString(items_type) && !cJSON_IsNull(items_type))
    {
    goto end; //String
    }
    }

    // local_pick_stations->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(local_pick_stationsJSON, "items");
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
        channel_place_ref_t *itemsItem = channel_place_ref_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }
    }


    local_pick_stations_local_var = local_pick_stations_create (
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        items_type && !cJSON_IsNull(items_type) ? strdup(items_type->valuestring) : NULL,
        items ? itemsList : NULL
        );

    return local_pick_stations_local_var;
end:
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            channel_place_ref_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    return NULL;

}
