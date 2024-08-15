#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "PlacesAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)


// Get a place's registered radio stations
//
_ara_content_page__place_id__channels_get_200_response_t*
PlacesAPI_araContentPagePlaceIdChannelsGet(apiClient_t *apiClient, char *placeId)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/ara/content/page/{placeId}/channels")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/ara/content/page/{placeId}/channels");


    // Path Params
    long sizeOfPathParams_placeId = strlen(placeId)+3 + strlen("{ placeId }");
    if(placeId == NULL) {
        goto end;
    }
    char* localVarToReplace_placeId = malloc(sizeOfPathParams_placeId);
    sprintf(localVarToReplace_placeId, "{%s}", "placeId");

    localVarPath = strReplace(localVarPath, localVarToReplace_placeId, placeId);


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
    cJSON *PlacesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    _ara_content_page__place_id__channels_get_200_response_t *elementToReturn = _ara_content_page__place_id__channels_get_200_response_parseFromJSON(PlacesAPIlocalVarJSON);
    cJSON_Delete(PlacesAPIlocalVarJSON);
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
    free(localVarToReplace_placeId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get a place's details
//
_ara_content_page__place_id__get_200_response_t*
PlacesAPI_araContentPagePlaceIdGet(apiClient_t *apiClient, char *placeId)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/ara/content/page/{placeId}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/ara/content/page/{placeId}");


    // Path Params
    long sizeOfPathParams_placeId = strlen(placeId)+3 + strlen("{ placeId }");
    if(placeId == NULL) {
        goto end;
    }
    char* localVarToReplace_placeId = malloc(sizeOfPathParams_placeId);
    sprintf(localVarToReplace_placeId, "{%s}", "placeId");

    localVarPath = strReplace(localVarPath, localVarToReplace_placeId, placeId);


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
    cJSON *PlacesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    _ara_content_page__place_id__get_200_response_t *elementToReturn = _ara_content_page__place_id__get_200_response_parseFromJSON(PlacesAPIlocalVarJSON);
    cJSON_Delete(PlacesAPIlocalVarJSON);
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
    free(localVarToReplace_placeId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get places with registered radio stations
//
_ara_content_places_get_200_response_t*
PlacesAPI_araContentPlacesGet(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/ara/content/places")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/ara/content/places");



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
    cJSON *PlacesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    _ara_content_places_get_200_response_t *elementToReturn = _ara_content_places_get_200_response_parseFromJSON(PlacesAPIlocalVarJSON);
    cJSON_Delete(PlacesAPIlocalVarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

