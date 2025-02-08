#pragma once

#include <iostream>

void addEm();

// No inline required
template <typename T>
T add(T x, T y) {
    return x + y;
}