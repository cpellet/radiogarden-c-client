/*
 * nearby_places.h
 *
 * 
 */

#ifndef _nearby_places_H_
#define _nearby_places_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct nearby_places_t nearby_places_t;

#include "right_page_ref.h"



typedef struct nearby_places_t {
    char *title; // string
    char *type; // string
    char *right_accessory; // string
    list_t *items; //nonprimitive container

} nearby_places_t;

nearby_places_t *nearby_places_create(
    char *title,
    char *type,
    char *right_accessory,
    list_t *items
);

void nearby_places_free(nearby_places_t *nearby_places);

nearby_places_t *nearby_places_parseFromJSON(cJSON *nearby_placesJSON);

cJSON *nearby_places_convertToJSON(nearby_places_t *nearby_places);

#endif /* _nearby_places_H_ */

