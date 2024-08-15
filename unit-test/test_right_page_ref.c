#ifndef right_page_ref_TEST
#define right_page_ref_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define right_page_ref_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/right_page_ref.h"
right_page_ref_t* instantiate_right_page_ref(int include_optional);

#include "test_place_ref.c"


right_page_ref_t* instantiate_right_page_ref(int include_optional) {
  right_page_ref_t* right_page_ref = NULL;
  if (include_optional) {
    right_page_ref = right_page_ref_create(
      "Georgetown TX",
      "41 km",
       // false, not to have infinite recursion
      instantiate_place_ref(0)
    );
  } else {
    right_page_ref = right_page_ref_create(
      "Georgetown TX",
      "41 km",
      NULL
    );
  }

  return right_page_ref;
}


#ifdef right_page_ref_MAIN

void test_right_page_ref(int include_optional) {
    right_page_ref_t* right_page_ref_1 = instantiate_right_page_ref(include_optional);

	cJSON* jsonright_page_ref_1 = right_page_ref_convertToJSON(right_page_ref_1);
	printf("right_page_ref :\n%s\n", cJSON_Print(jsonright_page_ref_1));
	right_page_ref_t* right_page_ref_2 = right_page_ref_parseFromJSON(jsonright_page_ref_1);
	cJSON* jsonright_page_ref_2 = right_page_ref_convertToJSON(right_page_ref_2);
	printf("repeating right_page_ref:\n%s\n", cJSON_Print(jsonright_page_ref_2));
}

int main() {
  test_right_page_ref(1);
  test_right_page_ref(0);

  printf("Hello world \n");
  return 0;
}

#endif // right_page_ref_MAIN
#endif // right_page_ref_TEST
