#include <string.h>
#include "libs/maybe_int.h"

#define TABLE_SIZE 20

int ascii_sum(char str[]) {
    int sum = 0;

    for (int i = 0; i < strlen(str); i++)
        sum += (int)str[i];

    return sum;
}

int hash(char key[]) {
    return ascii_sum(key) % TABLE_SIZE;
}

typedef struct {
    MaybeInt table[TABLE_SIZE];
} HashTable;

HashTable hashtable_new() {
    HashTable ht = {};

    for (int i = 0; i < TABLE_SIZE; i++)
        ht.table[i] = none();

    return ht;
}

void hashtable_set(HashTable *ht, char key[], int value) {
    ht->table[hash(key)] = some(value);
}

MaybeInt hashtable_get(HashTable ht, char key[]) {
    return ht.table[hash(key)];
}
