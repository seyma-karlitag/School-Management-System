#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;
class Course;
class Student {
public:
  Student();
  Student(string newName, int newId);
  ~Student();
  int getId();
  string getName(); //Defining get and set functions
  void setId(int newId);
  void setName(string newName);
  void addCourse(Course &course); //course add and subtract functions
  void deleteCourse(Course &course);
  bool hasCourse(Course &course);
  ostream &printCourses(ostream &os); //printing course names

private:
  string name;
  int Id, len = 0, cap = 0;
  Course **clist = nullptr;
};
ostream &operator<<(ostream &os, Student &student);
#endif
