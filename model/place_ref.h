/*
 * place_ref.h
 *
 * 
 */

#ifndef _place_ref_H_
#define _place_ref_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct place_ref_t place_ref_t;




typedef struct place_ref_t {
    char *title; // string
    char *subtitle; // string
    char *url; // string
    char *map; // string
    int count; //numeric
    int utc_offset; //numeric

} place_ref_t;

place_ref_t *place_ref_create(
    char *title,
    char *subtitle,
    char *url,
    char *map,
    int count,
    int utc_offset
);

void place_ref_free(place_ref_t *place_ref);

place_ref_t *place_ref_parseFromJSON(cJSON *place_refJSON);

cJSON *place_ref_convertToJSON(place_ref_t *place_ref);

#endif /* _place_ref_H_ */

