#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ChannelsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)


// Get a radio station's details
//
_ara_content_channel__channel_id__get_200_response_t*
ChannelsAPI_araContentChannelChannelIdGet(apiClient_t *apiClient, char *channelId)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/ara/content/channel/{channelId}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/ara/content/channel/{channelId}");


    // Path Params
    long sizeOfPathParams_channelId = strlen(channelId)+3 + strlen("{ channelId }");
    if(channelId == NULL) {
        goto end;
    }
    char* localVarToReplace_channelId = malloc(sizeOfPathParams_channelId);
    sprintf(localVarToReplace_channelId, "{%s}", "channelId");

    localVarPath = strReplace(localVarPath, localVarToReplace_channelId, channelId);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Successful response");
    //}
    //nonprimitive not container
    cJSON *ChannelsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    _ara_content_channel__channel_id__get_200_response_t *elementToReturn = _ara_content_channel__channel_id__get_200_response_parseFromJSON(ChannelsAPIlocalVarJSON);
    cJSON_Delete(ChannelsAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_channelId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get a radio station's live broadcast stream
//
void
ChannelsAPI_araContentListenChannelIdChannelMp3Get(apiClient_t *apiClient, char *channelId)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/ara/content/listen/{channelId}/channel.mp3")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/ara/content/listen/{channelId}/channel.mp3");


    // Path Params
    long sizeOfPathParams_channelId = strlen(channelId)+3 + strlen("{ channelId }");
    if(channelId == NULL) {
        goto end;
    }
    char* localVarToReplace_channelId = malloc(sizeOfPathParams_channelId);
    sprintf(localVarToReplace_channelId, "{%s}", "channelId");

    localVarPath = strReplace(localVarPath, localVarToReplace_channelId, channelId);


    list_addElement(localVarHeaderType,"text/html"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 302) {
    //    printf("%s\n","Redirect response");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_channelId);

}

// Get a radio station's live broadcast stream
//
void
ChannelsAPI_araContentListenChannelIdChannelMp3Head(apiClient_t *apiClient, char *channelId)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/ara/content/listen/{channelId}/channel.mp3")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/ara/content/listen/{channelId}/channel.mp3");


    // Path Params
    long sizeOfPathParams_channelId = strlen(channelId)+3 + strlen("{ channelId }");
    if(channelId == NULL) {
        goto end;
    }
    char* localVarToReplace_channelId = malloc(sizeOfPathParams_channelId);
    sprintf(localVarToReplace_channelId, "{%s}", "channelId");

    localVarPath = strReplace(localVarPath, localVarToReplace_channelId, channelId);


    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "HEAD");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 302) {
    //    printf("%s\n","Redirect response");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    
    
    free(localVarPath);
    free(localVarToReplace_channelId);

}

