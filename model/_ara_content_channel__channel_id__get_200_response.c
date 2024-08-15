#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_ara_content_channel__channel_id__get_200_response.h"



_ara_content_channel__channel_id__get_200_response_t *_ara_content_channel__channel_id__get_200_response_create(
    int api_version,
    char *version,
    channel_t *data
    ) {
    _ara_content_channel__channel_id__get_200_response_t *_ara_content_channel__channel_id__get_200_response_local_var = malloc(sizeof(_ara_content_channel__channel_id__get_200_response_t));
    if (!_ara_content_channel__channel_id__get_200_response_local_var) {
        return NULL;
    }
    _ara_content_channel__channel_id__get_200_response_local_var->api_version = api_version;
    _ara_content_channel__channel_id__get_200_response_local_var->version = version;
    _ara_content_channel__channel_id__get_200_response_local_var->data = data;

    return _ara_content_channel__channel_id__get_200_response_local_var;
}


void _ara_content_channel__channel_id__get_200_response_free(_ara_content_channel__channel_id__get_200_response_t *_ara_content_channel__channel_id__get_200_response) {
    if(NULL == _ara_content_channel__channel_id__get_200_response){
        return ;
    }
    listEntry_t *listEntry;
    if (_ara_content_channel__channel_id__get_200_response->version) {
        free(_ara_content_channel__channel_id__get_200_response->version);
        _ara_content_channel__channel_id__get_200_response->version = NULL;
    }
    if (_ara_content_channel__channel_id__get_200_response->data) {
        channel_free(_ara_content_channel__channel_id__get_200_response->data);
        _ara_content_channel__channel_id__get_200_response->data = NULL;
    }
    free(_ara_content_channel__channel_id__get_200_response);
}

cJSON *_ara_content_channel__channel_id__get_200_response_convertToJSON(_ara_content_channel__channel_id__get_200_response_t *_ara_content_channel__channel_id__get_200_response) {
    cJSON *item = cJSON_CreateObject();

    // _ara_content_channel__channel_id__get_200_response->api_version
    if(_ara_content_channel__channel_id__get_200_response->api_version) {
    if(cJSON_AddNumberToObject(item, "apiVersion", _ara_content_channel__channel_id__get_200_response->api_version) == NULL) {
    goto fail; //Numeric
    }
    }


    // _ara_content_channel__channel_id__get_200_response->version
    if(_ara_content_channel__channel_id__get_200_response->version) {
    if(cJSON_AddStringToObject(item, "version", _ara_content_channel__channel_id__get_200_response->version) == NULL) {
    goto fail; //String
    }
    }


    // _ara_content_channel__channel_id__get_200_response->data
    if(_ara_content_channel__channel_id__get_200_response->data) {
    cJSON *data_local_JSON = channel_convertToJSON(_ara_content_channel__channel_id__get_200_response->data);
    if(data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "data", data_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_ara_content_channel__channel_id__get_200_response_t *_ara_content_channel__channel_id__get_200_response_parseFromJSON(cJSON *_ara_content_channel__channel_id__get_200_responseJSON){

    _ara_content_channel__channel_id__get_200_response_t *_ara_content_channel__channel_id__get_200_response_local_var = NULL;

    // define the local variable for _ara_content_channel__channel_id__get_200_response->data
    channel_t *data_local_nonprim = NULL;

    // _ara_content_channel__channel_id__get_200_response->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(_ara_content_channel__channel_id__get_200_responseJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsNumber(api_version))
    {
    goto end; //Numeric
    }
    }

    // _ara_content_channel__channel_id__get_200_response->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(_ara_content_channel__channel_id__get_200_responseJSON, "version");
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }

    // _ara_content_channel__channel_id__get_200_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(_ara_content_channel__channel_id__get_200_responseJSON, "data");
    if (data) { 
    data_local_nonprim = channel_parseFromJSON(data); //nonprimitive
    }


    _ara_content_channel__channel_id__get_200_response_local_var = _ara_content_channel__channel_id__get_200_response_create (
        api_version ? api_version->valuedouble : 0,
        version && !cJSON_IsNull(version) ? strdup(version->valuestring) : NULL,
        data ? data_local_nonprim : NULL
        );

    return _ara_content_channel__channel_id__get_200_response_local_var;
end:
    if (data_local_nonprim) {
        channel_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    return NULL;

}
