#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "selected_stations.h"



selected_stations_t *selected_stations_create(
    char *title,
    char *type,
    char *items_type,
    list_t *items
    ) {
    selected_stations_t *selected_stations_local_var = malloc(sizeof(selected_stations_t));
    if (!selected_stations_local_var) {
        return NULL;
    }
    selected_stations_local_var->title = title;
    selected_stations_local_var->type = type;
    selected_stations_local_var->items_type = items_type;
    selected_stations_local_var->items = items;

    return selected_stations_local_var;
}


void selected_stations_free(selected_stations_t *selected_stations) {
    if(NULL == selected_stations){
        return ;
    }
    listEntry_t *listEntry;
    if (selected_stations->title) {
        free(selected_stations->title);
        selected_stations->title = NULL;
    }
    if (selected_stations->type) {
        free(selected_stations->type);
        selected_stations->type = NULL;
    }
    if (selected_stations->items_type) {
        free(selected_stations->items_type);
        selected_stations->items_type = NULL;
    }
    if (selected_stations->items) {
        list_ForEach(listEntry, selected_stations->items) {
            selected_stations_items_inner_free(listEntry->data);
        }
        list_freeList(selected_stations->items);
        selected_stations->items = NULL;
    }
    free(selected_stations);
}

cJSON *selected_stations_convertToJSON(selected_stations_t *selected_stations) {
    cJSON *item = cJSON_CreateObject();

    // selected_stations->title
    if(selected_stations->title) {
    if(cJSON_AddStringToObject(item, "title", selected_stations->title) == NULL) {
    goto fail; //String
    }
    }


    // selected_stations->type
    if(selected_stations->type) {
    if(cJSON_AddStringToObject(item, "type", selected_stations->type) == NULL) {
    goto fail; //String
    }
    }


    // selected_stations->items_type
    if(selected_stations->items_type) {
    if(cJSON_AddStringToObject(item, "itemsType", selected_stations->items_type) == NULL) {
    goto fail; //String
    }
    }


    // selected_stations->items
    if(selected_stations->items) {
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (selected_stations->items) {
    list_ForEach(itemsListEntry, selected_stations->items) {
    cJSON *itemLocal = selected_stations_items_inner_convertToJSON(itemsListEntry->data);
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

selected_stations_t *selected_stations_parseFromJSON(cJSON *selected_stationsJSON){

    selected_stations_t *selected_stations_local_var = NULL;

    // define the local list for selected_stations->items
    list_t *itemsList = NULL;

    // selected_stations->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(selected_stationsJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // selected_stations->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(selected_stationsJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // selected_stations->items_type
    cJSON *items_type = cJSON_GetObjectItemCaseSensitive(selected_stationsJSON, "itemsType");
    if (items_type) { 
    if(!cJSON_IsString(items_type) && !cJSON_IsNull(items_type))
    {
    goto end; //String
    }
    }

    // selected_stations->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(selected_stationsJSON, "items");
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
        selected_stations_items_inner_t *itemsItem = selected_stations_items_inner_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }
    }


    selected_stations_local_var = selected_stations_create (
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        items_type && !cJSON_IsNull(items_type) ? strdup(items_type->valuestring) : NULL,
        items ? itemsList : NULL
        );

    return selected_stations_local_var;
end:
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            selected_stations_items_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    return NULL;

}
