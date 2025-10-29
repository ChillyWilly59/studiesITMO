#include <iostream>
#include <vector>
#include <string>
#include <complex>

template<typename T>
concept Sortable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
    { a > b } -> std::convertible_to<bool>;
};

template<typename Iterator>
requires Sortable<typename Iterator::value_type>
bool is_sorted(Iterator begin, Iterator end) {
    if (begin == end) return true;

    Iterator prev = begin;
    Iterator current = begin;
    ++current;

    while (current != end) {
        if (*current < *prev) {
            return false;
        }
        ++prev;
        ++current;
    }
    return true;
}

int main() {
    std::vector<int> sorted_int = {1, 2, 3, 4, 5};
    std::vector<int> unsorted_int = {1, 3, 2, 4, 5};

    std::cout << "sorted_int is sorted: " << is_sorted(sorted_int.begin(), sorted_int.end()) << std::endl;
    std::cout << "unsorted_int is sorted: " << is_sorted(unsorted_int.begin(), unsorted_int.end()) << std::endl;

    std::vector<std::string> sorted_str = {"apple", "banana", "cherry"};
    std::vector<std::string> unsorted_str = {"banana", "apple", "cherry"};

    std::cout << "sorted_str is sorted: " << is_sorted(sorted_str.begin(), sorted_str.end()) << std::endl;
    std::cout << "unsorted_str is sorted: " << is_sorted(unsorted_str.begin(), unsorted_str.end()) << std::endl;

    std::vector<std::complex<double>> complex_vec = {{1.0, 2.0}, {3.0, 4.0}};

    return 0;
}