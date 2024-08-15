#ifndef country_popular_stations_items_inner_TEST
#define country_popular_stations_items_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define country_popular_stations_items_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/country_popular_stations_items_inner.h"
country_popular_stations_items_inner_t* instantiate_country_popular_stations_items_inner(int include_optional);

#include "test_more_ref_page.c"


country_popular_stations_items_inner_t* instantiate_country_popular_stations_items_inner(int include_optional) {
  country_popular_stations_items_inner_t* country_popular_stations_items_inner = NULL;
  if (include_optional) {
    country_popular_stations_items_inner = country_popular_stations_items_inner_create(
      "View all 21 stations",
      "/listen/kutx-98-9/vbFsCngB",
      "Georgetown TX",
      "BQP3R6jj",
      "more",
      "chevron-right",
      null
    );
  } else {
    country_popular_stations_items_inner = country_popular_stations_items_inner_create(
      "View all 21 stations",
      "/listen/kutx-98-9/vbFsCngB",
      "Georgetown TX",
      "BQP3R6jj",
      "more",
      "chevron-right",
      null
    );
  }

  return country_popular_stations_items_inner;
}


#ifdef country_popular_stations_items_inner_MAIN

void test_country_popular_stations_items_inner(int include_optional) {
    country_popular_stations_items_inner_t* country_popular_stations_items_inner_1 = instantiate_country_popular_stations_items_inner(include_optional);

	cJSON* jsoncountry_popular_stations_items_inner_1 = country_popular_stations_items_inner_convertToJSON(country_popular_stations_items_inner_1);
	printf("country_popular_stations_items_inner :\n%s\n", cJSON_Print(jsoncountry_popular_stations_items_inner_1));
	country_popular_stations_items_inner_t* country_popular_stations_items_inner_2 = country_popular_stations_items_inner_parseFromJSON(jsoncountry_popular_stations_items_inner_1);
	cJSON* jsoncountry_popular_stations_items_inner_2 = country_popular_stations_items_inner_convertToJSON(country_popular_stations_items_inner_2);
	printf("repeating country_popular_stations_items_inner:\n%s\n", cJSON_Print(jsoncountry_popular_stations_items_inner_2));
}

int main() {
  test_country_popular_stations_items_inner(1);
  test_country_popular_stations_items_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // country_popular_stations_items_inner_MAIN
#endif // country_popular_stations_items_inner_TEST
