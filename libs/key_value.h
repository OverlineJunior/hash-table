#define KEY_SIZE 50

typedef struct {
    char key[KEY_SIZE];
    int value;
} KeyValue;

KeyValue keyvalue_new(char key[], int value);
