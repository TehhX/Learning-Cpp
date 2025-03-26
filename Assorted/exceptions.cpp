#include <iostream>

// noexcept specifier (NOT a keyword) means func cannot throw exceptions.
float add(const float x, const float y) noexcept {
    return x + y;
}

float divide(const float x, const float y) {
    if (y == 0)
        throw "Divide by zero error.\n";

    return x / y;
}

// Base custom exception class:
class MyException {
private:
    std::string errorMsg;

public:
    MyException(const std::string_view errorMsg)
    : errorMsg { errorMsg } {}

    std::string getMsg() const { return errorMsg; }
};

// Division exception for divide:
class DivideByZero : public MyException {
public:
    DivideByZero()
    : MyException { "Attempted to divide by zero." } {}
};

float divideUsingDivideException(const float x, const float y) {
    if (y == 0)
        throw DivideByZero {};
    
    return x / y;
}

std::string getString(const unsigned int x) {
    switch(x) {
    case 0: return "Zero."; break;
    case 1: return  "One."; break;
    case 2: return  "Two."; break;
    default: throw -1;
    }
}

class Thing {
private:
    int id;

public:
    Thing(int id)
    : id { id } {
        if (id < 0)
            throw -1;
    }

    void print() const { std::cout << id << '\n'; }
};

int main() {
    // Non-func calling throws inside try/catch:
    try { throw -1; }
        catch (int e) { std::cerr << "Threw: " << e << '\n'; }

    // divide try/catches WITH funcs:
    try { std::cout << divide(1, 2) << '\n'; }
        catch (const char* e) { std::cerr << e; }

    try { std::cout << divide(5, 0) << '\n'; }
        catch (const char* e) { std::cerr << e; }

    try { std::cout << add(1, 2) << '\n'; }
        catch (const char* e) { std::cerr << e; }

    // getString try/catches WITH funcs:
    try { std::cout << getString(0) << '\n'; }
        catch (const int e) { std::cerr << "Incorrect parameter passed to getString(const unsigned int)\n"; }

    try { std::cout << getString(-1) << '\n'; }
        catch (const int e) { std::cerr << "Incorrect parameter passed to getString(const unsigned int)\n"; }
    
    // divide try/catch block WITH funcs. First attempts to catch incorrect type, then uses catch-all:
    try { std::cout << divide(0, 0) << '\n'; }
        catch (const float e) { std::cerr << "Float exception detected.\n"; }
        catch (...) { std::cerr << "Unknown exception detected.\n"; }
    
    // Throwing within a constructor.
    try {
        Thing thing { 5 };
        thing.print();
    } catch (const int e) { std::cerr << "Exception with thing: " << e << '\n'; }

    try {
        Thing thing { -5 };
        thing.print();
    } catch (const int e) { std::cerr << "Exception with thing: " << e << '\n'; }

    // Using DivideException as the exception type:
    try { std::cout << divideUsingDivideException(5, 0) << '\n'; }
        catch (const DivideByZero& de) { std::cerr << "Error: " << de.getMsg() << '\n'; } // Most specific execption.
        catch (const MyException& me)  { std::cerr << "Error: " << me.getMsg() << '\n'; } // Basest class execption.

    return 0;
}