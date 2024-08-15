/*
 * channel_ref.h
 *
 * 
 */

#ifndef _channel_ref_H_
#define _channel_ref_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct channel_ref_t channel_ref_t;




typedef struct channel_ref_t {
    char *title; // string
    char *href; // string

} channel_ref_t;

channel_ref_t *channel_ref_create(
    char *title,
    char *href
);

void channel_ref_free(channel_ref_t *channel_ref);

channel_ref_t *channel_ref_parseFromJSON(cJSON *channel_refJSON);

cJSON *channel_ref_convertToJSON(channel_ref_t *channel_ref);

#endif /* _channel_ref_H_ */

