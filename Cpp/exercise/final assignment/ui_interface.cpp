#include "ui_interface.h"
#include <iostream>
#include <limits>

UIInterface::UIInterface() {
    addressBook = AddressBook::getInstance();
}

void UIInterface::showMainMenu() {
    int choice;
    
    do {
        std::cout << "\n=== АДРЕСНАЯ КНИГА ===" << std::endl;
        std::cout << "1. Добавить контакт" << std::endl;
        std::cout << "2. Удалить контакт" << std::endl;
        std::cout << "3. Показать все контакты" << std::endl;
        std::cout << "4. Поиск контактов" << std::endl;
        std::cout << "5. Сохранить в файл" << std::endl;
        std::cout << "6. Загрузить из файла" << std::endl;
        std::cout << "7. Статистика" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите действие: ";
        
        std::cin >> choice;
        std::cin.ignore(); // Очистка буфера
        
        switch (choice) {
            case 1: addContact(); break;
            case 2: removeContact(); break;
            case 3: displayAllContacts(); break;
            case 4: searchContacts(); break;
            case 5: saveToFile(); break;
            case 6: loadFromFile(); break;
            case 7: showStatistics(); break;
            case 0: std::cout << "До свидания!" << std::endl; break;
            default: std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
}

void UIInterface::addContact() {
    std::cout << "\n=== ДОБАВЛЕНИЕ КОНТАКТА ===" << std::endl;
    
    int type;
    std::cout << "Выберите тип контакта:" << std::endl;
    std::cout << "1. Студент" << std::endl;
    std::cout << "2. Преподаватель" << std::endl;
    std::cout << "3. Коллега" << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> type;
    std::cin.ignore();
    
    setupFactory(type);
    
    std::string first = getInput("Введите имя: ");
    std::string last = getInput("Введите фамилию: ");
    std::string phone = getInput("Введите телефон: ");
    std::string email = getInput("Введите email: ");
    
    auto person = currentFactory->createPerson(first, last, phone, email);
    addressBook->addContact(std::move(person));
    
    std::cout << "Контакт успешно добавлен!" << std::endl;
}

void UIInterface::removeContact() {
    std::cout << "\n=== УДАЛЕНИЕ КОНТАКТА ===" << std::endl;
    
    std::string first = getInput("Введите имя: ");
    std::string last = getInput("Введите фамилию: ");
    
    if (addressBook->removeContact(first, last)) {
        std::cout << "Контакт успешно удален!" << std::endl;
    } else {
        std::cout << "Контакт не найден!" << std::endl;
    }
}

void UIInterface::displayAllContacts() {
    addressBook->displayAllContacts();
}

void UIInterface::searchContacts() {
    std::cout << "\n=== ПОИСК КОНТАКТОВ ===" << std::endl;
    
    int choice;
    std::cout << "1. Поиск по имени" << std::endl;
    std::cout << "2. Поиск по роду занятий" << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> choice;
    std::cin.ignore();
    
    std::vector<Person*> results;
    
    if (choice == 1) {
        std::string name = getInput("Введите имя для поиска: ");
        results = addressBook->findContactsByName(name);
    } else if (choice == 2) {
        std::string occupation = getInput("Введите род занятий: ");
        results = addressBook->findContactsByOccupation(occupation);
    } else {
        std::cout << "Неверный выбор!" << std::endl;
        return;
    }
    
    if (results.empty()) {
        std::cout << "Контакты не найдены." << std::endl;
    } else {
        std::cout << "=== РЕЗУЛЬТАТЫ ПОИСКА ===" << std::endl;
        for (auto contact : results) {
            contact->displayInfo();
        }
    }
}

void UIInterface::saveToFile() {
    std::string filename = getInput("Введите имя файла для сохранения: ");
    if (addressBook->saveToFile(filename)) {
        std::cout << "Данные успешно сохранены!" << std::endl;
    } else {
        std::cout << "Ошибка сохранения!" << std::endl;
    }
}

void UIInterface::loadFromFile() {
    std::string filename = getInput("Введите имя файла для загрузки: ");
    if (addressBook->loadFromFile(filename)) {
        std::cout << "Данные успешно загружены!" << std::endl;
    } else {
        std::cout << "Ошибка загрузки!" << std::endl;
    }
}

void UIInterface::showStatistics() {
    std::cout << "\n=== СТАТИСТИКА ===" << std::endl;
    std::cout << "Общее количество контактов: " << addressBook->getContactCount() << std::endl;
}

void UIInterface::setupFactory(int choice) {
    switch (choice) {
        case 1: currentFactory = std::make_unique<StudentFactory>(); break;
        case 2: currentFactory = std::make_unique<TeacherFactory>(); break;
        case 3: currentFactory = std::make_unique<ColleagueFactory>(); break;
        default: currentFactory = std::make_unique<StudentFactory>();
    }
}

std::string UIInterface::getInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}