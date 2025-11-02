#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <memory>

class Person {
protected:
    std::string firstName;
    std::string lastName;
    std::string phone;
    std::string email;

public:
    Person(const std::string& first, const std::string& last, 
           const std::string& phone, const std::string& email);
    virtual ~Person() = default;

    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getPhone() const { return phone; }
    std::string getEmail() const { return email; }

    void setFirstName(const std::string& first) { firstName = first; }
    void setLastName(const std::string& last) { lastName = last; }
    void setPhone(const std::string& ph) { phone = ph; }
    void setEmail(const std::string& em) { email = em; }

    virtual std::string getOccupation() const = 0;
    virtual std::string getDetails() const = 0;
    virtual std::unique_ptr<Person> clone() const = 0;

    virtual void displayInfo() const;
    virtual std::string getFullName() const;
};

class Student : public Person {
private:
    std::string university;
    std::string major;
    int year;

public:
    Student(const std::string& first, const std::string& last, 
            const std::string& phone, const std::string& email,
            const std::string& uni, const std::string& maj, int y);
    
    std::string getOccupation() const override;
    std::string getDetails() const override;
    std::unique_ptr<Person> clone() const override;
    
    // Геттеры для специфичных полей
    std::string getUniversity() const { return university; }
    std::string getMajor() const { return major; }
    int getYear() const { return year; }
};

class Teacher : public Person {
private:
    std::string school;
    std::string subject;
    std::string degree;

public:
    Teacher(const std::string& first, const std::string& last, 
            const std::string& phone, const std::string& email,
            const std::string& sch, const std::string& subj, const std::string& deg);
    
    std::string getOccupation() const override;
    std::string getDetails() const override;
    std::unique_ptr<Person> clone() const override;
    
    std::string getSchool() const { return school; }
    std::string getSubject() const { return subject; }
    std::string getDegree() const { return degree; }
};

class Colleague : public Person {
private:
    std::string company;
    std::string position;
    std::string department;

public:
    Colleague(const std::string& first, const std::string& last, 
              const std::string& phone, const std::string& email,
              const std::string& comp, const std::string& pos, const std::string& dept);
    
    std::string getOccupation() const override;
    std::string getDetails() const override;
    std::unique_ptr<Person> clone() const override;
    
    std::string getCompany() const { return company; }
    std::string getPosition() const { return position; }
    std::string getDepartment() const { return department; }
};

#endif