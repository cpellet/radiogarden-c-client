# GeoAPI

All URIs are relative to *http://radio.garden/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**GeoAPI_geoGet**](GeoAPI.md#GeoAPI_geoGet) | **GET** /geo | Get the client&#39;s geolocation


# **GeoAPI_geoGet**
```c
// Get the client's geolocation
//
geolocation_t* GeoAPI_geoGet(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[geolocation_t](geolocation.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

