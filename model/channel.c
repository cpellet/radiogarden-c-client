#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "channel.h"



channel_t *channel_create(
    char *id,
    char *title,
    char *url,
    char *website,
    int secure,
    channel_place_t *place,
    channel_country_t *country
    ) {
    channel_t *channel_local_var = malloc(sizeof(channel_t));
    if (!channel_local_var) {
        return NULL;
    }
    channel_local_var->id = id;
    channel_local_var->title = title;
    channel_local_var->url = url;
    channel_local_var->website = website;
    channel_local_var->secure = secure;
    channel_local_var->place = place;
    channel_local_var->country = country;

    return channel_local_var;
}


void channel_free(channel_t *channel) {
    if(NULL == channel){
        return ;
    }
    listEntry_t *listEntry;
    if (channel->id) {
        free(channel->id);
        channel->id = NULL;
    }
    if (channel->title) {
        free(channel->title);
        channel->title = NULL;
    }
    if (channel->url) {
        free(channel->url);
        channel->url = NULL;
    }
    if (channel->website) {
        free(channel->website);
        channel->website = NULL;
    }
    if (channel->place) {
        channel_place_free(channel->place);
        channel->place = NULL;
    }
    if (channel->country) {
        channel_country_free(channel->country);
        channel->country = NULL;
    }
    free(channel);
}

cJSON *channel_convertToJSON(channel_t *channel) {
    cJSON *item = cJSON_CreateObject();

    // channel->id
    if(channel->id) {
    if(cJSON_AddStringToObject(item, "id", channel->id) == NULL) {
    goto fail; //String
    }
    }


    // channel->title
    if(channel->title) {
    if(cJSON_AddStringToObject(item, "title", channel->title) == NULL) {
    goto fail; //String
    }
    }


    // channel->url
    if(channel->url) {
    if(cJSON_AddStringToObject(item, "url", channel->url) == NULL) {
    goto fail; //String
    }
    }


    // channel->website
    if(channel->website) {
    if(cJSON_AddStringToObject(item, "website", channel->website) == NULL) {
    goto fail; //String
    }
    }


    // channel->secure
    if(channel->secure) {
    if(cJSON_AddBoolToObject(item, "secure", channel->secure) == NULL) {
    goto fail; //Bool
    }
    }


    // channel->place
    if(channel->place) {
    cJSON *place_local_JSON = channel_place_convertToJSON(channel->place);
    if(place_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "place", place_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // channel->country
    if(channel->country) {
    cJSON *country_local_JSON = channel_country_convertToJSON(channel->country);
    if(country_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "country", country_local_JSON);
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

channel_t *channel_parseFromJSON(cJSON *channelJSON){

    channel_t *channel_local_var = NULL;

    // define the local variable for channel->place
    channel_place_t *place_local_nonprim = NULL;

    // define the local variable for channel->country
    channel_country_t *country_local_nonprim = NULL;

    // channel->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(channelJSON, "id");
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // channel->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(channelJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // channel->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(channelJSON, "url");
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }

    // channel->website
    cJSON *website = cJSON_GetObjectItemCaseSensitive(channelJSON, "website");
    if (website) { 
    if(!cJSON_IsString(website) && !cJSON_IsNull(website))
    {
    goto end; //String
    }
    }

    // channel->secure
    cJSON *secure = cJSON_GetObjectItemCaseSensitive(channelJSON, "secure");
    if (secure) { 
    if(!cJSON_IsBool(secure))
    {
    goto end; //Bool
    }
    }

    // channel->place
    cJSON *place = cJSON_GetObjectItemCaseSensitive(channelJSON, "place");
    if (place) { 
    place_local_nonprim = channel_place_parseFromJSON(place); //nonprimitive
    }

    // channel->country
    cJSON *country = cJSON_GetObjectItemCaseSensitive(channelJSON, "country");
    if (country) { 
    country_local_nonprim = channel_country_parseFromJSON(country); //nonprimitive
    }


    channel_local_var = channel_create (
        id && !cJSON_IsNull(id) ? strdup(id->valuestring) : NULL,
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL,
        website && !cJSON_IsNull(website) ? strdup(website->valuestring) : NULL,
        secure ? secure->valueint : 0,
        place ? place_local_nonprim : NULL,
        country ? country_local_nonprim : NULL
        );

    return channel_local_var;
end:
    if (place_local_nonprim) {
        channel_place_free(place_local_nonprim);
        place_local_nonprim = NULL;
    }
    if (country_local_nonprim) {
        channel_country_free(country_local_nonprim);
        country_local_nonprim = NULL;
    }
    return NULL;

}
