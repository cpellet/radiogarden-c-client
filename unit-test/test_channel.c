#ifndef channel_TEST
#define channel_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define channel_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/channel.h"
channel_t* instantiate_channel(int include_optional);

#include "test_channel_place.c"
#include "test_channel_country.c"


channel_t* instantiate_channel(int include_optional) {
  channel_t* channel = NULL;
  if (include_optional) {
    channel = channel_create(
      "vbFsCngB",
      "KUTX FM 98.9",
      "/listen/kutx-98-9/vbFsCngB",
      "http://www.kutx.org",
      true,
       // false, not to have infinite recursion
      instantiate_channel_place(0),
       // false, not to have infinite recursion
      instantiate_channel_country(0)
    );
  } else {
    channel = channel_create(
      "vbFsCngB",
      "KUTX FM 98.9",
      "/listen/kutx-98-9/vbFsCngB",
      "http://www.kutx.org",
      true,
      NULL,
      NULL
    );
  }

  return channel;
}


#ifdef channel_MAIN

void test_channel(int include_optional) {
    channel_t* channel_1 = instantiate_channel(include_optional);

	cJSON* jsonchannel_1 = channel_convertToJSON(channel_1);
	printf("channel :\n%s\n", cJSON_Print(jsonchannel_1));
	channel_t* channel_2 = channel_parseFromJSON(jsonchannel_1);
	cJSON* jsonchannel_2 = channel_convertToJSON(channel_2);
	printf("repeating channel:\n%s\n", cJSON_Print(jsonchannel_2));
}

int main() {
  test_channel(1);
  test_channel(0);

  printf("Hello world \n");
  return 0;
}

#endif // channel_MAIN
#endif // channel_TEST
