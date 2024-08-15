# PlacesAPI

All URIs are relative to *http://radio.garden/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**PlacesAPI_araContentPagePlaceIdChannelsGet**](PlacesAPI.md#PlacesAPI_araContentPagePlaceIdChannelsGet) | **GET** /ara/content/page/{placeId}/channels | Get a place&#39;s registered radio stations
[**PlacesAPI_araContentPagePlaceIdGet**](PlacesAPI.md#PlacesAPI_araContentPagePlaceIdGet) | **GET** /ara/content/page/{placeId} | Get a place&#39;s details
[**PlacesAPI_araContentPlacesGet**](PlacesAPI.md#PlacesAPI_araContentPlacesGet) | **GET** /ara/content/places | Get places with registered radio stations


# **PlacesAPI_araContentPagePlaceIdChannelsGet**
```c
// Get a place's registered radio stations
//
_ara_content_page__place_id__channels_get_200_response_t* PlacesAPI_araContentPagePlaceIdChannelsGet(apiClient_t *apiClient, char *placeId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**placeId** | **char \*** | ID of place to use | 

### Return type

[_ara_content_page__place_id__channels_get_200_response_t](_ara_content_page__place_id__channels_get_200_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PlacesAPI_araContentPagePlaceIdGet**
```c
// Get a place's details
//
_ara_content_page__place_id__get_200_response_t* PlacesAPI_araContentPagePlaceIdGet(apiClient_t *apiClient, char *placeId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**placeId** | **char \*** | ID of place to use | 

### Return type

[_ara_content_page__place_id__get_200_response_t](_ara_content_page__place_id__get_200_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **PlacesAPI_araContentPlacesGet**
```c
// Get places with registered radio stations
//
_ara_content_places_get_200_response_t* PlacesAPI_araContentPlacesGet(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[_ara_content_places_get_200_response_t](_ara_content_places_get_200_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

