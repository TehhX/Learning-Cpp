#include <iostream>
#include <vector>

namespace Compare {
    template <typename T>
    std::vector<T> static getUnion(const std::vector<T>& a, const std::vector<T> b) {
        std::vector<T> arr (a.size() + b.size());

        int i { 0 };

        bool aLarger { a.size() > b.size() };

        for (int o { 0 }; o < (aLarger ? b.size() : a.size()); o++) {
            arr[i++] = a[o];
            arr[i++] = b[o];
        }

        for (; i < (aLarger ? a.size() : b.size()); i++)
            arr[i] = aLarger ? a[i] : b[i];

        return arr;
    }

    template <typename T>
    std::vector<T> static getIntersection(const std::vector<T>& a, const std::vector<T>& b) {
        std::vector<T> arr {};

        for (int i { 0 }; i < a.size(); i++) {
            if (a[i] == b[i]) {
                arr.push_back(a[i]);
                continue;
            }

            else
                for (int o { 0 }; o < b.size(); o++)
                    if (a[i] == b[o]) {
                        arr.push_back(a[i]);
                        continue;
                    }
        }

        return arr;
    }
}

template <typename T>
void printVector(const std::string_view prefix, const std::vector<T>& arr) {
    if (arr.empty())
        return;

    for (const auto& i : arr)
        std::cout << i << ' ';

    std::cout << '\n';
}

int main() {
    std::vector setOne { 1, 2, 3 };
    std::vector setTwo { 3, 4, 5 };

    std::vector setUnion        {        Compare::getUnion(setOne, setTwo) };
    std::vector setIntersection { Compare::getIntersection(setOne, setTwo) };

    printVector("Union:        ",        setUnion);
    printVector("Intersection: ", setIntersection);
}