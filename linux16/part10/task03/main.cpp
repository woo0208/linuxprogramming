#include "Student.hpp"

int main() {
    Student s1(1001,"Kim",85.5);
    Student s2(1002,"Lee",92.0);
    Student s3(1003,"Park",85.5);

    Student result = bigger(s1,s2);

    cout << result.getname() << endl;

    if (isSame(s1,s3)) cout << "같은 점수입니다." << endl;

    return 0;
}
