#ifndef selected_stations_items_inner_TEST
#define selected_stations_items_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define selected_stations_items_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/selected_stations_items_inner.h"
selected_stations_items_inner_t* instantiate_selected_stations_items_inner(int include_optional);

#include "test_more_ref_page.c"


selected_stations_items_inner_t* instantiate_selected_stations_items_inner(int include_optional) {
  selected_stations_items_inner_t* selected_stations_items_inner = NULL;
  if (include_optional) {
    selected_stations_items_inner = selected_stations_items_inner_create(
      "View all 21 stations",
      "/listen/kutx-98-9/vbFsCngB",
      "more",
      "chevron-right",
      null
    );
  } else {
    selected_stations_items_inner = selected_stations_items_inner_create(
      "View all 21 stations",
      "/listen/kutx-98-9/vbFsCngB",
      "more",
      "chevron-right",
      null
    );
  }

  return selected_stations_items_inner;
}


#ifdef selected_stations_items_inner_MAIN

void test_selected_stations_items_inner(int include_optional) {
    selected_stations_items_inner_t* selected_stations_items_inner_1 = instantiate_selected_stations_items_inner(include_optional);

	cJSON* jsonselected_stations_items_inner_1 = selected_stations_items_inner_convertToJSON(selected_stations_items_inner_1);
	printf("selected_stations_items_inner :\n%s\n", cJSON_Print(jsonselected_stations_items_inner_1));
	selected_stations_items_inner_t* selected_stations_items_inner_2 = selected_stations_items_inner_parseFromJSON(jsonselected_stations_items_inner_1);
	cJSON* jsonselected_stations_items_inner_2 = selected_stations_items_inner_convertToJSON(selected_stations_items_inner_2);
	printf("repeating selected_stations_items_inner:\n%s\n", cJSON_Print(jsonselected_stations_items_inner_2));
}

int main() {
  test_selected_stations_items_inner(1);
  test_selected_stations_items_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // selected_stations_items_inner_MAIN
#endif // selected_stations_items_inner_TEST
