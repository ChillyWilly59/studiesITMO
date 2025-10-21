#include <iostream>
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

    cout << "\n--- ОБРАБОТКА МАССИВА ---\n";
    cout << "Сумма элементов: " << sumArray(n, mas) << endl;
    cout << "Среднее значение: " << averageArray(n, mas) << endl;
    cout << "Сумма отрицательных: " << sumNegative(n, mas) << endl;
    cout << "Сумма положительных: " << sumPositive(n, mas) << endl;
    cout << "Сумма с четными индексами: " << sumEvenIndexes(n, mas) << endl;
    cout << "Сумма с нечетными индексами: " << sumOddIndexes(n, mas) << endl;

    int minIdx, maxIdx;
    findMinMax(n, mas, minIdx, maxIdx);
    cout << "Минимальный элемент на индексе: " << minIdx << endl;
    cout << "Максимальный элемент на индексе: " << maxIdx << endl;
    cout << "Произведение между ними: " << productBetweenMinMax(n, mas) << endl;

    cout << "\n--- СОРТИРОВКА МАССИВА ---\n";
    selectionSort(n, mas);
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) cout << mas[i] << '\t';
    cout << endl;

    return 0;
}

