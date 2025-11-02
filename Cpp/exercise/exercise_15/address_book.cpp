#include "address_book.h"

#include <algorithm>
#include <fstream>
#include <iostream>

AddressBook* AddressBook::instance = nullptr;

AddressBook* AddressBook::getInstance() {
    if (instance == nullptr) {
        instance = new AddressBook();
    }
    return instance;
}

void AddressBook::addContact(std::unique_ptr<Person> person) {
    contacts.push_back(std::move(person));
}

bool AddressBook::removeContact(const std::string& firstName, const std::string& lastName) {
    auto it = std::remove_if(contacts.begin(), contacts.end(),
        [&](const std::unique_ptr<Person>& person) {
            return person->getFirstName() == firstName && person->getLastName() == lastName;
        });
    
    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        return true;
    }
    return false;
}

void AddressBook::displayAllContacts() const {
    if (contacts.empty()) {
        std::cout << "Адресная книга пуста." << std::endl;
        return;
    }
    
    std::cout << "=== ВСЕ КОНТАКТЫ ===" << std::endl;
    for (const auto& contact : contacts) {
        contact->displayInfo();
    }
}

std::vector<Person*> AddressBook::findContactsByName(const std::string& name) const {
    std::vector<Person*> result;
    for (const auto& contact : contacts) {
        if (contact->getFullName().find(name) != std::string::npos) {
            result.push_back(contact.get());
        }
    }
    return result;
}

std::vector<Person*> AddressBook::findContactsByOccupation(const std::string& occupation) const {
    std::vector<Person*> result;
    for (const auto& contact : contacts) {
        if (contact->getOccupation() == occupation) {
            result.push_back(contact.get());
        }
    }
    return result;
}

bool AddressBook::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    
    for (const auto& contact : contacts) {
        file << contact->getFullName() << "|"
             << contact->getPhone() << "|"
             << contact->getEmail() << "|"
             << contact->getOccupation() << "|"
             << contact->getDetails() << "\n";
    }
    
    file.close();
    return true;
}

bool AddressBook::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << "Загружена запись: " << line << std::endl;
    }
    
    file.close();
    return true;
}