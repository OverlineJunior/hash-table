#define TABLE_SIZE 20

typedef struct {
    int table[TABLE_SIZE];
} HashTable;

HashTable hashtable_new();
void hashtable_set(HashTable *ht, char key[], int value);
int hashtable_get(HashTable ht, char key[]);
