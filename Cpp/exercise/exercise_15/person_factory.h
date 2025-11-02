#ifndef PERSON_FACTORY_H
#define PERSON_FACTORY_H

#include "person.h"
#include <memory>

class PersonFactory {
public:
    virtual ~PersonFactory() = default;
    virtual std::unique_ptr<Person> createPerson(
        const std::string& first, const std::string& last,
        const std::string& phone, const std::string& email) = 0;
};

class StudentFactory : public PersonFactory {
public:
    std::unique_ptr<Person> createPerson(
        const std::string& first, const std::string& last,
        const std::string& phone, const std::string& email) override;
};

class TeacherFactory : public PersonFactory {
public:
    std::unique_ptr<Person> createPerson(
        const std::string& first, const std::string& last,
        const std::string& phone, const std::string& email) override;
};

class ColleagueFactory : public PersonFactory {
public:
    std::unique_ptr<Person> createPerson(
        const std::string& first, const std::string& last,
        const std::string& phone, const std::string& email) override;
};

#endif