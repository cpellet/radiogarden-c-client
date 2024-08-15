#ifndef selected_stations_TEST
#define selected_stations_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define selected_stations_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/selected_stations.h"
selected_stations_t* instantiate_selected_stations(int include_optional);



selected_stations_t* instantiate_selected_stations(int include_optional) {
  selected_stations_t* selected_stations = NULL;
  if (include_optional) {
    selected_stations = selected_stations_create(
      "Selected Stations",
      "list",
      "channel",
      list_createList()
    );
  } else {
    selected_stations = selected_stations_create(
      "Selected Stations",
      "list",
      "channel",
      list_createList()
    );
  }

  return selected_stations;
}


#ifdef selected_stations_MAIN

void test_selected_stations(int include_optional) {
    selected_stations_t* selected_stations_1 = instantiate_selected_stations(include_optional);

	cJSON* jsonselected_stations_1 = selected_stations_convertToJSON(selected_stations_1);
	printf("selected_stations :\n%s\n", cJSON_Print(jsonselected_stations_1));
	selected_stations_t* selected_stations_2 = selected_stations_parseFromJSON(jsonselected_stations_1);
	cJSON* jsonselected_stations_2 = selected_stations_convertToJSON(selected_stations_2);
	printf("repeating selected_stations:\n%s\n", cJSON_Print(jsonselected_stations_2));
}

int main() {
  test_selected_stations(1);
  test_selected_stations(0);

  printf("Hello world \n");
  return 0;
}

#endif // selected_stations_MAIN
#endif // selected_stations_TEST
