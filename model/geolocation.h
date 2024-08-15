/*
 * geolocation.h
 *
 * 
 */

#ifndef _geolocation_H_
#define _geolocation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct geolocation_t geolocation_t;




typedef struct geolocation_t {
    char *ip; // string
    char *country_code; // string
    char *country_name; // string
    char *region_code; // string
    char *region_name; // string
    char *city; // string
    char *zip_code; // string
    char *time_zone; // string
    float latitude; //numeric
    float longitude; //numeric
    int metro_code; //numeric

} geolocation_t;

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
);

void geolocation_free(geolocation_t *geolocation);

geolocation_t *geolocation_parseFromJSON(cJSON *geolocationJSON);

cJSON *geolocation_convertToJSON(geolocation_t *geolocation);

#endif /* _geolocation_H_ */

