#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "place_ref.h"



place_ref_t *place_ref_create(
    char *title,
    char *subtitle,
    char *url,
    char *map,
    int count,
    int utc_offset
    ) {
    place_ref_t *place_ref_local_var = malloc(sizeof(place_ref_t));
    if (!place_ref_local_var) {
        return NULL;
    }
    place_ref_local_var->title = title;
    place_ref_local_var->subtitle = subtitle;
    place_ref_local_var->url = url;
    place_ref_local_var->map = map;
    place_ref_local_var->count = count;
    place_ref_local_var->utc_offset = utc_offset;

    return place_ref_local_var;
}


void place_ref_free(place_ref_t *place_ref) {
    if(NULL == place_ref){
        return ;
    }
    listEntry_t *listEntry;
    if (place_ref->title) {
        free(place_ref->title);
        place_ref->title = NULL;
    }
    if (place_ref->subtitle) {
        free(place_ref->subtitle);
        place_ref->subtitle = NULL;
    }
    if (place_ref->url) {
        free(place_ref->url);
        place_ref->url = NULL;
    }
    if (place_ref->map) {
        free(place_ref->map);
        place_ref->map = NULL;
    }
    free(place_ref);
}

cJSON *place_ref_convertToJSON(place_ref_t *place_ref) {
    cJSON *item = cJSON_CreateObject();

    // place_ref->title
    if(place_ref->title) {
    if(cJSON_AddStringToObject(item, "title", place_ref->title) == NULL) {
    goto fail; //String
    }
    }


    // place_ref->subtitle
    if(place_ref->subtitle) {
    if(cJSON_AddStringToObject(item, "subtitle", place_ref->subtitle) == NULL) {
    goto fail; //String
    }
    }


    // place_ref->url
    if(place_ref->url) {
    if(cJSON_AddStringToObject(item, "url", place_ref->url) == NULL) {
    goto fail; //String
    }
    }


    // place_ref->map
    if(place_ref->map) {
    if(cJSON_AddStringToObject(item, "map", place_ref->map) == NULL) {
    goto fail; //String
    }
    }


    // place_ref->count
    if(place_ref->count) {
    if(cJSON_AddNumberToObject(item, "count", place_ref->count) == NULL) {
    goto fail; //Numeric
    }
    }


    // place_ref->utc_offset
    if(place_ref->utc_offset) {
    if(cJSON_AddNumberToObject(item, "utcOffset", place_ref->utc_offset) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

place_ref_t *place_ref_parseFromJSON(cJSON *place_refJSON){

    place_ref_t *place_ref_local_var = NULL;

    // place_ref->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(place_refJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // place_ref->subtitle
    cJSON *subtitle = cJSON_GetObjectItemCaseSensitive(place_refJSON, "subtitle");
    if (subtitle) { 
    if(!cJSON_IsString(subtitle) && !cJSON_IsNull(subtitle))
    {
    goto end; //String
    }
    }

    // place_ref->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(place_refJSON, "url");
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }

    // place_ref->map
    cJSON *map = cJSON_GetObjectItemCaseSensitive(place_refJSON, "map");
    if (map) { 
    if(!cJSON_IsString(map) && !cJSON_IsNull(map))
    {
    goto end; //String
    }
    }

    // place_ref->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(place_refJSON, "count");
    if (count) { 
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }
    }

    // place_ref->utc_offset
    cJSON *utc_offset = cJSON_GetObjectItemCaseSensitive(place_refJSON, "utcOffset");
    if (utc_offset) { 
    if(!cJSON_IsNumber(utc_offset))
    {
    goto end; //Numeric
    }
    }


    place_ref_local_var = place_ref_create (
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        subtitle && !cJSON_IsNull(subtitle) ? strdup(subtitle->valuestring) : NULL,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL,
        map && !cJSON_IsNull(map) ? strdup(map->valuestring) : NULL,
        count ? count->valuedouble : 0,
        utc_offset ? utc_offset->valuedouble : 0
        );

    return place_ref_local_var;
end:
    return NULL;

}
