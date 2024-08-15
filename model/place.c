#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "place.h"



place_t *place_create(
    char *id,
    list_t *geo,
    char *url,
    int size,
    int boost,
    char *title,
    char *country
    ) {
    place_t *place_local_var = malloc(sizeof(place_t));
    if (!place_local_var) {
        return NULL;
    }
    place_local_var->id = id;
    place_local_var->geo = geo;
    place_local_var->url = url;
    place_local_var->size = size;
    place_local_var->boost = boost;
    place_local_var->title = title;
    place_local_var->country = country;

    return place_local_var;
}


void place_free(place_t *place) {
    if(NULL == place){
        return ;
    }
    listEntry_t *listEntry;
    if (place->id) {
        free(place->id);
        place->id = NULL;
    }
    if (place->geo) {
        list_ForEach(listEntry, place->geo) {
            free(listEntry->data);
        }
        list_freeList(place->geo);
        place->geo = NULL;
    }
    if (place->url) {
        free(place->url);
        place->url = NULL;
    }
    if (place->title) {
        free(place->title);
        place->title = NULL;
    }
    if (place->country) {
        free(place->country);
        place->country = NULL;
    }
    free(place);
}

cJSON *place_convertToJSON(place_t *place) {
    cJSON *item = cJSON_CreateObject();

    // place->id
    if(place->id) {
    if(cJSON_AddStringToObject(item, "id", place->id) == NULL) {
    goto fail; //String
    }
    }


    // place->geo
    if(place->geo) {
    cJSON *geo = cJSON_AddArrayToObject(item, "geo");
    if(geo == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *geoListEntry;
    list_ForEach(geoListEntry, place->geo) {
    if(cJSON_AddNumberToObject(geo, "", *(double *)geoListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // place->url
    if(place->url) {
    if(cJSON_AddStringToObject(item, "url", place->url) == NULL) {
    goto fail; //String
    }
    }


    // place->size
    if(place->size) {
    if(cJSON_AddNumberToObject(item, "size", place->size) == NULL) {
    goto fail; //Numeric
    }
    }


    // place->boost
    if(place->boost) {
    if(cJSON_AddBoolToObject(item, "boost", place->boost) == NULL) {
    goto fail; //Bool
    }
    }


    // place->title
    if(place->title) {
    if(cJSON_AddStringToObject(item, "title", place->title) == NULL) {
    goto fail; //String
    }
    }


    // place->country
    if(place->country) {
    if(cJSON_AddStringToObject(item, "country", place->country) == NULL) {
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

place_t *place_parseFromJSON(cJSON *placeJSON){

    place_t *place_local_var = NULL;

    // define the local list for place->geo
    list_t *geoList = NULL;

    // place->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(placeJSON, "id");
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // place->geo
    cJSON *geo = cJSON_GetObjectItemCaseSensitive(placeJSON, "geo");
    if (geo) { 
    cJSON *geo_local = NULL;
    if(!cJSON_IsArray(geo)) {
        goto end;//primitive container
    }
    geoList = list_createList();

    cJSON_ArrayForEach(geo_local, geo)
    {
        if(!cJSON_IsNumber(geo_local))
        {
            goto end;
        }
        double *geo_local_value = (double *)calloc(1, sizeof(double));
        if(!geo_local_value)
        {
            goto end;
        }
        *geo_local_value = geo_local->valuedouble;
        list_addElement(geoList , geo_local_value);
    }
    }

    // place->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(placeJSON, "url");
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }

    // place->size
    cJSON *size = cJSON_GetObjectItemCaseSensitive(placeJSON, "size");
    if (size) { 
    if(!cJSON_IsNumber(size))
    {
    goto end; //Numeric
    }
    }

    // place->boost
    cJSON *boost = cJSON_GetObjectItemCaseSensitive(placeJSON, "boost");
    if (boost) { 
    if(!cJSON_IsBool(boost))
    {
    goto end; //Bool
    }
    }

    // place->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(placeJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // place->country
    cJSON *country = cJSON_GetObjectItemCaseSensitive(placeJSON, "country");
    if (country) { 
    if(!cJSON_IsString(country) && !cJSON_IsNull(country))
    {
    goto end; //String
    }
    }


    place_local_var = place_create (
        id && !cJSON_IsNull(id) ? strdup(id->valuestring) : NULL,
        geo ? geoList : NULL,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL,
        size ? size->valuedouble : 0,
        boost ? boost->valueint : 0,
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        country && !cJSON_IsNull(country) ? strdup(country->valuestring) : NULL
        );

    return place_local_var;
end:
    if (geoList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, geoList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(geoList);
        geoList = NULL;
    }
    return NULL;

}
