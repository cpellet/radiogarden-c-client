/*
 * channel_country.h
 *
 * 
 */

#ifndef _channel_country_H_
#define _channel_country_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct channel_country_t channel_country_t;




typedef struct channel_country_t {
    char *id; // string
    char *title; // string

} channel_country_t;

channel_country_t *channel_country_create(
    char *id,
    char *title
);

void channel_country_free(channel_country_t *channel_country);

channel_country_t *channel_country_parseFromJSON(cJSON *channel_countryJSON);

cJSON *channel_country_convertToJSON(channel_country_t *channel_country);

#endif /* _channel_country_H_ */

