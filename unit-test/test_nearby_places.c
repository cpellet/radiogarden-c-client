#ifndef nearby_places_TEST
#define nearby_places_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define nearby_places_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/nearby_places.h"
nearby_places_t* instantiate_nearby_places(int include_optional);



nearby_places_t* instantiate_nearby_places(int include_optional) {
  nearby_places_t* nearby_places = NULL;
  if (include_optional) {
    nearby_places = nearby_places_create(
      "Nearby Austin TX",
      "list",
      "chevron-right",
      list_createList()
    );
  } else {
    nearby_places = nearby_places_create(
      "Nearby Austin TX",
      "list",
      "chevron-right",
      list_createList()
    );
  }

  return nearby_places;
}


#ifdef nearby_places_MAIN

void test_nearby_places(int include_optional) {
    nearby_places_t* nearby_places_1 = instantiate_nearby_places(include_optional);

	cJSON* jsonnearby_places_1 = nearby_places_convertToJSON(nearby_places_1);
	printf("nearby_places :\n%s\n", cJSON_Print(jsonnearby_places_1));
	nearby_places_t* nearby_places_2 = nearby_places_parseFromJSON(jsonnearby_places_1);
	cJSON* jsonnearby_places_2 = nearby_places_convertToJSON(nearby_places_2);
	printf("repeating nearby_places:\n%s\n", cJSON_Print(jsonnearby_places_2));
}

int main() {
  test_nearby_places(1);
  test_nearby_places(0);

  printf("Hello world \n");
  return 0;
}

#endif // nearby_places_MAIN
#endif // nearby_places_TEST
