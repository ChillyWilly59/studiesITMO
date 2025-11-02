#include <iostream>

#include "ui_interface.h"

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "=== ПРИЛОЖЕНИЕ 'АДРЕСНАЯ КНИГА' ===" << std::endl;

    UIInterface ui;
    ui.showMainMenu();

    return 0;
}