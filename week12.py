# Student class
class Student:
    def __init__(self, id, name):
        self.id = id
        self.name = name
        self.courses = []

    def take_course(self, course):
        self.courses.append(course)
        course.add_student(self)

# Course class
class Course:
    def __init__(self, code, name):
        self.code = code
        self.name = name
        self.students = []

    def add_student(self, student):
        if student not in self.students:
            self.students.append(student)

# Registration system
class RegistrationSystem:
    def register(self, student, course):
        print(student.name + " is registering for " + course.name)
        student.take_course(course)

# Example
s1 = Student(1, "Maria")
s2 = Student(2, "Ezra")

c1 = Course(2210, "Programming 2")
c2 = Course(2270, "Calculus 3")

reg = RegistrationSystem()
reg.register(s1, c1)
reg.register(s2, c1)
reg.register(s1, c2)

# Show which courses each student has
for s in [s1, s2]:
    course_names = []
    for c in s.courses:
        course_names.append(c.name)
    print(s.name + " is taking " + str(course_names))
