#ifndef versioned_TEST
#define versioned_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define versioned_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/versioned.h"
versioned_t* instantiate_versioned(int include_optional);



versioned_t* instantiate_versioned(int include_optional) {
  versioned_t* versioned = NULL;
  if (include_optional) {
    versioned = versioned_create(
      1,
      "9bd5454"
    );
  } else {
    versioned = versioned_create(
      1,
      "9bd5454"
    );
  }

  return versioned;
}


#ifdef versioned_MAIN

void test_versioned(int include_optional) {
    versioned_t* versioned_1 = instantiate_versioned(include_optional);

	cJSON* jsonversioned_1 = versioned_convertToJSON(versioned_1);
	printf("versioned :\n%s\n", cJSON_Print(jsonversioned_1));
	versioned_t* versioned_2 = versioned_parseFromJSON(jsonversioned_1);
	cJSON* jsonversioned_2 = versioned_convertToJSON(versioned_2);
	printf("repeating versioned:\n%s\n", cJSON_Print(jsonversioned_2));
}

int main() {
  test_versioned(1);
  test_versioned(0);

  printf("Hello world \n");
  return 0;
}

#endif // versioned_MAIN
#endif // versioned_TEST
