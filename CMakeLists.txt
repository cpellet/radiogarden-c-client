cmake_minimum_required (VERSION 2.6...3.10.2)
project (CGenerator)

cmake_policy(SET CMP0063 NEW)

set(CMAKE_C_VISIBILITY_PRESET default)
set(CMAKE_CXX_VISIBILITY_PRESET default)
set(CMAKE_VISIBILITY_INLINES_HIDDEN OFF)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

find_package(OpenSSL)

if (OPENSSL_FOUND)
    message (STATUS "OPENSSL found")

    set(CMAKE_C_FLAGS "-DOPENSSL")
    if(CMAKE_VERSION VERSION_LESS 3.4)
        include_directories(${OPENSSL_INCLUDE_DIR})
        include_directories(${OPENSSL_INCLUDE_DIRS})
        link_directories(${OPENSSL_LIBRARIES})
    endif()

    message(STATUS "Using OpenSSL ${OPENSSL_VERSION}")
else()
    message (STATUS "OpenSSL Not found.")
endif()

set(pkgName "radio_garden")

# this default version can be overridden in PreTarget.cmake
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 1)

if( (DEFINED CURL_INCLUDE_DIR) AND (DEFINED CURL_LIBRARIES))
    include_directories(${CURL_INCLUDE_DIR})
    set(PLATFORM_LIBRARIES ${PLATFORM_LIBRARIES} ${CURL_LIBRARIES} )
else()
    find_package(CURL 7.58.0 REQUIRED)
    if(CURL_FOUND)
        include_directories(${CURL_INCLUDE_DIR})
        set(PLATFORM_LIBRARIES ${PLATFORM_LIBRARIES} ${CURL_LIBRARIES} )
    else(CURL_FOUND)
        message(FATAL_ERROR "Could not find the CURL library and development files.")
    endif()
endif()

set(SRCS
    src/list.c
    src/apiKey.c
    src/apiClient.c
    src/binary.c
    external/cJSON.c
    model/object.c
    model/_ara_content_channel__channel_id__get_200_response.c
    model/_ara_content_page__place_id__channels_get_200_response.c
    model/_ara_content_page__place_id__channels_get_200_response_all_of_data.c
    model/_ara_content_page__place_id__get_200_response.c
    model/_ara_content_page__place_id__get_200_response_all_of_data.c
    model/_ara_content_places_get_200_response.c
    model/_ara_content_places_get_200_response_all_of_data.c
    model/_search_get_200_response.c
    model/channel.c
    model/channel_country.c
    model/channel_place.c
    model/channel_place_ref.c
    model/channel_ref.c
    model/channel_refs.c
    model/cities.c
    model/country_popular_stations.c
    model/country_popular_stations_items_inner.c
    model/country_ref.c
    model/geolocation.c
    model/left_page_ref.c
    model/local_pick_stations.c
    model/local_popular_stations.c
    model/more_ref.c
    model/more_ref_page.c
    model/nearby_places.c
    model/place.c
    model/place_content.c
    model/place_content_content_inner.c
    model/place_ref.c
    model/right_page_ref.c
    model/search_result.c
    model/search_result__source.c
    model/search_results.c
    model/search_results_hits.c
    model/selected_stations.c
    model/selected_stations_items_inner.c
    model/versioned.c
    api/ChannelsAPI.c
    api/GeoAPI.c
    api/PlacesAPI.c
    api/SearchAPI.c

)

set(HDRS
    include/apiClient.h
    include/list.h
    include/binary.h
    include/keyValuePair.h
    external/cJSON.h
    model/object.h
    model/_ara_content_channel__channel_id__get_200_response.h
    model/_ara_content_page__place_id__channels_get_200_response.h
    model/_ara_content_page__place_id__channels_get_200_response_all_of_data.h
    model/_ara_content_page__place_id__get_200_response.h
    model/_ara_content_page__place_id__get_200_response_all_of_data.h
    model/_ara_content_places_get_200_response.h
    model/_ara_content_places_get_200_response_all_of_data.h
    model/_search_get_200_response.h
    model/channel.h
    model/channel_country.h
    model/channel_place.h
    model/channel_place_ref.h
    model/channel_ref.h
    model/channel_refs.h
    model/cities.h
    model/country_popular_stations.h
    model/country_popular_stations_items_inner.h
    model/country_ref.h
    model/geolocation.h
    model/left_page_ref.h
    model/local_pick_stations.h
    model/local_popular_stations.h
    model/more_ref.h
    model/more_ref_page.h
    model/nearby_places.h
    model/place.h
    model/place_content.h
    model/place_content_content_inner.h
    model/place_ref.h
    model/right_page_ref.h
    model/search_result.h
    model/search_result__source.h
    model/search_results.h
    model/search_results_hits.h
    model/selected_stations.h
    model/selected_stations_items_inner.h
    model/versioned.h
    api/ChannelsAPI.h
    api/GeoAPI.h
    api/PlacesAPI.h
    api/SearchAPI.h

)

