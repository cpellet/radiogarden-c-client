#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "versioned.h"



versioned_t *versioned_create(
    int api_version,
    char *version
    ) {
    versioned_t *versioned_local_var = malloc(sizeof(versioned_t));
    if (!versioned_local_var) {
        return NULL;
    }
    versioned_local_var->api_version = api_version;
    versioned_local_var->version = version;

    return versioned_local_var;
}


void versioned_free(versioned_t *versioned) {
    if(NULL == versioned){
        return ;
    }
    listEntry_t *listEntry;
    if (versioned->version) {
        free(versioned->version);
        versioned->version = NULL;
    }
    free(versioned);
}

cJSON *versioned_convertToJSON(versioned_t *versioned) {
    cJSON *item = cJSON_CreateObject();

    // versioned->api_version
    if(versioned->api_version) {
    if(cJSON_AddNumberToObject(item, "apiVersion", versioned->api_version) == NULL) {
    goto fail; //Numeric
    }
    }


    // versioned->version
    if(versioned->version) {
    if(cJSON_AddStringToObject(item, "version", versioned->version) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

versioned_t *versioned_parseFromJSON(cJSON *versionedJSON){

    versioned_t *versioned_local_var = NULL;

    // versioned->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(versionedJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsNumber(api_version))
    {
    goto end; //Numeric
    }
    }

    // versioned->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(versionedJSON, "version");
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }


    versioned_local_var = versioned_create (
        api_version ? api_version->valuedouble : 0,
        version && !cJSON_IsNull(version) ? strdup(version->valuestring) : NULL
        );

    return versioned_local_var;
end:
    return NULL;

}
