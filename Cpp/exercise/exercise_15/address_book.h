#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include "person.h"
#include <vector>
#include <memory>
#include <string>

class AddressBook {
private:
    static AddressBook* instance;
    std::vector<std::unique_ptr<Person>> contacts;

    AddressBook() = default;
    AddressBook(const AddressBook&) = delete;
    AddressBook& operator=(const AddressBook&) = delete;

public:
    static AddressBook* getInstance();

    void addContact(std::unique_ptr<Person> person);
    bool removeContact(const std::string& firstName, const std::string& lastName);
    void displayAllContacts() const;

    std::vector<Person*> findContactsByName(const std::string& name) const;
    std::vector<Person*> findContactsByOccupation(const std::string& occupation) const;

    bool saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);

    size_t getContactCount() const { return contacts.size(); }

    const std::vector<std::unique_ptr<Person>>& getContacts() const { return contacts; }

    void clear() { contacts.clear(); }
};

#endif