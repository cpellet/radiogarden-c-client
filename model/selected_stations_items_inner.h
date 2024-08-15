/*
 * selected_stations_items_inner.h
 *
 * 
 */

#ifndef _selected_stations_items_inner_H_
#define _selected_stations_items_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct selected_stations_items_inner_t selected_stations_items_inner_t;

#include "channel_ref.h"
#include "more_ref.h"
#include "more_ref_page.h"



typedef struct selected_stations_items_inner_t {
    char *title; // string
    char *href; // string
    char *type; // string
    char *right_accessory; // string
    struct more_ref_page_t *page; //model

} selected_stations_items_inner_t;

selected_stations_items_inner_t *selected_stations_items_inner_create(
    char *title,
    char *href,
    char *type,
    char *right_accessory,
    more_ref_page_t *page
);

void selected_stations_items_inner_free(selected_stations_items_inner_t *selected_stations_items_inner);

selected_stations_items_inner_t *selected_stations_items_inner_parseFromJSON(cJSON *selected_stations_items_innerJSON);

cJSON *selected_stations_items_inner_convertToJSON(selected_stations_items_inner_t *selected_stations_items_inner);

#endif /* _selected_stations_items_inner_H_ */

