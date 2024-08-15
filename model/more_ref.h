/*
 * more_ref.h
 *
 * 
 */

#ifndef _more_ref_H_
#define _more_ref_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct more_ref_t more_ref_t;

#include "more_ref_page.h"



typedef struct more_ref_t {
    char *title; // string
    char *type; // string
    char *right_accessory; // string
    struct more_ref_page_t *page; //model

} more_ref_t;

more_ref_t *more_ref_create(
    char *title,
    char *type,
    char *right_accessory,
    more_ref_page_t *page
);

void more_ref_free(more_ref_t *more_ref);

more_ref_t *more_ref_parseFromJSON(cJSON *more_refJSON);

cJSON *more_ref_convertToJSON(more_ref_t *more_ref);

#endif /* _more_ref_H_ */