include(PreTarget.cmake OPTIONAL)

set(PROJECT_VERSION_STRING "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# Add library with project file with project name as library name
add_library(${pkgName} ${SRCS} ${HDRS})
# Link dependent libraries
if(NOT CMAKE_VERSION VERSION_LESS 3.4)
    target_link_libraries(${pkgName} PRIVATE OpenSSL::SSL OpenSSL::Crypto)
endif()
target_link_libraries(${pkgName} PUBLIC ${CURL_LIBRARIES} )
target_include_directories(
    ${pkgName} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

include(PostTarget.cmake OPTIONAL)

# installation of libraries, headers, and config files
if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in)
    install(TARGETS ${pkgName} DESTINATION lib)
else()
    include(GNUInstallDirs)
    install(TARGETS ${pkgName} DESTINATION lib EXPORT ${pkgName}Targets)

    foreach(HDR_FILE ${HDRS})
        get_filename_component(HDR_DIRECTORY ${HDR_FILE} DIRECTORY)
        get_filename_component(ABSOLUTE_HDR_DIRECTORY ${HDR_DIRECTORY} ABSOLUTE)
        file(RELATIVE_PATH RELATIVE_HDR_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${ABSOLUTE_HDR_DIRECTORY})
        install(FILES ${HDR_FILE} DESTINATION include/${pkgName}/${RELATIVE_HDR_PATH})
    endforeach()

    include(CMakePackageConfigHelpers)
    write_basic_package_version_file(
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}ConfigVersion.cmake"
            VERSION "${PROJECT_VERSION_STRING}"
            COMPATIBILITY AnyNewerVersion
    )

    export(EXPORT ${pkgName}Targets
            FILE "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Targets.cmake"
            NAMESPACE ${pkgName}::
            )

    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Config.cmake"
            @ONLY
            )

    set(ConfigPackageLocation lib/cmake/${pkgName})
    install(EXPORT ${pkgName}Targets
            FILE
            ${pkgName}Targets.cmake
            NAMESPACE
            ${pkgName}::
            DESTINATION
            ${ConfigPackageLocation}
            )
    install(
            FILES
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Config.cmake"
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}ConfigVersion.cmake"
            DESTINATION
            ${ConfigPackageLocation}
    )
endif()

# make installation packages
include(Packing.cmake OPTIONAL)

# Setting file variables to null
set(SRCS "")
set(HDRS "")


## This section shows how to use the above compiled library to compile the source files
## set source files
#set(SRCS
#    unit-tests/manual-ChannelsAPI.c
#    unit-tests/manual-GeoAPI.c
#    unit-tests/manual-PlacesAPI.c
#    unit-tests/manual-SearchAPI.c
#)

##set header files
#set(HDRS
#)

## loop over all files in SRCS variable
#foreach(SOURCE_FILE ${SRCS})
#    # Get only the file name from the file as add_executable does not support executable with slash("/")
#    get_filename_component(FILE_NAME_ONLY ${SOURCE_FILE} NAME_WE)
#    # Remove .c from the file name and set it as executable name
#    string( REPLACE ".c" "" EXECUTABLE_FILE ${FILE_NAME_ONLY})
#    # Add executable for every source file in  SRCS
#    add_executable(unit-${EXECUTABLE_FILE} ${SOURCE_FILE})
#    # Link above created library to executable and dependent library curl
#    target_link_libraries(unit-${EXECUTABLE_FILE} ${CURL_LIBRARIES} ${pkgName} )
#endforeach(SOURCE_FILE ${SRCS})
