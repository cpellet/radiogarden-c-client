# ChannelsAPI

All URIs are relative to *http://radio.garden/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ChannelsAPI_araContentChannelChannelIdGet**](ChannelsAPI.md#ChannelsAPI_araContentChannelChannelIdGet) | **GET** /ara/content/channel/{channelId} | Get a radio station&#39;s details
[**ChannelsAPI_araContentListenChannelIdChannelMp3Get**](ChannelsAPI.md#ChannelsAPI_araContentListenChannelIdChannelMp3Get) | **GET** /ara/content/listen/{channelId}/channel.mp3 | Get a radio station&#39;s live broadcast stream
[**ChannelsAPI_araContentListenChannelIdChannelMp3Head**](ChannelsAPI.md#ChannelsAPI_araContentListenChannelIdChannelMp3Head) | **HEAD** /ara/content/listen/{channelId}/channel.mp3 | Get a radio station&#39;s live broadcast stream


# **ChannelsAPI_araContentChannelChannelIdGet**
```c
// Get a radio station's details
//
_ara_content_channel__channel_id__get_200_response_t* ChannelsAPI_araContentChannelChannelIdGet(apiClient_t *apiClient, char *channelId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**channelId** | **char \*** | ID of radio station to use | 

### Return type

[_ara_content_channel__channel_id__get_200_response_t](_ara_content_channel__channel_id__get_200_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ChannelsAPI_araContentListenChannelIdChannelMp3Get**
```c
// Get a radio station's live broadcast stream
//
void ChannelsAPI_araContentListenChannelIdChannelMp3Get(apiClient_t *apiClient, char *channelId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**channelId** | **char \*** | ID of radio station to use | 

### Return type

void

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: text/html

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ChannelsAPI_araContentListenChannelIdChannelMp3Head**
```c
// Get a radio station's live broadcast stream
//
void ChannelsAPI_araContentListenChannelIdChannelMp3Head(apiClient_t *apiClient, char *channelId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**channelId** | **char \*** | ID of radio station to use | 

### Return type

void

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

