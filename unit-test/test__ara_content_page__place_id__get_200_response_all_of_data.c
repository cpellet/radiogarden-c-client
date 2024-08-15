#ifndef _ara_content_page__place_id__get_200_response_all_of_data_TEST
#define _ara_content_page__place_id__get_200_response_all_of_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _ara_content_page__place_id__get_200_response_all_of_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_ara_content_page__place_id__get_200_response_all_of_data.h"
_ara_content_page__place_id__get_200_response_all_of_data_t* instantiate__ara_content_page__place_id__get_200_response_all_of_data(int include_optional);



_ara_content_page__place_id__get_200_response_all_of_data_t* instantiate__ara_content_page__place_id__get_200_response_all_of_data(int include_optional) {
  _ara_content_page__place_id__get_200_response_all_of_data_t* _ara_content_page__place_id__get_200_response_all_of_data = NULL;
  if (include_optional) {
    _ara_content_page__place_id__get_200_response_all_of_data = _ara_content_page__place_id__get_200_response_all_of_data_create(
      "Austin TX",
      "All Stations",
      "/visit/austin-tx/Aq7xeIiB/channels",
      "Aq7xeIiB",
      21,
      -360,
      list_createList()
    );
  } else {
    _ara_content_page__place_id__get_200_response_all_of_data = _ara_content_page__place_id__get_200_response_all_of_data_create(
      "Austin TX",
      "All Stations",
      "/visit/austin-tx/Aq7xeIiB/channels",
      "Aq7xeIiB",
      21,
      -360,
      list_createList()
    );
  }

  return _ara_content_page__place_id__get_200_response_all_of_data;
}


#ifdef _ara_content_page__place_id__get_200_response_all_of_data_MAIN

void test__ara_content_page__place_id__get_200_response_all_of_data(int include_optional) {
    _ara_content_page__place_id__get_200_response_all_of_data_t* _ara_content_page__place_id__get_200_response_all_of_data_1 = instantiate__ara_content_page__place_id__get_200_response_all_of_data(include_optional);

	cJSON* json_ara_content_page__place_id__get_200_response_all_of_data_1 = _ara_content_page__place_id__get_200_response_all_of_data_convertToJSON(_ara_content_page__place_id__get_200_response_all_of_data_1);
	printf("_ara_content_page__place_id__get_200_response_all_of_data :\n%s\n", cJSON_Print(json_ara_content_page__place_id__get_200_response_all_of_data_1));
	_ara_content_page__place_id__get_200_response_all_of_data_t* _ara_content_page__place_id__get_200_response_all_of_data_2 = _ara_content_page__place_id__get_200_response_all_of_data_parseFromJSON(json_ara_content_page__place_id__get_200_response_all_of_data_1);
	cJSON* json_ara_content_page__place_id__get_200_response_all_of_data_2 = _ara_content_page__place_id__get_200_response_all_of_data_convertToJSON(_ara_content_page__place_id__get_200_response_all_of_data_2);
	printf("repeating _ara_content_page__place_id__get_200_response_all_of_data:\n%s\n", cJSON_Print(json_ara_content_page__place_id__get_200_response_all_of_data_2));
}

int main() {
  test__ara_content_page__place_id__get_200_response_all_of_data(1);
  test__ara_content_page__place_id__get_200_response_all_of_data(0);

  printf("Hello world \n");
  return 0;
}

#endif // _ara_content_page__place_id__get_200_response_all_of_data_MAIN
#endif // _ara_content_page__place_id__get_200_response_all_of_data_TEST
