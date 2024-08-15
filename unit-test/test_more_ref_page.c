#ifndef more_ref_page_TEST
#define more_ref_page_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define more_ref_page_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/more_ref_page.h"
more_ref_page_t* instantiate_more_ref_page(int include_optional);



more_ref_page_t* instantiate_more_ref_page(int include_optional) {
  more_ref_page_t* more_ref_page = NULL;
  if (include_optional) {
    more_ref_page = more_ref_page_create(
      "United States",
      "All Stations",
      "/visit/united-states/GhDXw4EW",
      [-74.00114, 40.611214],
      21,
      -360
    );
  } else {
    more_ref_page = more_ref_page_create(
      "United States",
      "All Stations",
      "/visit/united-states/GhDXw4EW",
      [-74.00114, 40.611214],
      21,
      -360
    );
  }

  return more_ref_page;
}


#ifdef more_ref_page_MAIN

void test_more_ref_page(int include_optional) {
    more_ref_page_t* more_ref_page_1 = instantiate_more_ref_page(include_optional);

	cJSON* jsonmore_ref_page_1 = more_ref_page_convertToJSON(more_ref_page_1);
	printf("more_ref_page :\n%s\n", cJSON_Print(jsonmore_ref_page_1));
	more_ref_page_t* more_ref_page_2 = more_ref_page_parseFromJSON(jsonmore_ref_page_1);
	cJSON* jsonmore_ref_page_2 = more_ref_page_convertToJSON(more_ref_page_2);
	printf("repeating more_ref_page:\n%s\n", cJSON_Print(jsonmore_ref_page_2));
}

int main() {
  test_more_ref_page(1);
  test_more_ref_page(0);

  printf("Hello world \n");
  return 0;
}

#endif // more_ref_page_MAIN
#endif // more_ref_page_TEST
