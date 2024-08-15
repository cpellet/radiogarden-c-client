#ifndef search_results_TEST
#define search_results_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define search_results_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/search_results.h"
search_results_t* instantiate_search_results(int include_optional);

#include "test_search_results_hits.c"


search_results_t* instantiate_search_results(int include_optional) {
  search_results_t* search_results = NULL;
  if (include_optional) {
    search_results = search_results_create(
      "kutx",
      1,
       // false, not to have infinite recursion
      instantiate_search_results_hits(0)
    );
  } else {
    search_results = search_results_create(
      "kutx",
      1,
      NULL
    );
  }

  return search_results;
}


#ifdef search_results_MAIN

void test_search_results(int include_optional) {
    search_results_t* search_results_1 = instantiate_search_results(include_optional);

	cJSON* jsonsearch_results_1 = search_results_convertToJSON(search_results_1);
	printf("search_results :\n%s\n", cJSON_Print(jsonsearch_results_1));
	search_results_t* search_results_2 = search_results_parseFromJSON(jsonsearch_results_1);
	cJSON* jsonsearch_results_2 = search_results_convertToJSON(search_results_2);
	printf("repeating search_results:\n%s\n", cJSON_Print(jsonsearch_results_2));
}

int main() {
  test_search_results(1);
  test_search_results(0);

  printf("Hello world \n");
  return 0;
}

#endif // search_results_MAIN
#endif // search_results_TEST
