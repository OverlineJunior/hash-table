#include <stdio.h>
#include <string.h>
#include "libs/maybe_int.h"

#define TABLE_SIZE 20
#define KEY_SIZE 50
#define EMPTY_KEY "__EMPTY__"

// Returns the sum of the ASCII code of each char in str.
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
    char key[KEY_SIZE];
    int value;
} Entry;

Entry entry_new(char key[], int value) {
    Entry e;
    e.value = value;
    strcpy(e.key, key);

    return e;
}

typedef struct {
    Entry table[TABLE_SIZE][TABLE_SIZE];
    int len;
} HashTable;

// Returns a new, empty HashTable.
HashTable hashtable_new(void) {
    HashTable ht = {};
    ht.len = 0;

    // Initialize table with keys marked as empty to show availability later on.
    for (int i = 0; i < TABLE_SIZE; i++)
        for (int j = 0; j < TABLE_SIZE; j++)
            ht.table[i][j] = entry_new(EMPTY_KEY, 0);

    return ht;
}

// Returns the key's value if it exists, else none.
MaybeInt hashtable_get(HashTable ht, char key[]) {
    int bucket_i = hash(key);

    for (int i = 0; i < TABLE_SIZE; i++)
        if (strcmp(ht.table[bucket_i][i].key, key) == 0)
            return some(ht.table[bucket_i][i].value);

    return none();
}

// Inserts a new key with a value. Replaces previous key with the same name.
void hashtable_set(HashTable *ht, char key[], int value) {
    int bucket_i = hash(key);
    bool should_replace = hashtable_get(*ht, key).is_some;

    for (int i = 0; i < TABLE_SIZE; i++) {
        bool can_set = should_replace
            ? strcmp(ht->table[bucket_i][i].key, key) == 0
            : strcmp(ht->table[bucket_i][i].key, EMPTY_KEY) == 0;

        if (can_set) {
            ht->table[bucket_i][i] = entry_new(key, value);
            break;
        }
    }
}

// Removes a key.
void hashtable_del(HashTable *ht, char key[]) {
    int bucket_i = hash(key);

    for (int i = 0; i < TABLE_SIZE; i++)
        if (strcmp(ht->table[bucket_i][i].key, key) == 0) {
            ht->table[bucket_i][i] = entry_new(EMPTY_KEY, 0);
            break;
        }
}

// Displays each key value pairs.
void hashtable_display(HashTable ht) {
    printf("{\n");

    for (int i = 0; i < TABLE_SIZE; i++)
        for (int j = 0; j < TABLE_SIZE; j++)
            if (strcmp(ht.table[i][j].key, EMPTY_KEY) != 0)
                printf("    [%s]: %i\n", ht.table[i][j].key, ht.table[i][j].value);

    printf("}\n");
}
