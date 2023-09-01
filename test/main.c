#include <stdio.h>
#include "../hash_table.h"

int main(void) {
    HashTable ht = hashtable_new();
    hashtable_set(&ht, "foo", 555);
    hashtable_del(&ht, "foo");

    printf("is_some: %i\n", hashtable_get(ht, "foo").is_some);
}
