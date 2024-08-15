#ifndef local_popular_stations_TEST
#define local_popular_stations_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define local_popular_stations_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/local_popular_stations.h"
local_popular_stations_t* instantiate_local_popular_stations(int include_optional);

#include "test_place_ref.c"


local_popular_stations_t* instantiate_local_popular_stations(int include_optional) {
  local_popular_stations_t* local_popular_stations = NULL;
  if (include_optional) {
    local_popular_stations = local_popular_stations_create(
       // false, not to have infinite recursion
      instantiate_place_ref(0),
      "See all",
      "Popular in Austin TX",
      "list",
      "channel",
      list_createList()
    );
  } else {
    local_popular_stations = local_popular_stations_create(
      NULL,
      "See all",
      "Popular in Austin TX",
      "list",
      "channel",
      list_createList()
    );
  }

  return local_popular_stations;
}


#ifdef local_popular_stations_MAIN

void test_local_popular_stations(int include_optional) {
    local_popular_stations_t* local_popular_stations_1 = instantiate_local_popular_stations(include_optional);

	cJSON* jsonlocal_popular_stations_1 = local_popular_stations_convertToJSON(local_popular_stations_1);
	printf("local_popular_stations :\n%s\n", cJSON_Print(jsonlocal_popular_stations_1));
	local_popular_stations_t* local_popular_stations_2 = local_popular_stations_parseFromJSON(jsonlocal_popular_stations_1);
	cJSON* jsonlocal_popular_stations_2 = local_popular_stations_convertToJSON(local_popular_stations_2);
	printf("repeating local_popular_stations:\n%s\n", cJSON_Print(jsonlocal_popular_stations_2));
}

int main() {
  test_local_popular_stations(1);
  test_local_popular_stations(0);

  printf("Hello world \n");
  return 0;
}

#endif // local_popular_stations_MAIN
#endif // local_popular_stations_TEST
