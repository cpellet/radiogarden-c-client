#ifndef country_popular_stations_TEST
#define country_popular_stations_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define country_popular_stations_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/country_popular_stations.h"
country_popular_stations_t* instantiate_country_popular_stations(int include_optional);



country_popular_stations_t* instantiate_country_popular_stations(int include_optional) {
  country_popular_stations_t* country_popular_stations = NULL;
  if (include_optional) {
    country_popular_stations = country_popular_stations_create(
      "Popular in United States",
      "list",
      "channel",
      list_createList()
    );
  } else {
    country_popular_stations = country_popular_stations_create(
      "Popular in United States",
      "list",
      "channel",
      list_createList()
    );
  }

  return country_popular_stations;
}


#ifdef country_popular_stations_MAIN

void test_country_popular_stations(int include_optional) {
    country_popular_stations_t* country_popular_stations_1 = instantiate_country_popular_stations(include_optional);

	cJSON* jsoncountry_popular_stations_1 = country_popular_stations_convertToJSON(country_popular_stations_1);
	printf("country_popular_stations :\n%s\n", cJSON_Print(jsoncountry_popular_stations_1));
	country_popular_stations_t* country_popular_stations_2 = country_popular_stations_parseFromJSON(jsoncountry_popular_stations_1);
	cJSON* jsoncountry_popular_stations_2 = country_popular_stations_convertToJSON(country_popular_stations_2);
	printf("repeating country_popular_stations:\n%s\n", cJSON_Print(jsoncountry_popular_stations_2));
}

int main() {
  test_country_popular_stations(1);
  test_country_popular_stations(0);

  printf("Hello world \n");
  return 0;
}

#endif // country_popular_stations_MAIN
#endif // country_popular_stations_TEST
