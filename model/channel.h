/*
 * channel.h
 *
 * 
 */

#ifndef _channel_H_
#define _channel_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct channel_t channel_t;

#include "channel_country.h"
#include "channel_place.h"



typedef struct channel_t {
    char *id; // string
    char *title; // string
    char *url; // string
    char *website; // string
    int secure; //boolean
    struct channel_place_t *place; //model
    struct channel_country_t *country; //model

} channel_t;

channel_t *channel_create(
    char *id,
    char *title,
    char *url,
    char *website,
    int secure,
    channel_place_t *place,
    channel_country_t *country
);

void channel_free(channel_t *channel);

channel_t *channel_parseFromJSON(cJSON *channelJSON);

cJSON *channel_convertToJSON(channel_t *channel);

#endif /* _channel_H_ */

