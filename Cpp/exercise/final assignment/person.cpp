#include "person.h"

#include <iostream>

Person::Person(const std::string& first, const std::string& last, 
               const std::string& ph, const std::string& em)
    : firstName(first), lastName(last), phone(ph), email(em) {}

void Person::displayInfo() const {
    std::cout << "Имя: " << getFullName() << std::endl;
    std::cout << "Телефон: " << phone << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Род занятий: " << getOccupation() << std::endl;
    std::cout << "Детали: " << getDetails() << std::endl;
    std::cout << "------------------------" << std::endl;
}

std::string Person::getFullName() const {
    return firstName + " " + lastName;
}

// Реализация класса Student
Student::Student(const std::string& first, const std::string& last, 
                 const std::string& phone, const std::string& email,
                 const std::string& uni, const std::string& maj, int y)
    : Person(first, last, phone, email), university(uni), major(maj), year(y) {}

std::string Student::getOccupation() const {
    return "Студент";
}

std::string Student::getDetails() const {
    return "Университет: " + university + ", Специальность: " + major + ", Курс: " + std::to_string(year);
}

std::unique_ptr<Person> Student::clone() const {
    return std::make_unique<Student>(*this);
}

Teacher::Teacher(const std::string& first, const std::string& last, 
                 const std::string& phone, const std::string& email,
                 const std::string& sch, const std::string& subj, const std::string& deg)
    : Person(first, last, phone, email), school(sch), subject(subj), degree(deg) {}

std::string Teacher::getOccupation() const {
    return "Преподаватель";
}

std::string Teacher::getDetails() const {
    return "Школа: " + school + ", Предмет: " + subject + ", Степень: " + degree;
}

std::unique_ptr<Person> Teacher::clone() const {
    return std::make_unique<Teacher>(*this);
}

Colleague::Colleague(const std::string& first, const std::string& last, 
                     const std::string& phone, const std::string& email,
                     const std::string& comp, const std::string& pos, const std::string& dept)
    : Person(first, last, phone, email), company(comp), position(pos), department(dept) {}

std::string Colleague::getOccupation() const {
    return "Коллега";
}

std::string Colleague::getDetails() const {
    return "Компания: " + company + ", Должность: " + position + ", Отдел: " + department;
}

std::unique_ptr<Person> Colleague::clone() const {
    return std::make_unique<Colleague>(*this);
}