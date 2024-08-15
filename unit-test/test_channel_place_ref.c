#ifndef channel_place_ref_TEST
#define channel_place_ref_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define channel_place_ref_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/channel_place_ref.h"
channel_place_ref_t* instantiate_channel_place_ref(int include_optional);



channel_place_ref_t* instantiate_channel_place_ref(int include_optional) {
  channel_place_ref_t* channel_place_ref = NULL;
  if (include_optional) {
    channel_place_ref = channel_place_ref_create(
      "KUTX FM 98.9",
      "/listen/kutx-98-9/vbFsCngB",
      "Georgetown TX",
      "BQP3R6jj"
    );
  } else {
    channel_place_ref = channel_place_ref_create(
      "KUTX FM 98.9",
      "/listen/kutx-98-9/vbFsCngB",
      "Georgetown TX",
      "BQP3R6jj"
    );
  }

  return channel_place_ref;
}


#ifdef channel_place_ref_MAIN

void test_channel_place_ref(int include_optional) {
    channel_place_ref_t* channel_place_ref_1 = instantiate_channel_place_ref(include_optional);

	cJSON* jsonchannel_place_ref_1 = channel_place_ref_convertToJSON(channel_place_ref_1);
	printf("channel_place_ref :\n%s\n", cJSON_Print(jsonchannel_place_ref_1));
	channel_place_ref_t* channel_place_ref_2 = channel_place_ref_parseFromJSON(jsonchannel_place_ref_1);
	cJSON* jsonchannel_place_ref_2 = channel_place_ref_convertToJSON(channel_place_ref_2);
	printf("repeating channel_place_ref:\n%s\n", cJSON_Print(jsonchannel_place_ref_2));
}

int main() {
  test_channel_place_ref(1);
  test_channel_place_ref(0);

  printf("Hello world \n");
  return 0;
}

#endif // channel_place_ref_MAIN
#endif // channel_place_ref_TEST
