/*
 * channel_place_ref.h
 *
 * 
 */

#ifndef _channel_place_ref_H_
#define _channel_place_ref_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct channel_place_ref_t channel_place_ref_t;




typedef struct channel_place_ref_t {
    char *title; // string
    char *href; // string
    char *subtitle; // string
    char *map; // string

} channel_place_ref_t;

channel_place_ref_t *channel_place_ref_create(
    char *title,
    char *href,
    char *subtitle,
    char *map
);

void channel_place_ref_free(channel_place_ref_t *channel_place_ref);

channel_place_ref_t *channel_place_ref_parseFromJSON(cJSON *channel_place_refJSON);

cJSON *channel_place_ref_convertToJSON(channel_place_ref_t *channel_place_ref);

#endif /* _channel_place_ref_H_ */

