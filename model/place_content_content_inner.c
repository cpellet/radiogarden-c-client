#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "place_content_content_inner.h"



place_content_content_inner_t *place_content_content_inner_create(
    char *title,
    char *type,
    char *items_type,
    list_t *items,
    place_ref_t *action_page,
    char *action_text,
    char *right_accessory
    ) {
    place_content_content_inner_t *place_content_content_inner_local_var = malloc(sizeof(place_content_content_inner_t));
    if (!place_content_content_inner_local_var) {
        return NULL;
    }
    place_content_content_inner_local_var->title = title;
    place_content_content_inner_local_var->type = type;
    place_content_content_inner_local_var->items_type = items_type;
    place_content_content_inner_local_var->items = items;
    place_content_content_inner_local_var->action_page = action_page;
    place_content_content_inner_local_var->action_text = action_text;
    place_content_content_inner_local_var->right_accessory = right_accessory;

    return place_content_content_inner_local_var;
}


void place_content_content_inner_free(place_content_content_inner_t *place_content_content_inner) {
    if(NULL == place_content_content_inner){
        return ;
    }
    listEntry_t *listEntry;
    if (place_content_content_inner->title) {
        free(place_content_content_inner->title);
        place_content_content_inner->title = NULL;
    }
    if (place_content_content_inner->type) {
        free(place_content_content_inner->type);
        place_content_content_inner->type = NULL;
    }
    if (place_content_content_inner->items_type) {
        free(place_content_content_inner->items_type);
        place_content_content_inner->items_type = NULL;
    }
    if (place_content_content_inner->items) {
        list_ForEach(listEntry, place_content_content_inner->items) {
            left_page_ref_free(listEntry->data);
        }
        list_freeList(place_content_content_inner->items);
        place_content_content_inner->items = NULL;
    }
    if (place_content_content_inner->action_page) {
        place_ref_free(place_content_content_inner->action_page);
        place_content_content_inner->action_page = NULL;
    }
    if (place_content_content_inner->action_text) {
        free(place_content_content_inner->action_text);
        place_content_content_inner->action_text = NULL;
    }
    if (place_content_content_inner->right_accessory) {
        free(place_content_content_inner->right_accessory);
        place_content_content_inner->right_accessory = NULL;
    }
    free(place_content_content_inner);
}

cJSON *place_content_content_inner_convertToJSON(place_content_content_inner_t *place_content_content_inner) {
    cJSON *item = cJSON_CreateObject();

    // place_content_content_inner->title
    if(place_content_content_inner->title) {
    if(cJSON_AddStringToObject(item, "title", place_content_content_inner->title) == NULL) {
    goto fail; //String
    }
    }


    // place_content_content_inner->type
    if(place_content_content_inner->type) {
    if(cJSON_AddStringToObject(item, "type", place_content_content_inner->type) == NULL) {
    goto fail; //String
    }
    }


    // place_content_content_inner->items_type
    if(place_content_content_inner->items_type) {
    if(cJSON_AddStringToObject(item, "itemsType", place_content_content_inner->items_type) == NULL) {
    goto fail; //String
    }
    }


    // place_content_content_inner->items
    if(place_content_content_inner->items) {
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (place_content_content_inner->items) {
    list_ForEach(itemsListEntry, place_content_content_inner->items) {
    cJSON *itemLocal = left_page_ref_convertToJSON(itemsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(items, itemLocal);
    }
    }
    }


    // place_content_content_inner->action_page
    if(place_content_content_inner->action_page) {
    cJSON *action_page_local_JSON = place_ref_convertToJSON(place_content_content_inner->action_page);
    if(action_page_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "actionPage", action_page_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // place_content_content_inner->action_text
    if(place_content_content_inner->action_text) {
    if(cJSON_AddStringToObject(item, "actionText", place_content_content_inner->action_text) == NULL) {
    goto fail; //String
    }
    }


    // place_content_content_inner->right_accessory
    if(place_content_content_inner->right_accessory) {
    if(cJSON_AddStringToObject(item, "rightAccessory", place_content_content_inner->right_accessory) == NULL) {
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

place_content_content_inner_t *place_content_content_inner_parseFromJSON(cJSON *place_content_content_innerJSON){

    place_content_content_inner_t *place_content_content_inner_local_var = NULL;

    // define the local list for place_content_content_inner->items
    list_t *itemsList = NULL;

    // define the local variable for place_content_content_inner->action_page
    place_ref_t *action_page_local_nonprim = NULL;

    // place_content_content_inner->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(place_content_content_innerJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // place_content_content_inner->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(place_content_content_innerJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // place_content_content_inner->items_type
    cJSON *items_type = cJSON_GetObjectItemCaseSensitive(place_content_content_innerJSON, "itemsType");
    if (items_type) { 
    if(!cJSON_IsString(items_type) && !cJSON_IsNull(items_type))
    {
    goto end; //String
    }
    }

    // place_content_content_inner->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(place_content_content_innerJSON, "items");
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
        left_page_ref_t *itemsItem = left_page_ref_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }
    }

    // place_content_content_inner->action_page
    cJSON *action_page = cJSON_GetObjectItemCaseSensitive(place_content_content_innerJSON, "actionPage");
    if (action_page) { 
    action_page_local_nonprim = place_ref_parseFromJSON(action_page); //nonprimitive
    }

    // place_content_content_inner->action_text
    cJSON *action_text = cJSON_GetObjectItemCaseSensitive(place_content_content_innerJSON, "actionText");
    if (action_text) { 
    if(!cJSON_IsString(action_text) && !cJSON_IsNull(action_text))
    {
    goto end; //String
    }
    }

    // place_content_content_inner->right_accessory
    cJSON *right_accessory = cJSON_GetObjectItemCaseSensitive(place_content_content_innerJSON, "rightAccessory");
    if (right_accessory) { 
    if(!cJSON_IsString(right_accessory) && !cJSON_IsNull(right_accessory))
    {
    goto end; //String
    }
    }


    place_content_content_inner_local_var = place_content_content_inner_create (
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        items_type && !cJSON_IsNull(items_type) ? strdup(items_type->valuestring) : NULL,
        items ? itemsList : NULL,
        action_page ? action_page_local_nonprim : NULL,
        action_text && !cJSON_IsNull(action_text) ? strdup(action_text->valuestring) : NULL,
        right_accessory && !cJSON_IsNull(right_accessory) ? strdup(right_accessory->valuestring) : NULL
        );

    return place_content_content_inner_local_var;
end:
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            left_page_ref_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    if (action_page_local_nonprim) {
        place_ref_free(action_page_local_nonprim);
        action_page_local_nonprim = NULL;
    }
    return NULL;

}
