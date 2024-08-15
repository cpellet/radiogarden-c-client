#ifndef left_page_ref_TEST
#define left_page_ref_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define left_page_ref_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/left_page_ref.h"
left_page_ref_t* instantiate_left_page_ref(int include_optional);

#include "test_place_ref.c"


left_page_ref_t* instantiate_left_page_ref(int include_optional) {
  left_page_ref_t* left_page_ref = NULL;
  if (include_optional) {
    left_page_ref = left_page_ref_create(
      "New York NY",
      "count",
      219,
       // false, not to have infinite recursion
      instantiate_place_ref(0)
    );
  } else {
    left_page_ref = left_page_ref_create(
      "New York NY",
      "count",
      219,
      NULL
    );
  }

  return left_page_ref;
}


#ifdef left_page_ref_MAIN

void test_left_page_ref(int include_optional) {
    left_page_ref_t* left_page_ref_1 = instantiate_left_page_ref(include_optional);

	cJSON* jsonleft_page_ref_1 = left_page_ref_convertToJSON(left_page_ref_1);
	printf("left_page_ref :\n%s\n", cJSON_Print(jsonleft_page_ref_1));
	left_page_ref_t* left_page_ref_2 = left_page_ref_parseFromJSON(jsonleft_page_ref_1);
	cJSON* jsonleft_page_ref_2 = left_page_ref_convertToJSON(left_page_ref_2);
	printf("repeating left_page_ref:\n%s\n", cJSON_Print(jsonleft_page_ref_2));
}

int main() {
  test_left_page_ref(1);
  test_left_page_ref(0);

  printf("Hello world \n");
  return 0;
}

#endif // left_page_ref_MAIN
#endif // left_page_ref_TEST
