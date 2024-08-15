#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nearby_places.h"



nearby_places_t *nearby_places_create(
    char *title,
    char *type,
    char *right_accessory,
    list_t *items
    ) {
    nearby_places_t *nearby_places_local_var = malloc(sizeof(nearby_places_t));
    if (!nearby_places_local_var) {
        return NULL;
    }
    nearby_places_local_var->title = title;
    nearby_places_local_var->type = type;
    nearby_places_local_var->right_accessory = right_accessory;
    nearby_places_local_var->items = items;

    return nearby_places_local_var;
}


void nearby_places_free(nearby_places_t *nearby_places) {
    if(NULL == nearby_places){
        return ;
    }
    listEntry_t *listEntry;
    if (nearby_places->title) {
        free(nearby_places->title);
        nearby_places->title = NULL;
    }
    if (nearby_places->type) {
        free(nearby_places->type);
        nearby_places->type = NULL;
    }
    if (nearby_places->right_accessory) {
        free(nearby_places->right_accessory);
        nearby_places->right_accessory = NULL;
    }
    if (nearby_places->items) {
        list_ForEach(listEntry, nearby_places->items) {
            right_page_ref_free(listEntry->data);
        }
        list_freeList(nearby_places->items);
        nearby_places->items = NULL;
    }
    free(nearby_places);
}

cJSON *nearby_places_convertToJSON(nearby_places_t *nearby_places) {
    cJSON *item = cJSON_CreateObject();

    // nearby_places->title
    if(nearby_places->title) {
    if(cJSON_AddStringToObject(item, "title", nearby_places->title) == NULL) {
    goto fail; //String
    }
    }


    // nearby_places->type
    if(nearby_places->type) {
    if(cJSON_AddStringToObject(item, "type", nearby_places->type) == NULL) {
    goto fail; //String
    }
    }


    // nearby_places->right_accessory
    if(nearby_places->right_accessory) {
    if(cJSON_AddStringToObject(item, "rightAccessory", nearby_places->right_accessory) == NULL) {
    goto fail; //String
    }
    }


    // nearby_places->items
    if(nearby_places->items) {
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (nearby_places->items) {
    list_ForEach(itemsListEntry, nearby_places->items) {
    cJSON *itemLocal = right_page_ref_convertToJSON(itemsListEntry->data);
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

nearby_places_t *nearby_places_parseFromJSON(cJSON *nearby_placesJSON){

    nearby_places_t *nearby_places_local_var = NULL;

    // define the local list for nearby_places->items
    list_t *itemsList = NULL;

    // nearby_places->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(nearby_placesJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // nearby_places->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(nearby_placesJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // nearby_places->right_accessory
    cJSON *right_accessory = cJSON_GetObjectItemCaseSensitive(nearby_placesJSON, "rightAccessory");
    if (right_accessory) { 
    if(!cJSON_IsString(right_accessory) && !cJSON_IsNull(right_accessory))
    {
    goto end; //String
    }
    }

    // nearby_places->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(nearby_placesJSON, "items");
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
        right_page_ref_t *itemsItem = right_page_ref_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }
    }


    nearby_places_local_var = nearby_places_create (
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        right_accessory && !cJSON_IsNull(right_accessory) ? strdup(right_accessory->valuestring) : NULL,
        items ? itemsList : NULL
        );

    return nearby_places_local_var;
end:
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            right_page_ref_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    return NULL;

}
