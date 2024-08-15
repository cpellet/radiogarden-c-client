#ifndef country_ref_TEST
#define country_ref_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define country_ref_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/country_ref.h"
country_ref_t* instantiate_country_ref(int include_optional);



country_ref_t* instantiate_country_ref(int include_optional) {
  country_ref_t* country_ref = NULL;
  if (include_optional) {
    country_ref = country_ref_create(
      "United States",
      "/visit/united-states/GhDXw4EW",
      [-74.00114,40.611214]
    );
  } else {
    country_ref = country_ref_create(
      "United States",
      "/visit/united-states/GhDXw4EW",
      [-74.00114,40.611214]
    );
  }

  return country_ref;
}


#ifdef country_ref_MAIN

void test_country_ref(int include_optional) {
    country_ref_t* country_ref_1 = instantiate_country_ref(include_optional);

	cJSON* jsoncountry_ref_1 = country_ref_convertToJSON(country_ref_1);
	printf("country_ref :\n%s\n", cJSON_Print(jsoncountry_ref_1));
	country_ref_t* country_ref_2 = country_ref_parseFromJSON(jsoncountry_ref_1);
	cJSON* jsoncountry_ref_2 = country_ref_convertToJSON(country_ref_2);
	printf("repeating country_ref:\n%s\n", cJSON_Print(jsoncountry_ref_2));
}

int main() {
  test_country_ref(1);
  test_country_ref(0);

  printf("Hello world \n");
  return 0;
}

#endif // country_ref_MAIN
#endif // country_ref_TEST
