/*
 * channel_place.h
 *
 * 
 */

#ifndef _channel_place_H_
#define _channel_place_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct channel_place_t channel_place_t;




typedef struct channel_place_t {
    char *id; // string
    char *title; // string

} channel_place_t;

channel_place_t *channel_place_create(
    char *id,
    char *title
);

void channel_place_free(channel_place_t *channel_place);

channel_place_t *channel_place_parseFromJSON(cJSON *channel_placeJSON);

cJSON *channel_place_convertToJSON(channel_place_t *channel_place);

#endif /* _channel_place_H_ */

