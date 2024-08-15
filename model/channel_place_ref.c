#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "channel_place_ref.h"



channel_place_ref_t *channel_place_ref_create(
    char *title,
    char *href,
    char *subtitle,
    char *map
    ) {
    channel_place_ref_t *channel_place_ref_local_var = malloc(sizeof(channel_place_ref_t));
    if (!channel_place_ref_local_var) {
        return NULL;
    }
    channel_place_ref_local_var->title = title;
    channel_place_ref_local_var->href = href;
    channel_place_ref_local_var->subtitle = subtitle;
    channel_place_ref_local_var->map = map;

    return channel_place_ref_local_var;
}


void channel_place_ref_free(channel_place_ref_t *channel_place_ref) {
    if(NULL == channel_place_ref){
        return ;
    }
    listEntry_t *listEntry;
    if (channel_place_ref->title) {
        free(channel_place_ref->title);
        channel_place_ref->title = NULL;
    }
    if (channel_place_ref->href) {
        free(channel_place_ref->href);
        channel_place_ref->href = NULL;
    }
    if (channel_place_ref->subtitle) {
        free(channel_place_ref->subtitle);
        channel_place_ref->subtitle = NULL;
    }
    if (channel_place_ref->map) {
        free(channel_place_ref->map);
        channel_place_ref->map = NULL;
    }
    free(channel_place_ref);
}

cJSON *channel_place_ref_convertToJSON(channel_place_ref_t *channel_place_ref) {
    cJSON *item = cJSON_CreateObject();

    // channel_place_ref->title
    if(channel_place_ref->title) {
    if(cJSON_AddStringToObject(item, "title", channel_place_ref->title) == NULL) {
    goto fail; //String
    }
    }


    // channel_place_ref->href
    if(channel_place_ref->href) {
    if(cJSON_AddStringToObject(item, "href", channel_place_ref->href) == NULL) {
    goto fail; //String
    }
    }


    // channel_place_ref->subtitle
    if(channel_place_ref->subtitle) {
    if(cJSON_AddStringToObject(item, "subtitle", channel_place_ref->subtitle) == NULL) {
    goto fail; //String
    }
    }


    // channel_place_ref->map
    if(channel_place_ref->map) {
    if(cJSON_AddStringToObject(item, "map", channel_place_ref->map) == NULL) {
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

channel_place_ref_t *channel_place_ref_parseFromJSON(cJSON *channel_place_refJSON){

    channel_place_ref_t *channel_place_ref_local_var = NULL;

    // channel_place_ref->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(channel_place_refJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // channel_place_ref->href
    cJSON *href = cJSON_GetObjectItemCaseSensitive(channel_place_refJSON, "href");
    if (href) { 
    if(!cJSON_IsString(href) && !cJSON_IsNull(href))
    {
    goto end; //String
    }
    }

    // channel_place_ref->subtitle
    cJSON *subtitle = cJSON_GetObjectItemCaseSensitive(channel_place_refJSON, "subtitle");
    if (subtitle) { 
    if(!cJSON_IsString(subtitle) && !cJSON_IsNull(subtitle))
    {
    goto end; //String
    }
    }

    // channel_place_ref->map
    cJSON *map = cJSON_GetObjectItemCaseSensitive(channel_place_refJSON, "map");
    if (map) { 
    if(!cJSON_IsString(map) && !cJSON_IsNull(map))
    {
    goto end; //String
    }
    }


    channel_place_ref_local_var = channel_place_ref_create (
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        href && !cJSON_IsNull(href) ? strdup(href->valuestring) : NULL,
        subtitle && !cJSON_IsNull(subtitle) ? strdup(subtitle->valuestring) : NULL,
        map && !cJSON_IsNull(map) ? strdup(map->valuestring) : NULL
        );

    return channel_place_ref_local_var;
end:
    return NULL;

}
