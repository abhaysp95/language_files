#!/usr/bin/env python


class Student:
    def __init__(self, name, age, grade):
        self.name = name
        self.age = age
        self.grade = grade  # 0 - 100

    def get_grade(self):
        return self.grade


class Course:
    def __init__(self, name, max_students):
        self.name = name
        self.max_students = max_students
        self.students = []

    def add_students(self, student):
        if len(self.students) < self.max_students:
            self.students.append(student)
            return True
        return False

    def get_average(self):
        sum = 0
        for student in self.students:
            sum += student.get_grade()
        return sum / len(self.students)


stu1 = Student('Tom', 20, 67)
stu2 = Student('Som', 19, 87)
stu3 = Student('Dom', 21, 77)

course1 = Course('Science', 2)
course1.add_students(stu1)
course1.add_students(stu2)

print(stu1.name)
print(course1.students[0].name)
print(len(course1.students))

print(course1.get_average())
