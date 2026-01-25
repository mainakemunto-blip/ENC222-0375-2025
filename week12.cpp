#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Course class
class Course {
public:
    int code;
    string name;
    vector<class Student*> students;  // who is taking this course

    Course(int c, string n) {
        code = c;
        name = n;
    }

    void addStudent(Student* s) {
        students.push_back(s);
    }
};

// Student class
class Student {
public:
    int id;
    string name;
    vector<Course*> courses;

    Student(int i, string n) {
        id = i;
        name = n;
    }

    void takeCourse(Course* c) {
        courses.push_back(c);
        c->addStudent(this);
    }
};

// Registration system
class RegSystem {
public:
    void registerStudent(Student* s, Course* c) {
        cout << s->name << " is registering for " << c->name << endl;
        s->takeCourse(c);
    }
};

int main() {
    // Students
    Student s1(1, "Maria");
    Student s2(2, "Ezra");

    // Courses
    Course c1(2210, "Programming 2");
    Course c2(2270, "Calculus 3");

    // Registration
    RegSystem reg;
    reg.registerStudent(&s1, &c1);
    reg.registerStudent(&s2, &c1);
    reg.registerStudent(&s1, &c2);

    // Show enrolled courses
    Student* allStudents[] = { &s1, &s2 };
    for (int i = 0; i < 2; i++) {
        cout << allStudents[i]->name << " is taking ";
        for (int j = 0; j < allStudents[i]->courses.size(); j++) {
            cout << allStudents[i]->courses[j]->name;
            if (j != allStudents[i]->courses.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}
