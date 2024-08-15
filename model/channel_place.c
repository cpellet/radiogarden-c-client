#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "channel_place.h"



channel_place_t *channel_place_create(
    char *id,
    char *title
    ) {
    channel_place_t *channel_place_local_var = malloc(sizeof(channel_place_t));
    if (!channel_place_local_var) {
        return NULL;
    }
    channel_place_local_var->id = id;
    channel_place_local_var->title = title;

    return channel_place_local_var;
}


void channel_place_free(channel_place_t *channel_place) {
    if(NULL == channel_place){
        return ;
    }
    listEntry_t *listEntry;
    if (channel_place->id) {
        free(channel_place->id);
        channel_place->id = NULL;
    }
    if (channel_place->title) {
        free(channel_place->title);
        channel_place->title = NULL;
    }
    free(channel_place);
}

cJSON *channel_place_convertToJSON(channel_place_t *channel_place) {
    cJSON *item = cJSON_CreateObject();

    // channel_place->id
    if(channel_place->id) {
    if(cJSON_AddStringToObject(item, "id", channel_place->id) == NULL) {
    goto fail; //String
    }
    }


    // channel_place->title
    if(channel_place->title) {
    if(cJSON_AddStringToObject(item, "title", channel_place->title) == NULL) {
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

channel_place_t *channel_place_parseFromJSON(cJSON *channel_placeJSON){

    channel_place_t *channel_place_local_var = NULL;

    // channel_place->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(channel_placeJSON, "id");
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // channel_place->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(channel_placeJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }


    channel_place_local_var = channel_place_create (
        id && !cJSON_IsNull(id) ? strdup(id->valuestring) : NULL,
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL
        );

    return channel_place_local_var;
end:
    return NULL;

}
