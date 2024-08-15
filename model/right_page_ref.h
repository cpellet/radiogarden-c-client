/*
 * right_page_ref.h
 *
 * 
 */

#ifndef _right_page_ref_H_
#define _right_page_ref_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct right_page_ref_t right_page_ref_t;

#include "place_ref.h"



typedef struct right_page_ref_t {
    char *title; // string
    char *right_detail; // string
    struct place_ref_t *page; //model

} right_page_ref_t;

right_page_ref_t *right_page_ref_create(
    char *title,
    char *right_detail,
    place_ref_t *page
);

void right_page_ref_free(right_page_ref_t *right_page_ref);

right_page_ref_t *right_page_ref_parseFromJSON(cJSON *right_page_refJSON);

cJSON *right_page_ref_convertToJSON(right_page_ref_t *right_page_ref);

#endif /* _right_page_ref_H_ */

