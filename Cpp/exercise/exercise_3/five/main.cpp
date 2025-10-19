#include <iostream>
#include <string>
#include <cstddef>
using namespace std;



void decimalToBinary(int number) {
    if (number == 0) {
        return;
    }
    decimalToBinary(number / 2);
    cout << number % 2;
}

int main() {


    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (number < 0) {
        cout << " is not a valid number.\n" << endl;
    } else if (number == 0) {
        cout << "Number " << number << " in the binary system: 0" << endl;
    } else {
        cout << "Number " << number << " in the binary system: ";
        decimalToBinary(number);
        cout << endl;
    }

    return 0;
}
