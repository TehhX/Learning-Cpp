/*
    std::async, promise, and future may be used as a higher level way to do the same things in this example.
*/

#include <iostream>
#include <thread>

void squareArea(int *sideLength) {
    *sideLength *= *sideLength;
}

int getNewID() {
    static int id { 0 };
    return id++;
}

void bigCalc(int x, int *ret) {
    double val { 1e+100 - x };

    for (size_t i { 0 }; i < 750000000; i++) {
        val /= i * 0.1f;
    }

    *ret = val;
}

int main() {
    int width { 7 };

    // Thread runs on construction
    // Callback pointer, arguments to callback pointer
    std::thread threadOne { squareArea, &width };
    std::cout << "Working...\n";

    // Wait until threadOne finishes
    threadOne.join();
    std::cout << "Value: " << width << '\n';

    // Run 10 threads using lambda
    std::cout << "\nCreating 10 threads...\n";
    void (*printNewID)() { []() -> void { std::cout << "ID: " << getNewID() << '\n'; } };
    std::thread threads[] {
        std::thread { printNewID },
        std::thread { printNewID },
        std::thread { printNewID },
        std::thread { printNewID },
        std::thread { printNewID },
        std::thread { printNewID },
        std::thread { printNewID },
        std::thread { printNewID },
        std::thread { printNewID },
        std::thread { printNewID }
    };

    for (auto &t : threads)
        t.join();

    std::cout << "Finished.\n";

    // Start threads
    int calcHolder;
    std::cout << "\nDoing large calculation...\n";
    std::thread calcThread { bigCalc, 2, &calcHolder };

    // Do things in the meantime
    std::cout << "In progress...\n";
    std::cout << "Still in progress...\n";

    // Join up
    calcThread.join();
    std::cout << "Value: " << calcHolder << '\n';
}
