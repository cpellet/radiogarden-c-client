#ifndef geolocation_TEST
#define geolocation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define geolocation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/geolocation.h"
geolocation_t* instantiate_geolocation(int include_optional);



geolocation_t* instantiate_geolocation(int include_optional) {
  geolocation_t* geolocation = NULL;
  if (include_optional) {
    geolocation = geolocation_create(
      "f52f:80fc:ece8:8afc:2fc9:2e9b:a67e:4100",
      "US",
      "United States",
      "TX",
      "Texas",
      "Austin",
      "78799",
      "America/Chicago",
      30.26715,
      -97.74306,
      635
    );
  } else {
    geolocation = geolocation_create(
      "f52f:80fc:ece8:8afc:2fc9:2e9b:a67e:4100",
      "US",
      "United States",
      "TX",
      "Texas",
      "Austin",
      "78799",
      "America/Chicago",
      30.26715,
      -97.74306,
      635
    );
  }

  return geolocation;
}


#ifdef geolocation_MAIN

void test_geolocation(int include_optional) {
    geolocation_t* geolocation_1 = instantiate_geolocation(include_optional);

	cJSON* jsongeolocation_1 = geolocation_convertToJSON(geolocation_1);
	printf("geolocation :\n%s\n", cJSON_Print(jsongeolocation_1));
	geolocation_t* geolocation_2 = geolocation_parseFromJSON(jsongeolocation_1);
	cJSON* jsongeolocation_2 = geolocation_convertToJSON(geolocation_2);
	printf("repeating geolocation:\n%s\n", cJSON_Print(jsongeolocation_2));
}

int main() {
  test_geolocation(1);
  test_geolocation(0);

  printf("Hello world \n");
  return 0;
}

#endif // geolocation_MAIN
#endif // geolocation_TEST
