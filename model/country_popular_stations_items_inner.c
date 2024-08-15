#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "country_popular_stations_items_inner.h"



country_popular_stations_items_inner_t *country_popular_stations_items_inner_create(
    char *title,
    char *href,
    char *subtitle,
    char *map,
    char *type,
    char *right_accessory,
    more_ref_page_t *page
    ) {
    country_popular_stations_items_inner_t *country_popular_stations_items_inner_local_var = malloc(sizeof(country_popular_stations_items_inner_t));
    if (!country_popular_stations_items_inner_local_var) {
        return NULL;
    }
    country_popular_stations_items_inner_local_var->title = title;
    country_popular_stations_items_inner_local_var->href = href;
    country_popular_stations_items_inner_local_var->subtitle = subtitle;
    country_popular_stations_items_inner_local_var->map = map;
    country_popular_stations_items_inner_local_var->type = type;
    country_popular_stations_items_inner_local_var->right_accessory = right_accessory;
    country_popular_stations_items_inner_local_var->page = page;

    return country_popular_stations_items_inner_local_var;
}


void country_popular_stations_items_inner_free(country_popular_stations_items_inner_t *country_popular_stations_items_inner) {
    if(NULL == country_popular_stations_items_inner){
        return ;
    }
    listEntry_t *listEntry;
    if (country_popular_stations_items_inner->title) {
        free(country_popular_stations_items_inner->title);
        country_popular_stations_items_inner->title = NULL;
    }
    if (country_popular_stations_items_inner->href) {
        free(country_popular_stations_items_inner->href);
        country_popular_stations_items_inner->href = NULL;
    }
    if (country_popular_stations_items_inner->subtitle) {
        free(country_popular_stations_items_inner->subtitle);
        country_popular_stations_items_inner->subtitle = NULL;
    }
    if (country_popular_stations_items_inner->map) {
        free(country_popular_stations_items_inner->map);
        country_popular_stations_items_inner->map = NULL;
    }
    if (country_popular_stations_items_inner->type) {
        free(country_popular_stations_items_inner->type);
        country_popular_stations_items_inner->type = NULL;
    }
    if (country_popular_stations_items_inner->right_accessory) {
        free(country_popular_stations_items_inner->right_accessory);
        country_popular_stations_items_inner->right_accessory = NULL;
    }
    if (country_popular_stations_items_inner->page) {
        more_ref_page_free(country_popular_stations_items_inner->page);
        country_popular_stations_items_inner->page = NULL;
    }
    free(country_popular_stations_items_inner);
}

cJSON *country_popular_stations_items_inner_convertToJSON(country_popular_stations_items_inner_t *country_popular_stations_items_inner) {
    cJSON *item = cJSON_CreateObject();

    // country_popular_stations_items_inner->title
    if(country_popular_stations_items_inner->title) {
    if(cJSON_AddStringToObject(item, "title", country_popular_stations_items_inner->title) == NULL) {
    goto fail; //String
    }
    }


    // country_popular_stations_items_inner->href
    if(country_popular_stations_items_inner->href) {
    if(cJSON_AddStringToObject(item, "href", country_popular_stations_items_inner->href) == NULL) {
    goto fail; //String
    }
    }


    // country_popular_stations_items_inner->subtitle
    if(country_popular_stations_items_inner->subtitle) {
    if(cJSON_AddStringToObject(item, "subtitle", country_popular_stations_items_inner->subtitle) == NULL) {
    goto fail; //String
    }
    }


    // country_popular_stations_items_inner->map
    if(country_popular_stations_items_inner->map) {
    if(cJSON_AddStringToObject(item, "map", country_popular_stations_items_inner->map) == NULL) {
    goto fail; //String
    }
    }


    // country_popular_stations_items_inner->type
    if(country_popular_stations_items_inner->type) {
    if(cJSON_AddStringToObject(item, "type", country_popular_stations_items_inner->type) == NULL) {
    goto fail; //String
    }
    }


    // country_popular_stations_items_inner->right_accessory
    if(country_popular_stations_items_inner->right_accessory) {
    if(cJSON_AddStringToObject(item, "rightAccessory", country_popular_stations_items_inner->right_accessory) == NULL) {
    goto fail; //String
    }
    }


    // country_popular_stations_items_inner->page
    if(country_popular_stations_items_inner->page) {
    cJSON *page_local_JSON = more_ref_page_convertToJSON(country_popular_stations_items_inner->page);
    if(page_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "page", page_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

country_popular_stations_items_inner_t *country_popular_stations_items_inner_parseFromJSON(cJSON *country_popular_stations_items_innerJSON){

    country_popular_stations_items_inner_t *country_popular_stations_items_inner_local_var = NULL;

    // define the local variable for country_popular_stations_items_inner->page
    more_ref_page_t *page_local_nonprim = NULL;

    // country_popular_stations_items_inner->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(country_popular_stations_items_innerJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // country_popular_stations_items_inner->href
    cJSON *href = cJSON_GetObjectItemCaseSensitive(country_popular_stations_items_innerJSON, "href");
    if (href) { 
    if(!cJSON_IsString(href) && !cJSON_IsNull(href))
    {
    goto end; //String
    }
    }

    // country_popular_stations_items_inner->subtitle
    cJSON *subtitle = cJSON_GetObjectItemCaseSensitive(country_popular_stations_items_innerJSON, "subtitle");
    if (subtitle) { 
    if(!cJSON_IsString(subtitle) && !cJSON_IsNull(subtitle))
    {
    goto end; //String
    }
    }

    // country_popular_stations_items_inner->map
    cJSON *map = cJSON_GetObjectItemCaseSensitive(country_popular_stations_items_innerJSON, "map");
    if (map) { 
    if(!cJSON_IsString(map) && !cJSON_IsNull(map))
    {
    goto end; //String
    }
    }

    // country_popular_stations_items_inner->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(country_popular_stations_items_innerJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // country_popular_stations_items_inner->right_accessory
    cJSON *right_accessory = cJSON_GetObjectItemCaseSensitive(country_popular_stations_items_innerJSON, "rightAccessory");
    if (right_accessory) { 
    if(!cJSON_IsString(right_accessory) && !cJSON_IsNull(right_accessory))
    {
    goto end; //String
    }
    }

    // country_popular_stations_items_inner->page
    cJSON *page = cJSON_GetObjectItemCaseSensitive(country_popular_stations_items_innerJSON, "page");
    if (page) { 
    page_local_nonprim = more_ref_page_parseFromJSON(page); //nonprimitive
    }


    country_popular_stations_items_inner_local_var = country_popular_stations_items_inner_create (
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        href && !cJSON_IsNull(href) ? strdup(href->valuestring) : NULL,
        subtitle && !cJSON_IsNull(subtitle) ? strdup(subtitle->valuestring) : NULL,
        map && !cJSON_IsNull(map) ? strdup(map->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        right_accessory && !cJSON_IsNull(right_accessory) ? strdup(right_accessory->valuestring) : NULL,
        page ? page_local_nonprim : NULL
        );

    return country_popular_stations_items_inner_local_var;
end:
    if (page_local_nonprim) {
        more_ref_page_free(page_local_nonprim);
        page_local_nonprim = NULL;
    }
    return NULL;

}
