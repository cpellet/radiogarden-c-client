/*
 * versioned.h
 *
 * 
 */

#ifndef _versioned_H_
#define _versioned_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct versioned_t versioned_t;




typedef struct versioned_t {
    int api_version; //numeric
    char *version; // string

} versioned_t;

versioned_t *versioned_create(
    int api_version,
    char *version
);

void versioned_free(versioned_t *versioned);

versioned_t *versioned_parseFromJSON(cJSON *versionedJSON);

cJSON *versioned_convertToJSON(versioned_t *versioned);

#endif /* _versioned_H_ */

