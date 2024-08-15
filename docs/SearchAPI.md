# SearchAPI

All URIs are relative to *http://radio.garden/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**SearchAPI_searchGet**](SearchAPI.md#SearchAPI_searchGet) | **GET** /search | Search for countries, places, and radio stations


# **SearchAPI_searchGet**
```c
// Search for countries, places, and radio stations
//
_search_get_200_response_t* SearchAPI_searchGet(apiClient_t *apiClient, char *q);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**q** | **char \*** | Search query | 

### Return type

[_search_get_200_response_t](_search_get_200_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

