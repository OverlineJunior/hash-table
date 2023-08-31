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
        printf("Failed to allocate memory for Bucket\n");
        exit(EXIT_FAILURE);
    }

    bucket->elements = malloc(capacity * sizeof(KeyValue));

    if (bucket->elements == NULL) {
        printf("Failed to allocate memory for Bucket.elements\n");
        exit(EXIT_FAILURE);
    }

    bucket->len = 0;
    bucket->capacity = capacity;

    return bucket;
}

void bucket_push(Bucket *bucket, KeyValue kv) {
    if (bucket->len >= bucket->capacity) {
        printf("Cannot exceed Bucket's capacity\n");
        exit(EXIT_FAILURE);
    }

    bucket->elements[bucket->len] = kv;
    bucket->len++;
}

KeyValue bucket_get(Bucket *bucket, int index) {
    if (index >= bucket->len) {
        printf("Index cannot exceed Bucket's length\n");
        exit(EXIT_FAILURE);
    }

    return bucket->elements[index];
}

void bucket_remove(Bucket *bucket, int index) {
    if (index >= bucket->len) {
        printf("Index cannot exceed Bucket's length\n");
        exit(EXIT_FAILURE);
    }

    // Shift down elements after the index.
    for (int i = index; i < bucket->len; i++)
        bucket->elements[i] = bucket->elements[i + 1];

    bucket->len--;
}
