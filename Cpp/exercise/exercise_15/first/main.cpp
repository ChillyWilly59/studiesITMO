#include <iostream>
#include <map>
#include <string>

struct StudentGrade {
    std::string studentName;
    char grade;
};

int main() {
    std::map<std::string, char> studentGrades;

    studentGrades["Alice"] = 'A';
    studentGrades["Bob"] = 'B';
    studentGrades["Charlie"] = 'C';
    studentGrades["Diana"] = 'A';

    std::cout << "Student grades:" << std::endl;
    for (const auto& pair : studentGrades) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << "\nAlice's grade: " << studentGrades["Alice"] << std::endl;

    studentGrades["Bob"] = 'A';
    std::cout << "After changing Bob's grade:" << std::endl;
    std::cout << "Bob: " << studentGrades["Bob"] << std::endl;

    std::string newStudent = "Eve";
    studentGrades[newStudent] = 'B';
    std::cout << "\nAdded new student " << newStudent << " with grade: " << studentGrades[newStudent] << std::endl;

    return 0;
}