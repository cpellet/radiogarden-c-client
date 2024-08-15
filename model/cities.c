#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cities.h"



cities_t *cities_create(
    char *title,
    char *type,
    char *right_accessory,
    list_t *items
    ) {
    cities_t *cities_local_var = malloc(sizeof(cities_t));
    if (!cities_local_var) {
        return NULL;
    }
    cities_local_var->title = title;
    cities_local_var->type = type;
    cities_local_var->right_accessory = right_accessory;
    cities_local_var->items = items;

    return cities_local_var;
}


void cities_free(cities_t *cities) {
    if(NULL == cities){
        return ;
    }
    listEntry_t *listEntry;
    if (cities->title) {
        free(cities->title);
        cities->title = NULL;
    }
    if (cities->type) {
        free(cities->type);
        cities->type = NULL;
    }
    if (cities->right_accessory) {
        free(cities->right_accessory);
        cities->right_accessory = NULL;
    }
    if (cities->items) {
        list_ForEach(listEntry, cities->items) {
            left_page_ref_free(listEntry->data);
        }
        list_freeList(cities->items);
        cities->items = NULL;
    }
    free(cities);
}

cJSON *cities_convertToJSON(cities_t *cities) {
    cJSON *item = cJSON_CreateObject();

    // cities->title
    if(cities->title) {
    if(cJSON_AddStringToObject(item, "title", cities->title) == NULL) {
    goto fail; //String
    }
    }


    // cities->type
    if(cities->type) {
    if(cJSON_AddStringToObject(item, "type", cities->type) == NULL) {
    goto fail; //String
    }
    }


    // cities->right_accessory
    if(cities->right_accessory) {
    if(cJSON_AddStringToObject(item, "rightAccessory", cities->right_accessory) == NULL) {
    goto fail; //String
    }
    }


    // cities->items
    if(cities->items) {
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (cities->items) {
    list_ForEach(itemsListEntry, cities->items) {
    cJSON *itemLocal = left_page_ref_convertToJSON(itemsListEntry->data);
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

cities_t *cities_parseFromJSON(cJSON *citiesJSON){

    cities_t *cities_local_var = NULL;

    // define the local list for cities->items
    list_t *itemsList = NULL;

    // cities->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(citiesJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // cities->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(citiesJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // cities->right_accessory
    cJSON *right_accessory = cJSON_GetObjectItemCaseSensitive(citiesJSON, "rightAccessory");
    if (right_accessory) { 
    if(!cJSON_IsString(right_accessory) && !cJSON_IsNull(right_accessory))
    {
    goto end; //String
    }
    }

    // cities->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(citiesJSON, "items");
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


    cities_local_var = cities_create (
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        right_accessory && !cJSON_IsNull(right_accessory) ? strdup(right_accessory->valuestring) : NULL,
        items ? itemsList : NULL
        );

    return cities_local_var;
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
    return NULL;

}
