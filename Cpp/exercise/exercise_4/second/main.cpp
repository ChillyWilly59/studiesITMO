#include <iostream>

bool Input(int& i, int& b) {
if (!(std::cin >> i)) {
    std::cerr << "error: input error" << std::endl;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    return false;
}
    if (!(std::cin >> b)) {
        std::cerr << "error: input error" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return false;
    }
    return true;
};

int main()
{
    int a, b;
    if(Input(a,b)== false)
    {
        std::cerr << "error";
        return 1;
    }
    int s = a + b;
    std::cout << "Sum is: " << s << std::endl;
    return 0;
}
