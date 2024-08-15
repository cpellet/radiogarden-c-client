#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "channel_ref.h"



channel_ref_t *channel_ref_create(
    char *title,
    char *href
    ) {
    channel_ref_t *channel_ref_local_var = malloc(sizeof(channel_ref_t));
    if (!channel_ref_local_var) {
        return NULL;
    }
    channel_ref_local_var->title = title;
    channel_ref_local_var->href = href;

    return channel_ref_local_var;
}


void channel_ref_free(channel_ref_t *channel_ref) {
    if(NULL == channel_ref){
        return ;
    }
    listEntry_t *listEntry;
    if (channel_ref->title) {
        free(channel_ref->title);
        channel_ref->title = NULL;
    }
    if (channel_ref->href) {
        free(channel_ref->href);
        channel_ref->href = NULL;
    }
    free(channel_ref);
}

cJSON *channel_ref_convertToJSON(channel_ref_t *channel_ref) {
    cJSON *item = cJSON_CreateObject();

    // channel_ref->title
    if(channel_ref->title) {
    if(cJSON_AddStringToObject(item, "title", channel_ref->title) == NULL) {
    goto fail; //String
    }
    }


    // channel_ref->href
    if(channel_ref->href) {
    if(cJSON_AddStringToObject(item, "href", channel_ref->href) == NULL) {
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

channel_ref_t *channel_ref_parseFromJSON(cJSON *channel_refJSON){

    channel_ref_t *channel_ref_local_var = NULL;

    // channel_ref->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(channel_refJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // channel_ref->href
    cJSON *href = cJSON_GetObjectItemCaseSensitive(channel_refJSON, "href");
    if (href) { 
    if(!cJSON_IsString(href) && !cJSON_IsNull(href))
    {
    goto end; //String
    }
    }


    channel_ref_local_var = channel_ref_create (
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        href && !cJSON_IsNull(href) ? strdup(href->valuestring) : NULL
        );

    return channel_ref_local_var;
end:
    return NULL;

}
