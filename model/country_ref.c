#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "country_ref.h"



country_ref_t *country_ref_create(
    char *title,
    char *url,
    list_t *map
    ) {
    country_ref_t *country_ref_local_var = malloc(sizeof(country_ref_t));
    if (!country_ref_local_var) {
        return NULL;
    }
    country_ref_local_var->title = title;
    country_ref_local_var->url = url;
    country_ref_local_var->map = map;

    return country_ref_local_var;
}


void country_ref_free(country_ref_t *country_ref) {
    if(NULL == country_ref){
        return ;
    }
    listEntry_t *listEntry;
    if (country_ref->title) {
        free(country_ref->title);
        country_ref->title = NULL;
    }
    if (country_ref->url) {
        free(country_ref->url);
        country_ref->url = NULL;
    }
    if (country_ref->map) {
        list_ForEach(listEntry, country_ref->map) {
            free(listEntry->data);
        }
        list_freeList(country_ref->map);
        country_ref->map = NULL;
    }
    free(country_ref);
}

cJSON *country_ref_convertToJSON(country_ref_t *country_ref) {
    cJSON *item = cJSON_CreateObject();

    // country_ref->title
    if(country_ref->title) {
    if(cJSON_AddStringToObject(item, "title", country_ref->title) == NULL) {
    goto fail; //String
    }
    }


    // country_ref->url
    if(country_ref->url) {
    if(cJSON_AddStringToObject(item, "url", country_ref->url) == NULL) {
    goto fail; //String
    }
    }


    // country_ref->map
    if(country_ref->map) {
    cJSON *map = cJSON_AddArrayToObject(item, "map");
    if(map == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *mapListEntry;
    list_ForEach(mapListEntry, country_ref->map) {
    if(cJSON_AddNumberToObject(map, "", *(double *)mapListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

country_ref_t *country_ref_parseFromJSON(cJSON *country_refJSON){

    country_ref_t *country_ref_local_var = NULL;

    // define the local list for country_ref->map
    list_t *mapList = NULL;

    // country_ref->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(country_refJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // country_ref->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(country_refJSON, "url");
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }

    // country_ref->map
    cJSON *map = cJSON_GetObjectItemCaseSensitive(country_refJSON, "map");
    if (map) { 
    cJSON *map_local = NULL;
    if(!cJSON_IsArray(map)) {
        goto end;//primitive container
    }
    mapList = list_createList();

    cJSON_ArrayForEach(map_local, map)
    {
        if(!cJSON_IsNumber(map_local))
        {
            goto end;
        }
        double *map_local_value = (double *)calloc(1, sizeof(double));
        if(!map_local_value)
        {
            goto end;
        }
        *map_local_value = map_local->valuedouble;
        list_addElement(mapList , map_local_value);
    }
    }


    country_ref_local_var = country_ref_create (
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL,
        map ? mapList : NULL
        );

    return country_ref_local_var;
end:
    if (mapList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, mapList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(mapList);
        mapList = NULL;
    }
    return NULL;

}
