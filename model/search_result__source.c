#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "search_result__source.h"



search_result__source_t *search_result__source_create(
    char *code,
    char *subtitle,
    char *type,
    char *title,
    char *url
    ) {
    search_result__source_t *search_result__source_local_var = malloc(sizeof(search_result__source_t));
    if (!search_result__source_local_var) {
        return NULL;
    }
    search_result__source_local_var->code = code;
    search_result__source_local_var->subtitle = subtitle;
    search_result__source_local_var->type = type;
    search_result__source_local_var->title = title;
    search_result__source_local_var->url = url;

    return search_result__source_local_var;
}


void search_result__source_free(search_result__source_t *search_result__source) {
    if(NULL == search_result__source){
        return ;
    }
    listEntry_t *listEntry;
    if (search_result__source->code) {
        free(search_result__source->code);
        search_result__source->code = NULL;
    }
    if (search_result__source->subtitle) {
        free(search_result__source->subtitle);
        search_result__source->subtitle = NULL;
    }
    if (search_result__source->type) {
        free(search_result__source->type);
        search_result__source->type = NULL;
    }
    if (search_result__source->title) {
        free(search_result__source->title);
        search_result__source->title = NULL;
    }
    if (search_result__source->url) {
        free(search_result__source->url);
        search_result__source->url = NULL;
    }
    free(search_result__source);
}

cJSON *search_result__source_convertToJSON(search_result__source_t *search_result__source) {
    cJSON *item = cJSON_CreateObject();

    // search_result__source->code
    if(search_result__source->code) {
    if(cJSON_AddStringToObject(item, "code", search_result__source->code) == NULL) {
    goto fail; //String
    }
    }


    // search_result__source->subtitle
    if(search_result__source->subtitle) {
    if(cJSON_AddStringToObject(item, "subtitle", search_result__source->subtitle) == NULL) {
    goto fail; //String
    }
    }


    // search_result__source->type
    if(search_result__source->type) {
    if(cJSON_AddStringToObject(item, "type", search_result__source->type) == NULL) {
    goto fail; //String
    }
    }


    // search_result__source->title
    if(search_result__source->title) {
    if(cJSON_AddStringToObject(item, "title", search_result__source->title) == NULL) {
    goto fail; //String
    }
    }


    // search_result__source->url
    if(search_result__source->url) {
    if(cJSON_AddStringToObject(item, "url", search_result__source->url) == NULL) {
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

search_result__source_t *search_result__source_parseFromJSON(cJSON *search_result__sourceJSON){

    search_result__source_t *search_result__source_local_var = NULL;

    // search_result__source->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(search_result__sourceJSON, "code");
    if (code) { 
    if(!cJSON_IsString(code) && !cJSON_IsNull(code))
    {
    goto end; //String
    }
    }

    // search_result__source->subtitle
    cJSON *subtitle = cJSON_GetObjectItemCaseSensitive(search_result__sourceJSON, "subtitle");
    if (subtitle) { 
    if(!cJSON_IsString(subtitle) && !cJSON_IsNull(subtitle))
    {
    goto end; //String
    }
    }

    // search_result__source->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(search_result__sourceJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // search_result__source->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(search_result__sourceJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // search_result__source->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(search_result__sourceJSON, "url");
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }


    search_result__source_local_var = search_result__source_create (
        code && !cJSON_IsNull(code) ? strdup(code->valuestring) : NULL,
        subtitle && !cJSON_IsNull(subtitle) ? strdup(subtitle->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL
        );

    return search_result__source_local_var;
end:
    return NULL;

}
