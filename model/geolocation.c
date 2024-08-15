#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "geolocation.h"



geolocation_t *geolocation_create(
    char *ip,
    char *country_code,
    char *country_name,
    char *region_code,
    char *region_name,
    char *city,
    char *zip_code,
    char *time_zone,
    float latitude,
    float longitude,
    int metro_code
    ) {
    geolocation_t *geolocation_local_var = malloc(sizeof(geolocation_t));
    if (!geolocation_local_var) {
        return NULL;
    }
    geolocation_local_var->ip = ip;
    geolocation_local_var->country_code = country_code;
    geolocation_local_var->country_name = country_name;
    geolocation_local_var->region_code = region_code;
    geolocation_local_var->region_name = region_name;
    geolocation_local_var->city = city;
    geolocation_local_var->zip_code = zip_code;
    geolocation_local_var->time_zone = time_zone;
    geolocation_local_var->latitude = latitude;
    geolocation_local_var->longitude = longitude;
    geolocation_local_var->metro_code = metro_code;

    return geolocation_local_var;
}


void geolocation_free(geolocation_t *geolocation) {
    if(NULL == geolocation){
        return ;
    }
    listEntry_t *listEntry;
    if (geolocation->ip) {
        free(geolocation->ip);
        geolocation->ip = NULL;
    }
    if (geolocation->country_code) {
        free(geolocation->country_code);
        geolocation->country_code = NULL;
    }
    if (geolocation->country_name) {
        free(geolocation->country_name);
        geolocation->country_name = NULL;
    }
    if (geolocation->region_code) {
        free(geolocation->region_code);
        geolocation->region_code = NULL;
    }
    if (geolocation->region_name) {
        free(geolocation->region_name);
        geolocation->region_name = NULL;
    }
    if (geolocation->city) {
        free(geolocation->city);
        geolocation->city = NULL;
    }
    if (geolocation->zip_code) {
        free(geolocation->zip_code);
        geolocation->zip_code = NULL;
    }
    if (geolocation->time_zone) {
        free(geolocation->time_zone);
        geolocation->time_zone = NULL;
    }
    free(geolocation);
}

