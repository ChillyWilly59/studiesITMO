#include <iostream>
#include <vector>
#include "human.h"
#include "student.h"
#include "teacher.h"

int main() {
    std::vector<int> scores;
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(4);
    scores.push_back(4);
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);

    student *stud = new student("Петров", "Иван", "Алексеевич", scores);
    std::cout << stud->get_full_name() << std::endl;
    std::cout << "Средний балл: " << stud->get_average_score() << std::endl;

    unsigned int teacher_work_time = 40;
    teacher *tch = new teacher("Сергеев", "Дмитрий", "Сергеевич", teacher_work_time);
    std::cout << tch->get_full_name() << std::endl;
    std::cout << "Количество часов: " << tch->get_work_time() << std::endl;

    std::cout << "\nПолиморфный вызов:\n";
    human* people[2];
    people[0] = stud;
    people[1] = tch;

    for (int i = 0; i < 2; i++) {
        std::cout << people[i]->get_info() << std::endl;
    }

    delete stud;
    delete tch;

    return 0;
}