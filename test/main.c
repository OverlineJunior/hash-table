#include <stdio.h>
#include "../hash_table.h"

int main(void) {
    HashTable ht = hashtable_new();
    hashtable_set(&ht, "foo", 555);
    hashtable_set(&ht, "bar", 222);
    hashtable_set(&ht, "baz", 333);
    hashtable_display(ht);
}
