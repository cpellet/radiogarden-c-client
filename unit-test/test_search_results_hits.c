#ifndef search_results_hits_TEST
#define search_results_hits_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define search_results_hits_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/search_results_hits.h"
search_results_hits_t* instantiate_search_results_hits(int include_optional);



search_results_hits_t* instantiate_search_results_hits(int include_optional) {
  search_results_hits_t* search_results_hits = NULL;
  if (include_optional) {
    search_results_hits = search_results_hits_create(
      list_createList()
    );
  } else {
    search_results_hits = search_results_hits_create(
      list_createList()
    );
  }

  return search_results_hits;
}


#ifdef search_results_hits_MAIN

void test_search_results_hits(int include_optional) {
    search_results_hits_t* search_results_hits_1 = instantiate_search_results_hits(include_optional);

	cJSON* jsonsearch_results_hits_1 = search_results_hits_convertToJSON(search_results_hits_1);
	printf("search_results_hits :\n%s\n", cJSON_Print(jsonsearch_results_hits_1));
	search_results_hits_t* search_results_hits_2 = search_results_hits_parseFromJSON(jsonsearch_results_hits_1);
	cJSON* jsonsearch_results_hits_2 = search_results_hits_convertToJSON(search_results_hits_2);
	printf("repeating search_results_hits:\n%s\n", cJSON_Print(jsonsearch_results_hits_2));
}

int main() {
  test_search_results_hits(1);
  test_search_results_hits(0);

  printf("Hello world \n");
  return 0;
}

#endif // search_results_hits_MAIN
#endif // search_results_hits_TEST
