#include <string.h>

#define KEY_SIZE 50

typedef struct {
    char key[KEY_SIZE];
    int value;
} KeyValue;

KeyValue keyvalue_new(char key[], int value) {
    KeyValue kv = {};
    kv.value = value;
    strcpy(kv.key, key);

    return kv;
}
