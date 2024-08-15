/*
 * place_content_content_inner.h
 *
 * 
 */

#ifndef _place_content_content_inner_H_
#define _place_content_content_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct place_content_content_inner_t place_content_content_inner_t;

#include "cities.h"
#include "country_popular_stations.h"
#include "left_page_ref.h"
#include "local_pick_stations.h"
#include "local_popular_stations.h"
#include "nearby_places.h"
#include "place_ref.h"
#include "selected_stations.h"



typedef struct place_content_content_inner_t {
    char *title; // string
    char *type; // string
    char *items_type; // string
    list_t *items; //nonprimitive container
    struct place_ref_t *action_page; //model
    char *action_text; // string
    char *right_accessory; // string

} place_content_content_inner_t;

place_content_content_inner_t *place_content_content_inner_create(
    char *title,
    char *type,
    char *items_type,
    list_t *items,
    place_ref_t *action_page,
    char *action_text,
    char *right_accessory
);

void place_content_content_inner_free(place_content_content_inner_t *place_content_content_inner);

place_content_content_inner_t *place_content_content_inner_parseFromJSON(cJSON *place_content_content_innerJSON);

cJSON *place_content_content_inner_convertToJSON(place_content_content_inner_t *place_content_content_inner);

#endif /* _place_content_content_inner_H_ */

