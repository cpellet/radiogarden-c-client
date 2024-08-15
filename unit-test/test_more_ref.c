#ifndef more_ref_TEST
#define more_ref_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define more_ref_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/more_ref.h"
more_ref_t* instantiate_more_ref(int include_optional);

#include "test_more_ref_page.c"


more_ref_t* instantiate_more_ref(int include_optional) {
  more_ref_t* more_ref = NULL;
  if (include_optional) {
    more_ref = more_ref_create(
      "View all 21 stations",
      "more",
      "chevron-right",
      null
    );
  } else {
    more_ref = more_ref_create(
      "View all 21 stations",
      "more",
      "chevron-right",
      null
    );
  }

  return more_ref;
}


#ifdef more_ref_MAIN

void test_more_ref(int include_optional) {
    more_ref_t* more_ref_1 = instantiate_more_ref(include_optional);

	cJSON* jsonmore_ref_1 = more_ref_convertToJSON(more_ref_1);
	printf("more_ref :\n%s\n", cJSON_Print(jsonmore_ref_1));
	more_ref_t* more_ref_2 = more_ref_parseFromJSON(jsonmore_ref_1);
	cJSON* jsonmore_ref_2 = more_ref_convertToJSON(more_ref_2);
	printf("repeating more_ref:\n%s\n", cJSON_Print(jsonmore_ref_2));
}

int main() {
  test_more_ref(1);
  test_more_ref(0);

  printf("Hello world \n");
  return 0;
}

#endif // more_ref_MAIN
#endif // more_ref_TEST
