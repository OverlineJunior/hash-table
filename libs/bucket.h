#include <stdbool.h>
#include "key_value.h"

typedef struct Bucket {
    KeyValue value;
    bool is_empty;
    struct Bucket *next;
} Bucket;

Bucket *bucket_new(void);
