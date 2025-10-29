#include <iostream>

template<typename T>
T average(T arr[], int size) {
    T sum = T();
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    std::cout << "int average: " << average(intArr, 5) << std::endl;

    long longArr[] = {10L, 20L, 30L};
    std::cout << "long average: " << average(longArr, 3) << std::endl;

    double doubleArr[] = {1.5, 2.5, 3.5};
    std::cout << "double average: " << average(doubleArr, 3) << std::endl;

    char charArr[] = {10, 20, 30};
    std::cout << "char average: " << static_cast<int>(average(charArr, 3)) << std::endl;

    return 0;
}