#pragma once

#include <string>

template <typename T, typename F>
void iter(T* array, size_t length, F func) {
    if (!array || length == 0) {
        return;
    }
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}
