/*
 * cities.h
 *
 * 
 */

#ifndef _cities_H_
#define _cities_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cities_t cities_t;

#include "left_page_ref.h"



typedef struct cities_t {
    char *title; // string
    char *type; // string
    char *right_accessory; // string
    list_t *items; //nonprimitive container

} cities_t;

cities_t *cities_create(
    char *title,
    char *type,
    char *right_accessory,
    list_t *items
);

void cities_free(cities_t *cities);

cities_t *cities_parseFromJSON(cJSON *citiesJSON);

cJSON *cities_convertToJSON(cities_t *cities);

#endif /* _cities_H_ */

