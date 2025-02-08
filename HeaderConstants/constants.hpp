#pragma once

#include <iostream>

namespace Constants {
    // Defined and instantiated not only in the header file, also constant, requires "inline constexpr".
        inline constexpr float gravity {9.81};
        inline constexpr float avogadro {6.0221413e23};
        inline constexpr int funnyNumber {69};

    // Not also defined in header file, no inline needed.
        void fella(); 

    // Defined in header file, inline required.
        inline int otherGuy() {
            return 6969;
        }
}