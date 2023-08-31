#include "key_value.h"

typedef struct Bucket {
    KeyValue *elements;
    int len;
    int capacity;
} Bucket;

Bucket *bucket_new(int capacity);
void bucket_push(Bucket *bucket, KeyValue kv);
KeyValue bucket_get(Bucket *bucket, int index);
void bucket_remove(Bucket *bucket, int index);
