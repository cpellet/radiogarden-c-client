#ifndef local_pick_stations_TEST
#define local_pick_stations_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define local_pick_stations_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/local_pick_stations.h"
local_pick_stations_t* instantiate_local_pick_stations(int include_optional);



local_pick_stations_t* instantiate_local_pick_stations(int include_optional) {
  local_pick_stations_t* local_pick_stations = NULL;
  if (include_optional) {
    local_pick_stations = local_pick_stations_create(
      "Picks from the area",
      "list",
      "channel",
      list_createList()
    );
  } else {
    local_pick_stations = local_pick_stations_create(
      "Picks from the area",
      "list",
      "channel",
      list_createList()
    );
  }

  return local_pick_stations;
}


#ifdef local_pick_stations_MAIN

void test_local_pick_stations(int include_optional) {
    local_pick_stations_t* local_pick_stations_1 = instantiate_local_pick_stations(include_optional);

	cJSON* jsonlocal_pick_stations_1 = local_pick_stations_convertToJSON(local_pick_stations_1);
	printf("local_pick_stations :\n%s\n", cJSON_Print(jsonlocal_pick_stations_1));
	local_pick_stations_t* local_pick_stations_2 = local_pick_stations_parseFromJSON(jsonlocal_pick_stations_1);
	cJSON* jsonlocal_pick_stations_2 = local_pick_stations_convertToJSON(local_pick_stations_2);
	printf("repeating local_pick_stations:\n%s\n", cJSON_Print(jsonlocal_pick_stations_2));
}

int main() {
  test_local_pick_stations(1);
  test_local_pick_stations(0);

  printf("Hello world \n");
  return 0;
}

#endif // local_pick_stations_MAIN
#endif // local_pick_stations_TEST