cJSON *geolocation_convertToJSON(geolocation_t *geolocation) {
    cJSON *item = cJSON_CreateObject();

    // geolocation->ip
    if(geolocation->ip) {
    if(cJSON_AddStringToObject(item, "ip", geolocation->ip) == NULL) {
    goto fail; //String
    }
    }


    // geolocation->country_code
    if(geolocation->country_code) {
    if(cJSON_AddStringToObject(item, "country_code", geolocation->country_code) == NULL) {
    goto fail; //String
    }
    }


    // geolocation->country_name
    if(geolocation->country_name) {
    if(cJSON_AddStringToObject(item, "country_name", geolocation->country_name) == NULL) {
    goto fail; //String
    }
    }


    // geolocation->region_code
    if(geolocation->region_code) {
    if(cJSON_AddStringToObject(item, "region_code", geolocation->region_code) == NULL) {
    goto fail; //String
    }
    }


    // geolocation->region_name
    if(geolocation->region_name) {
    if(cJSON_AddStringToObject(item, "region_name", geolocation->region_name) == NULL) {
    goto fail; //String
    }
    }


    // geolocation->city
    if(geolocation->city) {
    if(cJSON_AddStringToObject(item, "city", geolocation->city) == NULL) {
    goto fail; //String
    }
    }


    // geolocation->zip_code
    if(geolocation->zip_code) {
    if(cJSON_AddStringToObject(item, "zip_code", geolocation->zip_code) == NULL) {
    goto fail; //String
    }
    }


    // geolocation->time_zone
    if(geolocation->time_zone) {
    if(cJSON_AddStringToObject(item, "time_zone", geolocation->time_zone) == NULL) {
    goto fail; //String
    }
    }


    // geolocation->latitude
    if(geolocation->latitude) {
    if(cJSON_AddNumberToObject(item, "latitude", geolocation->latitude) == NULL) {
    goto fail; //Numeric
    }
    }


    // geolocation->longitude
    if(geolocation->longitude) {
    if(cJSON_AddNumberToObject(item, "longitude", geolocation->longitude) == NULL) {
    goto fail; //Numeric
    }
    }


    // geolocation->metro_code
    if(geolocation->metro_code) {
    if(cJSON_AddNumberToObject(item, "metro_code", geolocation->metro_code) == NULL) {
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

geolocation_t *geolocation_parseFromJSON(cJSON *geolocationJSON){

    geolocation_t *geolocation_local_var = NULL;

    // geolocation->ip
    cJSON *ip = cJSON_GetObjectItemCaseSensitive(geolocationJSON, "ip");
    if (ip) { 
    if(!cJSON_IsString(ip) && !cJSON_IsNull(ip))
    {
    goto end; //String
    }
    }

    // geolocation->country_code
    cJSON *country_code = cJSON_GetObjectItemCaseSensitive(geolocationJSON, "country_code");
    if (country_code) { 
    if(!cJSON_IsString(country_code) && !cJSON_IsNull(country_code))
    {
    goto end; //String
    }
    }

    // geolocation->country_name
    cJSON *country_name = cJSON_GetObjectItemCaseSensitive(geolocationJSON, "country_name");
    if (country_name) { 
    if(!cJSON_IsString(country_name) && !cJSON_IsNull(country_name))
    {
    goto end; //String
    }
    }

    // geolocation->region_code
    cJSON *region_code = cJSON_GetObjectItemCaseSensitive(geolocationJSON, "region_code");
    if (region_code) { 
    if(!cJSON_IsString(region_code) && !cJSON_IsNull(region_code))
    {
    goto end; //String
    }
    }

    // geolocation->region_name
    cJSON *region_name = cJSON_GetObjectItemCaseSensitive(geolocationJSON, "region_name");
    if (region_name) { 
    if(!cJSON_IsString(region_name) && !cJSON_IsNull(region_name))
    {
    goto end; //String
    }
    }

    // geolocation->city
    cJSON *city = cJSON_GetObjectItemCaseSensitive(geolocationJSON, "city");
    if (city) { 
    if(!cJSON_IsString(city) && !cJSON_IsNull(city))
    {
    goto end; //String
    }
    }

    // geolocation->zip_code
    cJSON *zip_code = cJSON_GetObjectItemCaseSensitive(geolocationJSON, "zip_code");
    if (zip_code) { 
    if(!cJSON_IsString(zip_code) && !cJSON_IsNull(zip_code))
    {
    goto end; //String
    }
    }

    // geolocation->time_zone
    cJSON *time_zone = cJSON_GetObjectItemCaseSensitive(geolocationJSON, "time_zone");
    if (time_zone) { 
    if(!cJSON_IsString(time_zone) && !cJSON_IsNull(time_zone))
    {
    goto end; //String
    }
    }

    // geolocation->latitude
    cJSON *latitude = cJSON_GetObjectItemCaseSensitive(geolocationJSON, "latitude");
    if (latitude) { 
    if(!cJSON_IsNumber(latitude))
    {
    goto end; //Numeric
    }
    }

    // geolocation->longitude
    cJSON *longitude = cJSON_GetObjectItemCaseSensitive(geolocationJSON, "longitude");
    if (longitude) { 
    if(!cJSON_IsNumber(longitude))
    {
    goto end; //Numeric
    }
    }

    // geolocation->metro_code
    cJSON *metro_code = cJSON_GetObjectItemCaseSensitive(geolocationJSON, "metro_code");
    if (metro_code) { 
    if(!cJSON_IsNumber(metro_code))
    {
    goto end; //Numeric
    }
    }


    geolocation_local_var = geolocation_create (
        ip && !cJSON_IsNull(ip) ? strdup(ip->valuestring) : NULL,
        country_code && !cJSON_IsNull(country_code) ? strdup(country_code->valuestring) : NULL,
        country_name && !cJSON_IsNull(country_name) ? strdup(country_name->valuestring) : NULL,
        region_code && !cJSON_IsNull(region_code) ? strdup(region_code->valuestring) : NULL,
        region_name && !cJSON_IsNull(region_name) ? strdup(region_name->valuestring) : NULL,
        city && !cJSON_IsNull(city) ? strdup(city->valuestring) : NULL,
        zip_code && !cJSON_IsNull(zip_code) ? strdup(zip_code->valuestring) : NULL,
        time_zone && !cJSON_IsNull(time_zone) ? strdup(time_zone->valuestring) : NULL,
        latitude ? latitude->valuedouble : 0,
        longitude ? longitude->valuedouble : 0,
        metro_code ? metro_code->valuedouble : 0
        );

    return geolocation_local_var;
end:
    return NULL;

}
