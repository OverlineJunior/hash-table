#include <stdio.h>
#include <stdlib.h>
#include "key_value.h"

typedef struct Bucket {
    KeyValue *elements;
    int len;
    int capacity;
} Bucket;

Bucket *bucket_new(int capacity) {
    Bucket *bucket = malloc(sizeof(Bucket));

    if (bucket == NULL) {
        printf("Failed to allocate memory for Bucket");
        exit(EXIT_FAILURE);
    }

    bucket->elements = malloc(capacity * sizeof(KeyValue));

    if (bucket->elements == NULL) {
        printf("Failed to allocate memory for Bucket.elements");
        exit(EXIT_FAILURE);
    }

    bucket->len = 0;
    bucket->capacity = capacity;

    return bucket;
}
