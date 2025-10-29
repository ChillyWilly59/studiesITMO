#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

int FindMaxEven(const std::vector<int>& numbers) {
    auto it = std::max_element(numbers.begin(), numbers.end(),
        [](int a, int b) {
            bool a_even = (a % 2 == 0);
            bool b_even = (b % 2 == 0);
            if (!a_even && !b_even) return false;
            if (!a_even) return true;
            if (!b_even) return false;
            return a < b;
        });

    if (it == numbers.end() || *it % 2 != 0) {
        throw std::runtime_error("No even numbers found");
    }

    return *it;
}

int main() {
    std::vector<int> vec1 = {1, 3, 5, 8, 12, 7, 6};
    std::vector<int> vec2 = {1, 3, 5, 7};
    std::vector<int> vec3 = {2, 4, 6, 8, 10};

    try {
        std::cout << "Max even in vec1: " << FindMaxEven(vec1) << std::endl;
        std::cout << "Max even in vec3: " << FindMaxEven(vec3) << std::endl;
        std::cout << "Max even in vec2: " << FindMaxEven(vec2) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}