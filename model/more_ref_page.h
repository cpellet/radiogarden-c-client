/*
 * more_ref_page.h
 *
 * 
 */

#ifndef _more_ref_page_H_
#define _more_ref_page_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct more_ref_page_t more_ref_page_t;

#include "country_ref.h"
#include "place_ref.h"



typedef struct more_ref_page_t {
    char *title; // string
    char *subtitle; // string
    char *url; // string
    list_t *map; //primitive container
    int count; //numeric
    int utc_offset; //numeric

} more_ref_page_t;

more_ref_page_t *more_ref_page_create(
    char *title,
    char *subtitle,
    char *url,
    list_t *map,
    int count,
    int utc_offset
);

void more_ref_page_free(more_ref_page_t *more_ref_page);

more_ref_page_t *more_ref_page_parseFromJSON(cJSON *more_ref_pageJSON);

cJSON *more_ref_page_convertToJSON(more_ref_page_t *more_ref_page);

#endif /* _more_ref_page_H_ */

