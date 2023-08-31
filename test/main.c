#include <stdio.h>
#include "../libs/bucket.h"

int main(void) {
    Bucket *b = bucket_new();
    printf("%i", b->is_empty);
}
