#ifndef channel_country_TEST
#define channel_country_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define channel_country_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/channel_country.h"
channel_country_t* instantiate_channel_country(int include_optional);



channel_country_t* instantiate_channel_country(int include_optional) {
  channel_country_t* channel_country = NULL;
  if (include_optional) {
    channel_country = channel_country_create(
      "GhDXw4EW",
      "United States"
    );
  } else {
    channel_country = channel_country_create(
      "GhDXw4EW",
      "United States"
    );
  }

  return channel_country;
}


#ifdef channel_country_MAIN

void test_channel_country(int include_optional) {
    channel_country_t* channel_country_1 = instantiate_channel_country(include_optional);

	cJSON* jsonchannel_country_1 = channel_country_convertToJSON(channel_country_1);
	printf("channel_country :\n%s\n", cJSON_Print(jsonchannel_country_1));
	channel_country_t* channel_country_2 = channel_country_parseFromJSON(jsonchannel_country_1);
	cJSON* jsonchannel_country_2 = channel_country_convertToJSON(channel_country_2);
	printf("repeating channel_country:\n%s\n", cJSON_Print(jsonchannel_country_2));
}

int main() {
  test_channel_country(1);
  test_channel_country(0);

  printf("Hello world \n");
  return 0;
}

#endif // channel_country_MAIN
#endif // channel_country_TEST
