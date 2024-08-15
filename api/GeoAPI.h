#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/geolocation.h"


// Get the client's geolocation
//
geolocation_t*
GeoAPI_geoGet(apiClient_t *apiClient);


