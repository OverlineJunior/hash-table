#include <stdbool.h>

typedef struct {
    bool is_some;
    int value;
} MaybeInt;

MaybeInt some(int value);
MaybeInt none(void);
