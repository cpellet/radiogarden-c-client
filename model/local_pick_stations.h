/*
 * local_pick_stations.h
 *
 * 
 */

#ifndef _local_pick_stations_H_
#define _local_pick_stations_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct local_pick_stations_t local_pick_stations_t;

#include "channel_place_ref.h"



typedef struct local_pick_stations_t {
    char *title; // string
    char *type; // string
    char *items_type; // string
    list_t *items; //nonprimitive container

} local_pick_stations_t;

local_pick_stations_t *local_pick_stations_create(
    char *title,
    char *type,
    char *items_type,
    list_t *items
);

void local_pick_stations_free(local_pick_stations_t *local_pick_stations);

local_pick_stations_t *local_pick_stations_parseFromJSON(cJSON *local_pick_stationsJSON);

cJSON *local_pick_stations_convertToJSON(local_pick_stations_t *local_pick_stations);

#endif /* _local_pick_stations_H_ */

