/*
 * channel_refs.h
 *
 * 
 */

#ifndef _channel_refs_H_
#define _channel_refs_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct channel_refs_t channel_refs_t;

#include "channel_ref.h"



typedef struct channel_refs_t {
    char *items_type; // string
    char *type; // string
    list_t *items; //nonprimitive container

} channel_refs_t;

channel_refs_t *channel_refs_create(
    char *items_type,
    char *type,
    list_t *items
);

void channel_refs_free(channel_refs_t *channel_refs);

channel_refs_t *channel_refs_parseFromJSON(cJSON *channel_refsJSON);

cJSON *channel_refs_convertToJSON(channel_refs_t *channel_refs);

#endif /* _channel_refs_H_ */

