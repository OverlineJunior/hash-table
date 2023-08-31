#include "libs/maybe_int.h"

#define TABLE_SIZE 20

typedef struct {
    MaybeInt table[TABLE_SIZE];
} HashTable;

HashTable hashtable_new();
void hashtable_set(HashTable *ht, char key[], int value);
MaybeInt hashtable_get(HashTable ht, char key[]);
