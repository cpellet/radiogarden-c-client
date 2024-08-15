/*
 * selected_stations.h
 *
 * 
 */

#ifndef _selected_stations_H_
#define _selected_stations_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct selected_stations_t selected_stations_t;

#include "selected_stations_items_inner.h"



typedef struct selected_stations_t {
    char *title; // string
    char *type; // string
    char *items_type; // string
    list_t *items; //nonprimitive container

} selected_stations_t;

selected_stations_t *selected_stations_create(
    char *title,
    char *type,
    char *items_type,
    list_t *items
);

void selected_stations_free(selected_stations_t *selected_stations);

selected_stations_t *selected_stations_parseFromJSON(cJSON *selected_stationsJSON);

cJSON *selected_stations_convertToJSON(selected_stations_t *selected_stations);

#endif /* _selected_stations_H_ */

