/*
 * place.h
 *
 * 
 */

#ifndef _place_H_
#define _place_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct place_t place_t;




typedef struct place_t {
    char *id; // string
    list_t *geo; //primitive container
    char *url; // string
    int size; //numeric
    int boost; //boolean
    char *title; // string
    char *country; // string

} place_t;

place_t *place_create(
    char *id,
    list_t *geo,
    char *url,
    int size,
    int boost,
    char *title,
    char *country
);

void place_free(place_t *place);

place_t *place_parseFromJSON(cJSON *placeJSON);

cJSON *place_convertToJSON(place_t *place);

#endif /* _place_H_ */

