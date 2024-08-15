#ifndef place_ref_TEST
#define place_ref_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define place_ref_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/place_ref.h"
place_ref_t* instantiate_place_ref(int include_optional);



place_ref_t* instantiate_place_ref(int include_optional) {
  place_ref_t* place_ref = NULL;
  if (include_optional) {
    place_ref = place_ref_create(
      "Austin TX",
      "All Stations",
      "/visit/austin-tx/Aq7xeIiB/channels",
      "Aq7xeIiB",
      21,
      -360
    );
  } else {
    place_ref = place_ref_create(
      "Austin TX",
      "All Stations",
      "/visit/austin-tx/Aq7xeIiB/channels",
      "Aq7xeIiB",
      21,
      -360
    );
  }

  return place_ref;
}


#ifdef place_ref_MAIN

void test_place_ref(int include_optional) {
    place_ref_t* place_ref_1 = instantiate_place_ref(include_optional);

	cJSON* jsonplace_ref_1 = place_ref_convertToJSON(place_ref_1);
	printf("place_ref :\n%s\n", cJSON_Print(jsonplace_ref_1));
	place_ref_t* place_ref_2 = place_ref_parseFromJSON(jsonplace_ref_1);
	cJSON* jsonplace_ref_2 = place_ref_convertToJSON(place_ref_2);
	printf("repeating place_ref:\n%s\n", cJSON_Print(jsonplace_ref_2));
}

int main() {
  test_place_ref(1);
  test_place_ref(0);

  printf("Hello world \n");
  return 0;
}

#endif // place_ref_MAIN
#endif // place_ref_TEST
