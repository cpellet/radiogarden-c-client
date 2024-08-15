#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "more_ref_page.h"



more_ref_page_t *more_ref_page_create(
    char *title,
    char *subtitle,
    char *url,
    list_t *map,
    int count,
    int utc_offset
    ) {
    more_ref_page_t *more_ref_page_local_var = malloc(sizeof(more_ref_page_t));
    if (!more_ref_page_local_var) {
        return NULL;
    }
    more_ref_page_local_var->title = title;
    more_ref_page_local_var->subtitle = subtitle;
    more_ref_page_local_var->url = url;
    more_ref_page_local_var->map = map;
    more_ref_page_local_var->count = count;
    more_ref_page_local_var->utc_offset = utc_offset;

    return more_ref_page_local_var;
}


void more_ref_page_free(more_ref_page_t *more_ref_page) {
    if(NULL == more_ref_page){
        return ;
    }
    listEntry_t *listEntry;
    if (more_ref_page->title) {
        free(more_ref_page->title);
        more_ref_page->title = NULL;
    }
    if (more_ref_page->subtitle) {
        free(more_ref_page->subtitle);
        more_ref_page->subtitle = NULL;
    }
    if (more_ref_page->url) {
        free(more_ref_page->url);
        more_ref_page->url = NULL;
    }
    if (more_ref_page->map) {
        list_ForEach(listEntry, more_ref_page->map) {
            free(listEntry->data);
        }
        list_freeList(more_ref_page->map);
        more_ref_page->map = NULL;
    }
    free(more_ref_page);
}

cJSON *more_ref_page_convertToJSON(more_ref_page_t *more_ref_page) {
    cJSON *item = cJSON_CreateObject();

    // more_ref_page->title
    if(more_ref_page->title) {
    if(cJSON_AddStringToObject(item, "title", more_ref_page->title) == NULL) {
    goto fail; //String
    }
    }


    // more_ref_page->subtitle
    if(more_ref_page->subtitle) {
    if(cJSON_AddStringToObject(item, "subtitle", more_ref_page->subtitle) == NULL) {
    goto fail; //String
    }
    }


    // more_ref_page->url
    if(more_ref_page->url) {
    if(cJSON_AddStringToObject(item, "url", more_ref_page->url) == NULL) {
    goto fail; //String
    }
    }


    // more_ref_page->map
    if(more_ref_page->map) {
    cJSON *map = cJSON_AddArrayToObject(item, "map");
    if(map == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *mapListEntry;
    list_ForEach(mapListEntry, more_ref_page->map) {
    if(cJSON_AddNumberToObject(map, "", *(double *)mapListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // more_ref_page->count
    if(more_ref_page->count) {
    if(cJSON_AddNumberToObject(item, "count", more_ref_page->count) == NULL) {
    goto fail; //Numeric
    }
    }


    // more_ref_page->utc_offset
    if(more_ref_page->utc_offset) {
    if(cJSON_AddNumberToObject(item, "utcOffset", more_ref_page->utc_offset) == NULL) {
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

more_ref_page_t *more_ref_page_parseFromJSON(cJSON *more_ref_pageJSON){

    more_ref_page_t *more_ref_page_local_var = NULL;

    // define the local list for more_ref_page->map
    list_t *mapList = NULL;

    // more_ref_page->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(more_ref_pageJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // more_ref_page->subtitle
    cJSON *subtitle = cJSON_GetObjectItemCaseSensitive(more_ref_pageJSON, "subtitle");
    if (subtitle) { 
    if(!cJSON_IsString(subtitle) && !cJSON_IsNull(subtitle))
    {
    goto end; //String
    }
    }

    // more_ref_page->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(more_ref_pageJSON, "url");
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }

    // more_ref_page->map
    cJSON *map = cJSON_GetObjectItemCaseSensitive(more_ref_pageJSON, "map");
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

    // more_ref_page->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(more_ref_pageJSON, "count");
    if (count) { 
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }
    }

    // more_ref_page->utc_offset
    cJSON *utc_offset = cJSON_GetObjectItemCaseSensitive(more_ref_pageJSON, "utcOffset");
    if (utc_offset) { 
    if(!cJSON_IsNumber(utc_offset))
    {
    goto end; //Numeric
    }
    }


    more_ref_page_local_var = more_ref_page_create (
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        subtitle && !cJSON_IsNull(subtitle) ? strdup(subtitle->valuestring) : NULL,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL,
        map ? mapList : NULL,
        count ? count->valuedouble : 0,
        utc_offset ? utc_offset->valuedouble : 0
        );

    return more_ref_page_local_var;
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
