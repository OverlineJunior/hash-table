#include <stdbool.h>

typedef struct {
    bool is_some;
    int value;
} MaybeInt;

MaybeInt some(int value) {
    MaybeInt res = {
        .is_some = true,
        .value = value,
    };

    return res;
}

MaybeInt none(void) {
    MaybeInt res = {
        .is_some = false,
        .value = 0,
    };

    return res;
}
