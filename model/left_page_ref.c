#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "left_page_ref.h"



left_page_ref_t *left_page_ref_create(
    char *title,
    char *left_accessory,
    int left_accessory_count,
    place_ref_t *page
    ) {
    left_page_ref_t *left_page_ref_local_var = malloc(sizeof(left_page_ref_t));
    if (!left_page_ref_local_var) {
        return NULL;
    }
    left_page_ref_local_var->title = title;
    left_page_ref_local_var->left_accessory = left_accessory;
    left_page_ref_local_var->left_accessory_count = left_accessory_count;
    left_page_ref_local_var->page = page;

    return left_page_ref_local_var;
}


void left_page_ref_free(left_page_ref_t *left_page_ref) {
    if(NULL == left_page_ref){
        return ;
    }
    listEntry_t *listEntry;
    if (left_page_ref->title) {
        free(left_page_ref->title);
        left_page_ref->title = NULL;
    }
    if (left_page_ref->left_accessory) {
        free(left_page_ref->left_accessory);
        left_page_ref->left_accessory = NULL;
    }
    if (left_page_ref->page) {
        place_ref_free(left_page_ref->page);
        left_page_ref->page = NULL;
    }
    free(left_page_ref);
}

cJSON *left_page_ref_convertToJSON(left_page_ref_t *left_page_ref) {
    cJSON *item = cJSON_CreateObject();

    // left_page_ref->title
    if(left_page_ref->title) {
    if(cJSON_AddStringToObject(item, "title", left_page_ref->title) == NULL) {
    goto fail; //String
    }
    }


    // left_page_ref->left_accessory
    if(left_page_ref->left_accessory) {
    if(cJSON_AddStringToObject(item, "leftAccessory", left_page_ref->left_accessory) == NULL) {
    goto fail; //String
    }
    }


    // left_page_ref->left_accessory_count
    if(left_page_ref->left_accessory_count) {
    if(cJSON_AddNumberToObject(item, "leftAccessoryCount", left_page_ref->left_accessory_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // left_page_ref->page
    if(left_page_ref->page) {
    cJSON *page_local_JSON = place_ref_convertToJSON(left_page_ref->page);
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

left_page_ref_t *left_page_ref_parseFromJSON(cJSON *left_page_refJSON){

    left_page_ref_t *left_page_ref_local_var = NULL;

    // define the local variable for left_page_ref->page
    place_ref_t *page_local_nonprim = NULL;

    // left_page_ref->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(left_page_refJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // left_page_ref->left_accessory
    cJSON *left_accessory = cJSON_GetObjectItemCaseSensitive(left_page_refJSON, "leftAccessory");
    if (left_accessory) { 
    if(!cJSON_IsString(left_accessory) && !cJSON_IsNull(left_accessory))
    {
    goto end; //String
    }
    }

    // left_page_ref->left_accessory_count
    cJSON *left_accessory_count = cJSON_GetObjectItemCaseSensitive(left_page_refJSON, "leftAccessoryCount");
    if (left_accessory_count) { 
    if(!cJSON_IsNumber(left_accessory_count))
    {
    goto end; //Numeric
    }
    }

    // left_page_ref->page
    cJSON *page = cJSON_GetObjectItemCaseSensitive(left_page_refJSON, "page");
    if (page) { 
    page_local_nonprim = place_ref_parseFromJSON(page); //nonprimitive
    }


    left_page_ref_local_var = left_page_ref_create (
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        left_accessory && !cJSON_IsNull(left_accessory) ? strdup(left_accessory->valuestring) : NULL,
        left_accessory_count ? left_accessory_count->valuedouble : 0,
        page ? page_local_nonprim : NULL
        );

    return left_page_ref_local_var;
end:
    if (page_local_nonprim) {
        place_ref_free(page_local_nonprim);
        page_local_nonprim = NULL;
    }
    return NULL;

}
