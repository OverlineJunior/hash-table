#define TABLE_SIZE 20

typedef struct {
    int table[TABLE_SIZE];
} HashTable;

HashTable hashtable_new();
