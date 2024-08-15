#ifndef place_TEST
#define place_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define place_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/place.h"
place_t* instantiate_place(int include_optional);



place_t* instantiate_place(int include_optional) {
  place_t* place = NULL;
  if (include_optional) {
    place = place_create(
      "Aq7xeIiB",
      [-97.74306,30.267153],
      "/visit/austin-tx/Aq7xeIiB",
      21,
      true,
      "Austin TX",
      "United States"
    );
  } else {
    place = place_create(
      "Aq7xeIiB",
      [-97.74306,30.267153],
      "/visit/austin-tx/Aq7xeIiB",
      21,
      true,
      "Austin TX",
      "United States"
    );
  }

  return place;
}


#ifdef place_MAIN

void test_place(int include_optional) {
    place_t* place_1 = instantiate_place(include_optional);

	cJSON* jsonplace_1 = place_convertToJSON(place_1);
	printf("place :\n%s\n", cJSON_Print(jsonplace_1));
	place_t* place_2 = place_parseFromJSON(jsonplace_1);
	cJSON* jsonplace_2 = place_convertToJSON(place_2);
	printf("repeating place:\n%s\n", cJSON_Print(jsonplace_2));
}

int main() {
  test_place(1);
  test_place(0);

  printf("Hello world \n");
  return 0;
}

#endif // place_MAIN
#endif // place_TEST
