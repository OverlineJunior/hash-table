#include <stdio.h>
#include "../libs/bucket.h"

int main(void) {
    Bucket *b = bucket_new(5);
    bucket_push(b, keyvalue_new("A", 1));
    bucket_push(b, keyvalue_new("B", 2));
    printf(
        "%i, %i",
        bucket_get(b, 0).value,
        bucket_get(b, 1).value
    );
}
