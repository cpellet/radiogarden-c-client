/*
 * left_page_ref.h
 *
 * 
 */

#ifndef _left_page_ref_H_
#define _left_page_ref_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct left_page_ref_t left_page_ref_t;

#include "place_ref.h"



typedef struct left_page_ref_t {
    char *title; // string
    char *left_accessory; // string
    int left_accessory_count; //numeric
    struct place_ref_t *page; //model

} left_page_ref_t;

left_page_ref_t *left_page_ref_create(
    char *title,
    char *left_accessory,
    int left_accessory_count,
    place_ref_t *page
);

void left_page_ref_free(left_page_ref_t *left_page_ref);

left_page_ref_t *left_page_ref_parseFromJSON(cJSON *left_page_refJSON);

cJSON *left_page_ref_convertToJSON(left_page_ref_t *left_page_ref);

#endif /* _left_page_ref_H_ */

