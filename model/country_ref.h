/*
 * country_ref.h
 *
 * 
 */

#ifndef _country_ref_H_
#define _country_ref_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct country_ref_t country_ref_t;




typedef struct country_ref_t {
    char *title; // string
    char *url; // string
    list_t *map; //primitive container

} country_ref_t;

country_ref_t *country_ref_create(
    char *title,
    char *url,
    list_t *map
);

void country_ref_free(country_ref_t *country_ref);

country_ref_t *country_ref_parseFromJSON(cJSON *country_refJSON);

cJSON *country_ref_convertToJSON(country_ref_t *country_ref);

#endif /* _country_ref_H_ */

