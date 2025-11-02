#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include "address_book.h"
#include "person_factory.h"
#include <memory>

class UIInterface {
private:
    AddressBook* addressBook;
    std::unique_ptr<PersonFactory> currentFactory;

public:
    UIInterface();
    ~UIInterface() = default;

    void showMainMenu();
    void addContact();
    void removeContact();
    void displayAllContacts();
    void searchContacts();
    void saveToFile();
    void loadFromFile();
    void showStatistics();

private:
    void setupFactory(int choice);
    std::string getInput(const std::string& prompt);
};

#endif