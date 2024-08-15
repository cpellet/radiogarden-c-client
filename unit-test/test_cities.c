#ifndef cities_TEST
#define cities_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cities_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cities.h"
cities_t* instantiate_cities(int include_optional);



cities_t* instantiate_cities(int include_optional) {
  cities_t* cities = NULL;
  if (include_optional) {
    cities = cities_create(
      "Cities in United States",
      "list",
      "chevron-right",
      list_createList()
    );
  } else {
    cities = cities_create(
      "Cities in United States",
      "list",
      "chevron-right",
      list_createList()
    );
  }

  return cities;
}


#ifdef cities_MAIN

void test_cities(int include_optional) {
    cities_t* cities_1 = instantiate_cities(include_optional);

	cJSON* jsoncities_1 = cities_convertToJSON(cities_1);
	printf("cities :\n%s\n", cJSON_Print(jsoncities_1));
	cities_t* cities_2 = cities_parseFromJSON(jsoncities_1);
	cJSON* jsoncities_2 = cities_convertToJSON(cities_2);
	printf("repeating cities:\n%s\n", cJSON_Print(jsoncities_2));
}

int main() {
  test_cities(1);
  test_cities(0);

  printf("Hello world \n");
  return 0;
}

#endif // cities_MAIN
#endif // cities_TEST
