#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "country_popular_stations.h"



country_popular_stations_t *country_popular_stations_create(
    char *title,
    char *type,
    char *items_type,
    list_t *items
    ) {
    country_popular_stations_t *country_popular_stations_local_var = malloc(sizeof(country_popular_stations_t));
    if (!country_popular_stations_local_var) {
        return NULL;
    }
    country_popular_stations_local_var->title = title;
    country_popular_stations_local_var->type = type;
    country_popular_stations_local_var->items_type = items_type;
    country_popular_stations_local_var->items = items;

    return country_popular_stations_local_var;
}


void country_popular_stations_free(country_popular_stations_t *country_popular_stations) {
    if(NULL == country_popular_stations){
        return ;
    }
    listEntry_t *listEntry;
    if (country_popular_stations->title) {
        free(country_popular_stations->title);
        country_popular_stations->title = NULL;
    }
    if (country_popular_stations->type) {
        free(country_popular_stations->type);
        country_popular_stations->type = NULL;
    }
    if (country_popular_stations->items_type) {
        free(country_popular_stations->items_type);
        country_popular_stations->items_type = NULL;
    }
    if (country_popular_stations->items) {
        list_ForEach(listEntry, country_popular_stations->items) {
            country_popular_stations_items_inner_free(listEntry->data);
        }
        list_freeList(country_popular_stations->items);
        country_popular_stations->items = NULL;
    }
    free(country_popular_stations);
}

cJSON *country_popular_stations_convertToJSON(country_popular_stations_t *country_popular_stations) {
    cJSON *item = cJSON_CreateObject();

    // country_popular_stations->title
    if(country_popular_stations->title) {
    if(cJSON_AddStringToObject(item, "title", country_popular_stations->title) == NULL) {
    goto fail; //String
    }
    }


    // country_popular_stations->type
    if(country_popular_stations->type) {
    if(cJSON_AddStringToObject(item, "type", country_popular_stations->type) == NULL) {
    goto fail; //String
    }
    }


    // country_popular_stations->items_type
    if(country_popular_stations->items_type) {
    if(cJSON_AddStringToObject(item, "itemsType", country_popular_stations->items_type) == NULL) {
    goto fail; //String
    }
    }


    // country_popular_stations->items
    if(country_popular_stations->items) {
    cJSON *items = cJSON_AddArrayToObject(item, "items");
    if(items == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *itemsListEntry;
    if (country_popular_stations->items) {
    list_ForEach(itemsListEntry, country_popular_stations->items) {
    cJSON *itemLocal = country_popular_stations_items_inner_convertToJSON(itemsListEntry->data);
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

country_popular_stations_t *country_popular_stations_parseFromJSON(cJSON *country_popular_stationsJSON){

    country_popular_stations_t *country_popular_stations_local_var = NULL;

    // define the local list for country_popular_stations->items
    list_t *itemsList = NULL;

    // country_popular_stations->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(country_popular_stationsJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // country_popular_stations->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(country_popular_stationsJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // country_popular_stations->items_type
    cJSON *items_type = cJSON_GetObjectItemCaseSensitive(country_popular_stationsJSON, "itemsType");
    if (items_type) { 
    if(!cJSON_IsString(items_type) && !cJSON_IsNull(items_type))
    {
    goto end; //String
    }
    }

    // country_popular_stations->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(country_popular_stationsJSON, "items");
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
        country_popular_stations_items_inner_t *itemsItem = country_popular_stations_items_inner_parseFromJSON(items_local_nonprimitive);

        list_addElement(itemsList, itemsItem);
    }
    }


    country_popular_stations_local_var = country_popular_stations_create (
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        items_type && !cJSON_IsNull(items_type) ? strdup(items_type->valuestring) : NULL,
        items ? itemsList : NULL
        );

    return country_popular_stations_local_var;
end:
    if (itemsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, itemsList) {
            country_popular_stations_items_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(itemsList);
        itemsList = NULL;
    }
    return NULL;

}
