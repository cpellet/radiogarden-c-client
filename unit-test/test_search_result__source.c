#ifndef search_result__source_TEST
#define search_result__source_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define search_result__source_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/search_result__source.h"
search_result__source_t* instantiate_search_result__source(int include_optional);



search_result__source_t* instantiate_search_result__source(int include_optional) {
  search_result__source_t* search_result__source = NULL;
  if (include_optional) {
    search_result__source = search_result__source_create(
      "US",
      "Austin TX, United States",
      "channel",
      "KUTX FM 98.9",
      "/listen/kutx-98-9/vbFsCngB"
    );
  } else {
    search_result__source = search_result__source_create(
      "US",
      "Austin TX, United States",
      "channel",
      "KUTX FM 98.9",
      "/listen/kutx-98-9/vbFsCngB"
    );
  }

  return search_result__source;
}


#ifdef search_result__source_MAIN

void test_search_result__source(int include_optional) {
    search_result__source_t* search_result__source_1 = instantiate_search_result__source(include_optional);

	cJSON* jsonsearch_result__source_1 = search_result__source_convertToJSON(search_result__source_1);
	printf("search_result__source :\n%s\n", cJSON_Print(jsonsearch_result__source_1));
	search_result__source_t* search_result__source_2 = search_result__source_parseFromJSON(jsonsearch_result__source_1);
	cJSON* jsonsearch_result__source_2 = search_result__source_convertToJSON(search_result__source_2);
	printf("repeating search_result__source:\n%s\n", cJSON_Print(jsonsearch_result__source_2));
}

int main() {
  test_search_result__source(1);
  test_search_result__source(0);

  printf("Hello world \n");
  return 0;
}

#endif // search_result__source_MAIN
#endif // search_result__source_TEST
