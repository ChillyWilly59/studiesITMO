#include <iostream>
#include <concepts>

template<typename T>
concept Comparable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
};

template<Comparable T>
T maxOfTwo(const T& a, const T& b) {
    return (a < b) ? b : a;
}

class MyClass {
private:
    int value;
public:
    MyClass(int v) : value(v) {}
    bool operator<(const MyClass& other) const {
        return value < other.value;
    }
    friend std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
        os << obj.value;
        return os;
    }
};

int main() {
    std::cout << "maxOfTwo(5, 10): " << maxOfTwo(5, 10) << std::endl;
    std::cout << "maxOfTwo(3.14, 2.71): " << maxOfTwo(3.14, 2.71) << std::endl;

    MyClass obj1(15), obj2(25);
    std::cout << "maxOfTwo(MyClass(15), MyClass(25)): " << maxOfTwo(obj1, obj2) << std::endl;

    return 0;
}