#include <stdio.h>
#include "../hash_table.h"

int main(void) {
    HashTable ht = hashtable_new();

    // Both keys have the same hash.
    hashtable_set(&ht, "12", 1);
    hashtable_set(&ht, "03", 2);

    printf(
        "[%s]: %i\n",
        "12",
        hashtable_get(ht, "12").value
    );

    printf(
        "[%s]: %i\n",
        "03",
        hashtable_get(ht, "03").value
    );
}
