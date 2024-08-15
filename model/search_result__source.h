/*
 * search_result__source.h
 *
 * 
 */

#ifndef _search_result__source_H_
#define _search_result__source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct search_result__source_t search_result__source_t;




typedef struct search_result__source_t {
    char *code; // string
    char *subtitle; // string
    char *type; // string
    char *title; // string
    char *url; // string

} search_result__source_t;

search_result__source_t *search_result__source_create(
    char *code,
    char *subtitle,
    char *type,
    char *title,
    char *url
);

void search_result__source_free(search_result__source_t *search_result__source);

search_result__source_t *search_result__source_parseFromJSON(cJSON *search_result__sourceJSON);

cJSON *search_result__source_convertToJSON(search_result__source_t *search_result__source);

#endif /* _search_result__source_H_ */

