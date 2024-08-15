/*
 * country_popular_stations_items_inner.h
 *
 * 
 */

#ifndef _country_popular_stations_items_inner_H_
#define _country_popular_stations_items_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct country_popular_stations_items_inner_t country_popular_stations_items_inner_t;

#include "channel_place_ref.h"
#include "more_ref.h"
#include "more_ref_page.h"



typedef struct country_popular_stations_items_inner_t {
    char *title; // string
    char *href; // string
    char *subtitle; // string
    char *map; // string
    char *type; // string
    char *right_accessory; // string
    struct more_ref_page_t *page; //model

} country_popular_stations_items_inner_t;

country_popular_stations_items_inner_t *country_popular_stations_items_inner_create(
    char *title,
    char *href,
    char *subtitle,
    char *map,
    char *type,
    char *right_accessory,
    more_ref_page_t *page
);

void country_popular_stations_items_inner_free(country_popular_stations_items_inner_t *country_popular_stations_items_inner);

country_popular_stations_items_inner_t *country_popular_stations_items_inner_parseFromJSON(cJSON *country_popular_stations_items_innerJSON);

cJSON *country_popular_stations_items_inner_convertToJSON(country_popular_stations_items_inner_t *country_popular_stations_items_inner);

#endif /* _country_popular_stations_items_inner_H_ */

