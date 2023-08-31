#include <string.h>

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
    int table[TABLE_SIZE];
} HashTable;

HashTable hashtable_new() {
    HashTable ht = {};
    return ht;
}

void hashtable_set(HashTable *ht, char key[], int value) {
    ht->table[hash(key)] = value;
}

int hashtable_get(HashTable ht, char key[]) {
    return ht.table[hash(key)];
}
