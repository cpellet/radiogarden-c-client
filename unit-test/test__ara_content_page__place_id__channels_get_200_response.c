#ifndef _ara_content_page__place_id__channels_get_200_response_TEST
#define _ara_content_page__place_id__channels_get_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _ara_content_page__place_id__channels_get_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_ara_content_page__place_id__channels_get_200_response.h"
_ara_content_page__place_id__channels_get_200_response_t* instantiate__ara_content_page__place_id__channels_get_200_response(int include_optional);

#include "test__ara_content_page__place_id__channels_get_200_response_all_of_data.c"


_ara_content_page__place_id__channels_get_200_response_t* instantiate__ara_content_page__place_id__channels_get_200_response(int include_optional) {
  _ara_content_page__place_id__channels_get_200_response_t* _ara_content_page__place_id__channels_get_200_response = NULL;
  if (include_optional) {
    _ara_content_page__place_id__channels_get_200_response = _ara_content_page__place_id__channels_get_200_response_create(
      1,
      "9bd5454",
      null
    );
  } else {
    _ara_content_page__place_id__channels_get_200_response = _ara_content_page__place_id__channels_get_200_response_create(
      1,
      "9bd5454",
      null
    );
  }

  return _ara_content_page__place_id__channels_get_200_response;
}


#ifdef _ara_content_page__place_id__channels_get_200_response_MAIN

void test__ara_content_page__place_id__channels_get_200_response(int include_optional) {
    _ara_content_page__place_id__channels_get_200_response_t* _ara_content_page__place_id__channels_get_200_response_1 = instantiate__ara_content_page__place_id__channels_get_200_response(include_optional);

	cJSON* json_ara_content_page__place_id__channels_get_200_response_1 = _ara_content_page__place_id__channels_get_200_response_convertToJSON(_ara_content_page__place_id__channels_get_200_response_1);
	printf("_ara_content_page__place_id__channels_get_200_response :\n%s\n", cJSON_Print(json_ara_content_page__place_id__channels_get_200_response_1));
	_ara_content_page__place_id__channels_get_200_response_t* _ara_content_page__place_id__channels_get_200_response_2 = _ara_content_page__place_id__channels_get_200_response_parseFromJSON(json_ara_content_page__place_id__channels_get_200_response_1);
	cJSON* json_ara_content_page__place_id__channels_get_200_response_2 = _ara_content_page__place_id__channels_get_200_response_convertToJSON(_ara_content_page__place_id__channels_get_200_response_2);
	printf("repeating _ara_content_page__place_id__channels_get_200_response:\n%s\n", cJSON_Print(json_ara_content_page__place_id__channels_get_200_response_2));
}

int main() {
  test__ara_content_page__place_id__channels_get_200_response(1);
  test__ara_content_page__place_id__channels_get_200_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // _ara_content_page__place_id__channels_get_200_response_MAIN
#endif // _ara_content_page__place_id__channels_get_200_response_TEST
