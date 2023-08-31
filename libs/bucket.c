#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "key_value.h"

typedef struct Bucket {
    KeyValue value;
    bool is_empty;
    struct Bucket *next;
} Bucket;

Bucket *bucket_new(void) {
    Bucket *b = malloc(sizeof(Bucket));

    if (b == NULL) {
        printf("Failed to allocate memory for Bucket");
        exit(EXIT_FAILURE);
    }

    b->value = keyvalue_new("", 0);
    b->is_empty = true;
    b->next = NULL;

    return b;
}
