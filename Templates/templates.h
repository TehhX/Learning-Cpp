#pragma once

#include <iostream>

template <typename T>
inline T max(T x = 0, T y = 1) {
    return x > y ? x : y;
}

template <>
const char* max(const char*, const char*) = delete;