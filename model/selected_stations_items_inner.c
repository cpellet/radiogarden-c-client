#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "selected_stations_items_inner.h"



selected_stations_items_inner_t *selected_stations_items_inner_create(
    char *title,
    char *href,
    char *type,
    char *right_accessory,
    more_ref_page_t *page
    ) {
    selected_stations_items_inner_t *selected_stations_items_inner_local_var = malloc(sizeof(selected_stations_items_inner_t));
    if (!selected_stations_items_inner_local_var) {
        return NULL;
    }
    selected_stations_items_inner_local_var->title = title;
    selected_stations_items_inner_local_var->href = href;
    selected_stations_items_inner_local_var->type = type;
    selected_stations_items_inner_local_var->right_accessory = right_accessory;
    selected_stations_items_inner_local_var->page = page;

    return selected_stations_items_inner_local_var;
}


void selected_stations_items_inner_free(selected_stations_items_inner_t *selected_stations_items_inner) {
    if(NULL == selected_stations_items_inner){
        return ;
    }
    listEntry_t *listEntry;
    if (selected_stations_items_inner->title) {
        free(selected_stations_items_inner->title);
        selected_stations_items_inner->title = NULL;
    }
    if (selected_stations_items_inner->href) {
        free(selected_stations_items_inner->href);
        selected_stations_items_inner->href = NULL;
    }
    if (selected_stations_items_inner->type) {
        free(selected_stations_items_inner->type);
        selected_stations_items_inner->type = NULL;
    }
    if (selected_stations_items_inner->right_accessory) {
        free(selected_stations_items_inner->right_accessory);
        selected_stations_items_inner->right_accessory = NULL;
    }
    if (selected_stations_items_inner->page) {
        more_ref_page_free(selected_stations_items_inner->page);
        selected_stations_items_inner->page = NULL;
    }
    free(selected_stations_items_inner);
}

cJSON *selected_stations_items_inner_convertToJSON(selected_stations_items_inner_t *selected_stations_items_inner) {
    cJSON *item = cJSON_CreateObject();

    // selected_stations_items_inner->title
    if(selected_stations_items_inner->title) {
    if(cJSON_AddStringToObject(item, "title", selected_stations_items_inner->title) == NULL) {
    goto fail; //String
    }
    }


    // selected_stations_items_inner->href
    if(selected_stations_items_inner->href) {
    if(cJSON_AddStringToObject(item, "href", selected_stations_items_inner->href) == NULL) {
    goto fail; //String
    }
    }


    // selected_stations_items_inner->type
    if(selected_stations_items_inner->type) {
    if(cJSON_AddStringToObject(item, "type", selected_stations_items_inner->type) == NULL) {
    goto fail; //String
    }
    }


    // selected_stations_items_inner->right_accessory
    if(selected_stations_items_inner->right_accessory) {
    if(cJSON_AddStringToObject(item, "rightAccessory", selected_stations_items_inner->right_accessory) == NULL) {
    goto fail; //String
    }
    }


    // selected_stations_items_inner->page
    if(selected_stations_items_inner->page) {
    cJSON *page_local_JSON = more_ref_page_convertToJSON(selected_stations_items_inner->page);
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

selected_stations_items_inner_t *selected_stations_items_inner_parseFromJSON(cJSON *selected_stations_items_innerJSON){

    selected_stations_items_inner_t *selected_stations_items_inner_local_var = NULL;

    // define the local variable for selected_stations_items_inner->page
    more_ref_page_t *page_local_nonprim = NULL;

    // selected_stations_items_inner->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(selected_stations_items_innerJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // selected_stations_items_inner->href
    cJSON *href = cJSON_GetObjectItemCaseSensitive(selected_stations_items_innerJSON, "href");
    if (href) { 
    if(!cJSON_IsString(href) && !cJSON_IsNull(href))
    {
    goto end; //String
    }
    }

    // selected_stations_items_inner->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(selected_stations_items_innerJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // selected_stations_items_inner->right_accessory
    cJSON *right_accessory = cJSON_GetObjectItemCaseSensitive(selected_stations_items_innerJSON, "rightAccessory");
    if (right_accessory) { 
    if(!cJSON_IsString(right_accessory) && !cJSON_IsNull(right_accessory))
    {
    goto end; //String
    }
    }

    // selected_stations_items_inner->page
    cJSON *page = cJSON_GetObjectItemCaseSensitive(selected_stations_items_innerJSON, "page");
    if (page) { 
    page_local_nonprim = more_ref_page_parseFromJSON(page); //nonprimitive
    }


    selected_stations_items_inner_local_var = selected_stations_items_inner_create (
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        href && !cJSON_IsNull(href) ? strdup(href->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        right_accessory && !cJSON_IsNull(right_accessory) ? strdup(right_accessory->valuestring) : NULL,
        page ? page_local_nonprim : NULL
        );

    return selected_stations_items_inner_local_var;
end:
    if (page_local_nonprim) {
        more_ref_page_free(page_local_nonprim);
        page_local_nonprim = NULL;
    }
    return NULL;

}
