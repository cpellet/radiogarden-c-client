#ifndef channel_ref_TEST
#define channel_ref_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define channel_ref_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/channel_ref.h"
channel_ref_t* instantiate_channel_ref(int include_optional);



channel_ref_t* instantiate_channel_ref(int include_optional) {
  channel_ref_t* channel_ref = NULL;
  if (include_optional) {
    channel_ref = channel_ref_create(
      "KUTX FM 98.9",
      "/listen/kutx-98-9/vbFsCngB"
    );
  } else {
    channel_ref = channel_ref_create(
      "KUTX FM 98.9",
      "/listen/kutx-98-9/vbFsCngB"
    );
  }

  return channel_ref;
}


#ifdef channel_ref_MAIN

void test_channel_ref(int include_optional) {
    channel_ref_t* channel_ref_1 = instantiate_channel_ref(include_optional);

	cJSON* jsonchannel_ref_1 = channel_ref_convertToJSON(channel_ref_1);
	printf("channel_ref :\n%s\n", cJSON_Print(jsonchannel_ref_1));
	channel_ref_t* channel_ref_2 = channel_ref_parseFromJSON(jsonchannel_ref_1);
	cJSON* jsonchannel_ref_2 = channel_ref_convertToJSON(channel_ref_2);
	printf("repeating channel_ref:\n%s\n", cJSON_Print(jsonchannel_ref_2));
}

int main() {
  test_channel_ref(1);
  test_channel_ref(0);

  printf("Hello world \n");
  return 0;
}

#endif // channel_ref_MAIN
#endif // channel_ref_TEST
