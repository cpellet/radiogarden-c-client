#ifndef channel_place_TEST
#define channel_place_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define channel_place_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/channel_place.h"
channel_place_t* instantiate_channel_place(int include_optional);



channel_place_t* instantiate_channel_place(int include_optional) {
  channel_place_t* channel_place = NULL;
  if (include_optional) {
    channel_place = channel_place_create(
      "Aq7xeIiB",
      "Austin TX"
    );
  } else {
    channel_place = channel_place_create(
      "Aq7xeIiB",
      "Austin TX"
    );
  }

  return channel_place;
}


#ifdef channel_place_MAIN

void test_channel_place(int include_optional) {
    channel_place_t* channel_place_1 = instantiate_channel_place(include_optional);

	cJSON* jsonchannel_place_1 = channel_place_convertToJSON(channel_place_1);
	printf("channel_place :\n%s\n", cJSON_Print(jsonchannel_place_1));
	channel_place_t* channel_place_2 = channel_place_parseFromJSON(jsonchannel_place_1);
	cJSON* jsonchannel_place_2 = channel_place_convertToJSON(channel_place_2);
	printf("repeating channel_place:\n%s\n", cJSON_Print(jsonchannel_place_2));
}

int main() {
  test_channel_place(1);
  test_channel_place(0);

  printf("Hello world \n");
  return 0;
}

#endif // channel_place_MAIN
#endif // channel_place_TEST
