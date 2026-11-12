#include "Student.hpp"

Student::Student(int id, string name, double score) {
    this->id = id;
    this->name = name;
    this->score = score;
};

bool Student::operator>(Student s) {
    return score > s.score;
};

bool Student::operator==(Student s) {
    return score == s.score;
};

string Student::getname() {
    return name;
}
