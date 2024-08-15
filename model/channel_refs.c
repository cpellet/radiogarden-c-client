#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "channel_refs.h"



channel_refs_t *channel_refs_create(
    char *items_type,
    char *type,
    list_t *items
    ) {
    channel_refs_t *channel_refs_local_var = malloc(sizeof(channel_refs_t));
    if (!channel_refs_local_var) {
        return NULL;
    }
    channel_refs_local_var->items_type = items_type;
    channel_refs_local_var->type = type;
    channel_refs_local_var->items = items;

    return channel_refs_local_var;
}


void channel_refs_free(channel_refs_t *channel_refs) {
    if(NULL == channel_refs){
        return ;
    }
    listEntry_t *listEntry;
    if (channel_refs->items_type) {
        free(channel_refs->items_type);
        channel_refs->items_type = NULL;
    }
    if (channel_refs->type) {
        free(channel_refs->type);
        channel_refs->type = NULL;
    }
    if (channel_refs->items) {
        list_ForEach(listEntry, channel_refs->items) {
            channel_ref_free(listEntry->data);
        }
        list_freeList(channel_refs->items);
        channel_refs->items = NULL;
    }
    free(channel_refs);
}

cJSON *channel_refs_convertToJSON(channel_refs_t *channel_refs) {
    cJSON *item = cJSON_CreateObject();

    // channel_refs->items_type
    if(channel_refs->items_type) {
    if(cJSON_AddStringToObject(item, "itemsType", channel_refs->items_type) == NULL) {
    goto fail; //String
    }
    }


    // channel_refs->type
    if(channel_refs->type) {
    if(cJSON_AddStringToObject(item, "type", channel_refs->type) == NULL) {
    goto fail; //String
    }
    }


    // channel_refs->items
    if(channel_refs->items) {
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (channel_refs->items) {
    list_ForEach(itemsListEntry, channel_refs->items) {
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

channel_refs_t *channel_refs_parseFromJSON(cJSON *channel_refsJSON){

    channel_refs_t *channel_refs_local_var = NULL;

    // define the local list for channel_refs->items
    list_t *itemsList = NULL;

    // channel_refs->items_type
    cJSON *items_type = cJSON_GetObjectItemCaseSensitive(channel_refsJSON, "itemsType");
    if (items_type) { 
    if(!cJSON_IsString(items_type) && !cJSON_IsNull(items_type))
    {
    goto end; //String
    }
    }

    // channel_refs->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(channel_refsJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // channel_refs->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(channel_refsJSON, "items");
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


    channel_refs_local_var = channel_refs_create (
        items_type && !cJSON_IsNull(items_type) ? strdup(items_type->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        items ? itemsList : NULL
        );

    return channel_refs_local_var;
end:
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
