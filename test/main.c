#include <stdio.h>
#include "../hash_table.h"

int main(void) {
    HashTable table = hashtable_new();
    hashtable_set(&table, "foo", 1);
    hashtable_set(&table, "bar", 2);

    printf("foo: %i, bar: %i\n", hashtable_get(table, "foo"), hashtable_get(table, "bar"));
}
