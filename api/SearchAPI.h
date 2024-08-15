#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/_search_get_200_response.h"


// Search for countries, places, and radio stations
//
_search_get_200_response_t*
SearchAPI_searchGet(apiClient_t *apiClient, char *q);


