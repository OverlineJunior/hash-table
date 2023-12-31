#include "libs/maybe_int.h"

#define TABLE_SIZE 20
#define KEY_SIZE 50

typedef struct {
    char key[KEY_SIZE];
    int value;
} Entry;

typedef struct {
    Entry table[TABLE_SIZE][TABLE_SIZE];
    int len;
} HashTable;

HashTable hashtable_new(void);
void hashtable_set(HashTable *ht, char key[], int value);
MaybeInt hashtable_get(HashTable ht, char key[]);
void hashtable_del(HashTable *ht, char key[]);
void hashtable_display(HashTable ht);
