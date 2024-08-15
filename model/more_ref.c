#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "more_ref.h"



more_ref_t *more_ref_create(
    char *title,
    char *type,
    char *right_accessory,
    more_ref_page_t *page
    ) {
    more_ref_t *more_ref_local_var = malloc(sizeof(more_ref_t));
    if (!more_ref_local_var) {
        return NULL;
    }
    more_ref_local_var->title = title;
    more_ref_local_var->type = type;
    more_ref_local_var->right_accessory = right_accessory;
    more_ref_local_var->page = page;

    return more_ref_local_var;
}


void more_ref_free(more_ref_t *more_ref) {
    if(NULL == more_ref){
        return ;
    }
    listEntry_t *listEntry;
    if (more_ref->title) {
        free(more_ref->title);
        more_ref->title = NULL;
    }
    if (more_ref->type) {
        free(more_ref->type);
        more_ref->type = NULL;
    }
    if (more_ref->right_accessory) {
        free(more_ref->right_accessory);
        more_ref->right_accessory = NULL;
    }
    if (more_ref->page) {
        more_ref_page_free(more_ref->page);
        more_ref->page = NULL;
    }
    free(more_ref);
}

cJSON *more_ref_convertToJSON(more_ref_t *more_ref) {
    cJSON *item = cJSON_CreateObject();

    // more_ref->title
    if(more_ref->title) {
    if(cJSON_AddStringToObject(item, "title", more_ref->title) == NULL) {
    goto fail; //String
    }
    }


    // more_ref->type
    if(more_ref->type) {
    if(cJSON_AddStringToObject(item, "type", more_ref->type) == NULL) {
    goto fail; //String
    }
    }


    // more_ref->right_accessory
    if(more_ref->right_accessory) {
    if(cJSON_AddStringToObject(item, "rightAccessory", more_ref->right_accessory) == NULL) {
    goto fail; //String
    }
    }


    // more_ref->page
    if(more_ref->page) {
    cJSON *page_local_JSON = more_ref_page_convertToJSON(more_ref->page);
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

more_ref_t *more_ref_parseFromJSON(cJSON *more_refJSON){

    more_ref_t *more_ref_local_var = NULL;

    // define the local variable for more_ref->page
    more_ref_page_t *page_local_nonprim = NULL;

    // more_ref->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(more_refJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // more_ref->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(more_refJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // more_ref->right_accessory
    cJSON *right_accessory = cJSON_GetObjectItemCaseSensitive(more_refJSON, "rightAccessory");
    if (right_accessory) { 
    if(!cJSON_IsString(right_accessory) && !cJSON_IsNull(right_accessory))
    {
    goto end; //String
    }
    }

    // more_ref->page
    cJSON *page = cJSON_GetObjectItemCaseSensitive(more_refJSON, "page");
    if (page) { 
    page_local_nonprim = more_ref_page_parseFromJSON(page); //nonprimitive
    }


    more_ref_local_var = more_ref_create (
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        right_accessory && !cJSON_IsNull(right_accessory) ? strdup(right_accessory->valuestring) : NULL,
        page ? page_local_nonprim : NULL
        );

    return more_ref_local_var;
end:
    if (page_local_nonprim) {
        more_ref_page_free(page_local_nonprim);
        page_local_nonprim = NULL;
    }
    return NULL;

}
