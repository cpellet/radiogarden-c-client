#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "right_page_ref.h"



right_page_ref_t *right_page_ref_create(
    char *title,
    char *right_detail,
    place_ref_t *page
    ) {
    right_page_ref_t *right_page_ref_local_var = malloc(sizeof(right_page_ref_t));
    if (!right_page_ref_local_var) {
        return NULL;
    }
    right_page_ref_local_var->title = title;
    right_page_ref_local_var->right_detail = right_detail;
    right_page_ref_local_var->page = page;

    return right_page_ref_local_var;
}


void right_page_ref_free(right_page_ref_t *right_page_ref) {
    if(NULL == right_page_ref){
        return ;
    }
    listEntry_t *listEntry;
    if (right_page_ref->title) {
        free(right_page_ref->title);
        right_page_ref->title = NULL;
    }
    if (right_page_ref->right_detail) {
        free(right_page_ref->right_detail);
        right_page_ref->right_detail = NULL;
    }
    if (right_page_ref->page) {
        place_ref_free(right_page_ref->page);
        right_page_ref->page = NULL;
    }
    free(right_page_ref);
}

cJSON *right_page_ref_convertToJSON(right_page_ref_t *right_page_ref) {
    cJSON *item = cJSON_CreateObject();

    // right_page_ref->title
    if(right_page_ref->title) {
    if(cJSON_AddStringToObject(item, "title", right_page_ref->title) == NULL) {
    goto fail; //String
    }
    }


    // right_page_ref->right_detail
    if(right_page_ref->right_detail) {
    if(cJSON_AddStringToObject(item, "rightDetail", right_page_ref->right_detail) == NULL) {
    goto fail; //String
    }
    }


    // right_page_ref->page
    if(right_page_ref->page) {
    cJSON *page_local_JSON = place_ref_convertToJSON(right_page_ref->page);
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

right_page_ref_t *right_page_ref_parseFromJSON(cJSON *right_page_refJSON){

    right_page_ref_t *right_page_ref_local_var = NULL;

    // define the local variable for right_page_ref->page
    place_ref_t *page_local_nonprim = NULL;

    // right_page_ref->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(right_page_refJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // right_page_ref->right_detail
    cJSON *right_detail = cJSON_GetObjectItemCaseSensitive(right_page_refJSON, "rightDetail");
    if (right_detail) { 
    if(!cJSON_IsString(right_detail) && !cJSON_IsNull(right_detail))
    {
    goto end; //String
    }
    }

    // right_page_ref->page
    cJSON *page = cJSON_GetObjectItemCaseSensitive(right_page_refJSON, "page");
    if (page) { 
    page_local_nonprim = place_ref_parseFromJSON(page); //nonprimitive
    }


    right_page_ref_local_var = right_page_ref_create (
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        right_detail && !cJSON_IsNull(right_detail) ? strdup(right_detail->valuestring) : NULL,
        page ? page_local_nonprim : NULL
        );

    return right_page_ref_local_var;
end:
    if (page_local_nonprim) {
        place_ref_free(page_local_nonprim);
        page_local_nonprim = NULL;
    }
    return NULL;

}
