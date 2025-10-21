#include <iostream>
#include <fstream>
using namespace std;

int sumArray(int size, int arr[]) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return sum;
}

double averageArray(int size, int arr[]) {
    int sum = sumArray(size, arr);
    return static_cast<double>(sum) / size;
}

int sumNegative(int size, int arr[]) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] < 0) sum += arr[i];
    return sum;
}

int sumPositive(int size, int arr[]) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] > 0) sum += arr[i];
    return sum;
}

int sumEvenIndexes(int size, int arr[]) {
    int sum = 0;
    for (int i = 0; i < size; i += 2) sum += arr[i];
    return sum;
}

int sumOddIndexes(int size, int arr[]) {
    int sum = 0;
    for (int i = 1; i < size; i += 2) sum += arr[i];
    return sum;
}

void findMinMax(int size, int arr[], int &minIndex, int &maxIndex) {
    minIndex = maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) minIndex = i;
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }
}

int productBetweenMinMax(int size, int arr[]) {
    int minIdx, maxIdx;
    findMinMax(size, arr, minIdx, maxIdx);

    if (abs(maxIdx - minIdx) <= 1) return 0;
    int start = min(minIdx, maxIdx);
    int end = max(minIdx, maxIdx);

    int product = 1;
    for (int i = start + 1; i < end; i++) {
        product *= arr[i];
    }
    return product;
}

void selectionSort(int size, int arr[]) {
    int minIdx, buf;
    for (int i = 0; i < size; i++) {
        minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        if (minIdx != i) {
            buf = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = buf;
        }
    }
}

int main() {
    const int n = 10;
    int mas[n];

    for (int i = 0; i < n; i++) {
        cout << "mas[" << i << "] = ";
        cin >> mas[i];
    }

    ofstream outFile("arrays.txt");

    if (!outFile) {
        cout << "Не удалось открыть файл для записи!" << endl;
        return 1;
    }

    outFile << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        outFile << mas[i] << " ";
    }
    outFile << endl;

    selectionSort(n, mas);
    outFile << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        outFile << mas[i] << " ";
    }
    outFile << endl;

    outFile.close();
    cout << "Массивы сохранены в файл arrays.txt." << endl;

    return 0;
}
