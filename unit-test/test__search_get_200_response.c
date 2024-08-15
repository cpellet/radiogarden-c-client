#ifndef _search_get_200_response_TEST
#define _search_get_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _search_get_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_search_get_200_response.h"
_search_get_200_response_t* instantiate__search_get_200_response(int include_optional);

#include "test_search_results_hits.c"


_search_get_200_response_t* instantiate__search_get_200_response(int include_optional) {
  _search_get_200_response_t* _search_get_200_response = NULL;
  if (include_optional) {
    _search_get_200_response = _search_get_200_response_create(
      1,
      "9bd5454",
      "kutx",
      1,
       // false, not to have infinite recursion
      instantiate_search_results_hits(0)
    );
  } else {
    _search_get_200_response = _search_get_200_response_create(
      1,
      "9bd5454",
      "kutx",
      1,
      NULL
    );
  }

  return _search_get_200_response;
}


#ifdef _search_get_200_response_MAIN

void test__search_get_200_response(int include_optional) {
    _search_get_200_response_t* _search_get_200_response_1 = instantiate__search_get_200_response(include_optional);

	cJSON* json_search_get_200_response_1 = _search_get_200_response_convertToJSON(_search_get_200_response_1);
	printf("_search_get_200_response :\n%s\n", cJSON_Print(json_search_get_200_response_1));
	_search_get_200_response_t* _search_get_200_response_2 = _search_get_200_response_parseFromJSON(json_search_get_200_response_1);
	cJSON* json_search_get_200_response_2 = _search_get_200_response_convertToJSON(_search_get_200_response_2);
	printf("repeating _search_get_200_response:\n%s\n", cJSON_Print(json_search_get_200_response_2));
}

int main() {
  test__search_get_200_response(1);
  test__search_get_200_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // _search_get_200_response_MAIN
#endif // _search_get_200_response_TEST
