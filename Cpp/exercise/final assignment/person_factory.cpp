#include "person_factory.h"
#include <iostream>

std::unique_ptr<Person> StudentFactory::createPerson(
    const std::string& first, const std::string& last,
    const std::string& phone, const std::string& email) {
    
    std::string university, major;
    int year;
    
    std::cout << "Введите университет: ";
    std::getline(std::cin, university);
    
    std::cout << "Введите специальность: ";
    std::getline(std::cin, major);
    
    std::cout << "Введите курс: ";
    std::cin >> year;
    std::cin.ignore();
    return std::make_unique<Student>(first, last, phone, email, university, major, year);
}

std::unique_ptr<Person> TeacherFactory::createPerson(
    const std::string& first, const std::string& last,
    const std::string& phone, const std::string& email) {
    
    std::string school, subject, degree;
    
    std::cout << "Введите школу/вуз: ";
    std::getline(std::cin, school);
    
    std::cout << "Введите предмет: ";
    std::getline(std::cin, subject);
    
    std::cout << "Введите степень: ";
    std::getline(std::cin, degree);
    
    return std::make_unique<Teacher>(first, last, phone, email, school, subject, degree);
}

std::unique_ptr<Person> ColleagueFactory::createPerson(
    const std::string& first, const std::string& last,
    const std::string& phone, const std::string& email) {
    
    std::string company, position, department;
    
    std::cout << "Введите компанию: ";
    std::getline(std::cin, company);
    
    std::cout << "Введите должность: ";
    std::getline(std::cin, position);
    
    std::cout << "Введите отдел: ";
    std::getline(std::cin, department);
    
    return std::make_unique<Colleague>(first, last, phone, email, company, position, department);
}