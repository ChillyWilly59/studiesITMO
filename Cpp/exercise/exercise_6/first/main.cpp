#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("poem.txt");

    if (!outFile) {
        cout << "Не удалось открыть файл для записи!" << endl;
        return 1;
    }

    string line;
    cout << "Введите стихотворение (для завершения ввода введите пустую строку):\n";
    while (true) {
        getline(cin, line);
        if (line.empty()) break;
        outFile << line << endl;
    }

    outFile.close();
    cout << "Стихотворение записано в файл poem.txt." << endl;

    return 0;
}
