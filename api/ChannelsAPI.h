#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/_ara_content_channel__channel_id__get_200_response.h"


// Get a radio station's details
//
_ara_content_channel__channel_id__get_200_response_t*
ChannelsAPI_araContentChannelChannelIdGet(apiClient_t *apiClient, char *channelId);


// Get a radio station's live broadcast stream
//
void
ChannelsAPI_araContentListenChannelIdChannelMp3Get(apiClient_t *apiClient, char *channelId);


// Get a radio station's live broadcast stream
//
void
ChannelsAPI_araContentListenChannelIdChannelMp3Head(apiClient_t *apiClient, char *channelId);


