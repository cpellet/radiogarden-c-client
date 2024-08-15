#ifndef search_result_TEST
#define search_result_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define search_result_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/search_result.h"
search_result_t* instantiate_search_result(int include_optional);

#include "test_search_result__source.c"


search_result_t* instantiate_search_result(int include_optional) {
  search_result_t* search_result = NULL;
  if (include_optional) {
    search_result = search_result_create(
      "602749",
      165.90909,
       // false, not to have infinite recursion
      instantiate_search_result__source(0)
    );
  } else {
    search_result = search_result_create(
      "602749",
      165.90909,
      NULL
    );
  }

  return search_result;
}


#ifdef search_result_MAIN

void test_search_result(int include_optional) {
    search_result_t* search_result_1 = instantiate_search_result(include_optional);

	cJSON* jsonsearch_result_1 = search_result_convertToJSON(search_result_1);
	printf("search_result :\n%s\n", cJSON_Print(jsonsearch_result_1));
	search_result_t* search_result_2 = search_result_parseFromJSON(jsonsearch_result_1);
	cJSON* jsonsearch_result_2 = search_result_convertToJSON(search_result_2);
	printf("repeating search_result:\n%s\n", cJSON_Print(jsonsearch_result_2));
}

int main() {
  test_search_result(1);
  test_search_result(0);

  printf("Hello world \n");
  return 0;
}

#endif // search_result_MAIN
#endif // search_result_TEST
