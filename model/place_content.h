/*
 * place_content.h
 *
 * 
 */

#ifndef _place_content_H_
#define _place_content_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct place_content_t place_content_t;

#include "place_content_content_inner.h"



typedef struct place_content_t {
    list_t *content; //nonprimitive container

} place_content_t;

place_content_t *place_content_create(
    list_t *content
);

void place_content_free(place_content_t *place_content);

place_content_t *place_content_parseFromJSON(cJSON *place_contentJSON);

cJSON *place_content_convertToJSON(place_content_t *place_content);

#endif /* _place_content_H_ */

