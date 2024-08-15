#ifndef place_content_TEST
#define place_content_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define place_content_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/place_content.h"
place_content_t* instantiate_place_content(int include_optional);



place_content_t* instantiate_place_content(int include_optional) {
  place_content_t* place_content = NULL;
  if (include_optional) {
    place_content = place_content_create(
      list_createList()
    );
  } else {
    place_content = place_content_create(
      list_createList()
    );
  }

  return place_content;
}


#ifdef place_content_MAIN

void test_place_content(int include_optional) {
    place_content_t* place_content_1 = instantiate_place_content(include_optional);

	cJSON* jsonplace_content_1 = place_content_convertToJSON(place_content_1);
	printf("place_content :\n%s\n", cJSON_Print(jsonplace_content_1));
	place_content_t* place_content_2 = place_content_parseFromJSON(jsonplace_content_1);
	cJSON* jsonplace_content_2 = place_content_convertToJSON(place_content_2);
	printf("repeating place_content:\n%s\n", cJSON_Print(jsonplace_content_2));
}

int main() {
  test_place_content(1);
  test_place_content(0);

  printf("Hello world \n");
  return 0;
}

#endif // place_content_MAIN
#endif // place_content_TEST
