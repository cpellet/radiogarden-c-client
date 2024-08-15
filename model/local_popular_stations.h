/*
 * local_popular_stations.h
 *
 * 
 */

#ifndef _local_popular_stations_H_
#define _local_popular_stations_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct local_popular_stations_t local_popular_stations_t;

#include "channel_ref.h"
#include "place_ref.h"



typedef struct local_popular_stations_t {
    struct place_ref_t *action_page; //model
    char *action_text; // string
    char *title; // string
    char *type; // string
    char *items_type; // string
    list_t *items; //nonprimitive container

} local_popular_stations_t;

local_popular_stations_t *local_popular_stations_create(
    place_ref_t *action_page,
    char *action_text,
    char *title,
    char *type,
    char *items_type,
    list_t *items
);

void local_popular_stations_free(local_popular_stations_t *local_popular_stations);

local_popular_stations_t *local_popular_stations_parseFromJSON(cJSON *local_popular_stationsJSON);

cJSON *local_popular_stations_convertToJSON(local_popular_stations_t *local_popular_stations);

#endif /* _local_popular_stations_H_ */

