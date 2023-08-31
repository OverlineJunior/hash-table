#include <stdio.h>
#include "../libs/bucket.h"

int main(void) {
    Bucket *b = bucket_new(5);
    printf("%i, %i", b->len, b->capacity);
}
