#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/_ara_content_page__place_id__channels_get_200_response.h"
#include "../model/_ara_content_page__place_id__get_200_response.h"
#include "../model/_ara_content_places_get_200_response.h"


// Get a place's registered radio stations
//
_ara_content_page__place_id__channels_get_200_response_t*
PlacesAPI_araContentPagePlaceIdChannelsGet(apiClient_t *apiClient, char *placeId);


// Get a place's details
//
_ara_content_page__place_id__get_200_response_t*
PlacesAPI_araContentPagePlaceIdGet(apiClient_t *apiClient, char *placeId);


// Get places with registered radio stations
//
_ara_content_places_get_200_response_t*
PlacesAPI_araContentPlacesGet(apiClient_t *apiClient);


