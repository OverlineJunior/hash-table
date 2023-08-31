#include "key_value.h"

typedef struct Bucket {
    KeyValue *elements;
    int len;
    int capacity;
} Bucket;

Bucket *bucket_new(int capacity);
