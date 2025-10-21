#include <iostream>
using namespace std;

int sequentialSearchWithTransposition(int arr[], int size, int key) {
    for (int i = 1; i < size; i++) {
        if (arr[i] == key) {
            swap(arr[i], arr[i - 1]);
            return i - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {5, 3, 8, 6, 2, 7, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 6;

    int index = sequentialSearchWithTransposition(arr, size, key);

    if (index != -1) {
        cout << "Элемент " << key << " найден по индексу " << index << endl;
        cout << "Массив после транспозиции: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Элемент не найден!" << endl;
    }

    return 0;
}
