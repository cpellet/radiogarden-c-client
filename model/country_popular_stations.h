/*
 * country_popular_stations.h
 *
 * 
 */

#ifndef _country_popular_stations_H_
#define _country_popular_stations_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct country_popular_stations_t country_popular_stations_t;

#include "country_popular_stations_items_inner.h"



typedef struct country_popular_stations_t {
    char *title; // string
    char *type; // string
    char *items_type; // string
    list_t *items; //nonprimitive container

} country_popular_stations_t;

country_popular_stations_t *country_popular_stations_create(
    char *title,
    char *type,
    char *items_type,
    list_t *items
);

void country_popular_stations_free(country_popular_stations_t *country_popular_stations);

country_popular_stations_t *country_popular_stations_parseFromJSON(cJSON *country_popular_stationsJSON);

cJSON *country_popular_stations_convertToJSON(country_popular_stations_t *country_popular_stations);

#endif /* _country_popular_stations_H_ */

