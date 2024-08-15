#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "channel_country.h"



channel_country_t *channel_country_create(
    char *id,
    char *title
    ) {
    channel_country_t *channel_country_local_var = malloc(sizeof(channel_country_t));
    if (!channel_country_local_var) {
        return NULL;
    }
    channel_country_local_var->id = id;
    channel_country_local_var->title = title;

    return channel_country_local_var;
}


void channel_country_free(channel_country_t *channel_country) {
    if(NULL == channel_country){
        return ;
    }
    listEntry_t *listEntry;
    if (channel_country->id) {
        free(channel_country->id);
        channel_country->id = NULL;
    }
    if (channel_country->title) {
        free(channel_country->title);
        channel_country->title = NULL;
    }
    free(channel_country);
}

cJSON *channel_country_convertToJSON(channel_country_t *channel_country) {
    cJSON *item = cJSON_CreateObject();

    // channel_country->id
    if(channel_country->id) {
    if(cJSON_AddStringToObject(item, "id", channel_country->id) == NULL) {
    goto fail; //String
    }
    }


    // channel_country->title
    if(channel_country->title) {
    if(cJSON_AddStringToObject(item, "title", channel_country->title) == NULL) {
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

channel_country_t *channel_country_parseFromJSON(cJSON *channel_countryJSON){

    channel_country_t *channel_country_local_var = NULL;

    // channel_country->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(channel_countryJSON, "id");
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // channel_country->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(channel_countryJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }


    channel_country_local_var = channel_country_create (
        id && !cJSON_IsNull(id) ? strdup(id->valuestring) : NULL,
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL
        );

    return channel_country_local_var;
end:
    return NULL;

}
