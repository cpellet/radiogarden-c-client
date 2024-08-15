#ifndef place_content_content_inner_TEST
#define place_content_content_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define place_content_content_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/place_content_content_inner.h"
place_content_content_inner_t* instantiate_place_content_content_inner(int include_optional);

#include "test_place_ref.c"


place_content_content_inner_t* instantiate_place_content_content_inner(int include_optional) {
  place_content_content_inner_t* place_content_content_inner = NULL;
  if (include_optional) {
    place_content_content_inner = place_content_content_inner_create(
      "Cities in United States",
      "list",
      "channel",
      list_createList(),
       // false, not to have infinite recursion
      instantiate_place_ref(0),
      "See all",
      "chevron-right"
    );
  } else {
    place_content_content_inner = place_content_content_inner_create(
      "Cities in United States",
      "list",
      "channel",
      list_createList(),
      NULL,
      "See all",
      "chevron-right"
    );
  }

  return place_content_content_inner;
}


#ifdef place_content_content_inner_MAIN

void test_place_content_content_inner(int include_optional) {
    place_content_content_inner_t* place_content_content_inner_1 = instantiate_place_content_content_inner(include_optional);

	cJSON* jsonplace_content_content_inner_1 = place_content_content_inner_convertToJSON(place_content_content_inner_1);
	printf("place_content_content_inner :\n%s\n", cJSON_Print(jsonplace_content_content_inner_1));
	place_content_content_inner_t* place_content_content_inner_2 = place_content_content_inner_parseFromJSON(jsonplace_content_content_inner_1);
	cJSON* jsonplace_content_content_inner_2 = place_content_content_inner_convertToJSON(place_content_content_inner_2);
	printf("repeating place_content_content_inner:\n%s\n", cJSON_Print(jsonplace_content_content_inner_2));
}

int main() {
  test_place_content_content_inner(1);
  test_place_content_content_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // place_content_content_inner_MAIN
#endif // place_content_content_inner_TEST
