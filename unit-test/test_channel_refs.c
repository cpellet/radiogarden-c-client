#ifndef channel_refs_TEST
#define channel_refs_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define channel_refs_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/channel_refs.h"
channel_refs_t* instantiate_channel_refs(int include_optional);



channel_refs_t* instantiate_channel_refs(int include_optional) {
  channel_refs_t* channel_refs = NULL;
  if (include_optional) {
    channel_refs = channel_refs_create(
      "channel",
      "list",
      list_createList()
    );
  } else {
    channel_refs = channel_refs_create(
      "channel",
      "list",
      list_createList()
    );
  }

  return channel_refs;
}


#ifdef channel_refs_MAIN

void test_channel_refs(int include_optional) {
    channel_refs_t* channel_refs_1 = instantiate_channel_refs(include_optional);

	cJSON* jsonchannel_refs_1 = channel_refs_convertToJSON(channel_refs_1);
	printf("channel_refs :\n%s\n", cJSON_Print(jsonchannel_refs_1));
	channel_refs_t* channel_refs_2 = channel_refs_parseFromJSON(jsonchannel_refs_1);
	cJSON* jsonchannel_refs_2 = channel_refs_convertToJSON(channel_refs_2);
	printf("repeating channel_refs:\n%s\n", cJSON_Print(jsonchannel_refs_2));
}

int main() {
  test_channel_refs(1);
  test_channel_refs(0);

  printf("Hello world \n");
  return 0;
}

#endif // channel_refs_MAIN
#endif // channel_refs_TEST
