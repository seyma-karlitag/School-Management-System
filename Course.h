#ifndef COURSE_H
#define COURSE_H
#include <iostream>

using namespace std;
class Student;
class Course {
public:
  Course();
  Course(string cname, int newCode);
  ~Course();
  //Defining get set functions
  int getCode();
  void setCode(int newCode);
  string getName();
  //Defining member functions
  void setName(string newName);
  
  //add and delete students functions
  void addStudent(Student &student);
  void deleteStudent(Student &student);
  bool hasStudent(Student &student);
  ostream &printStudents(ostream &os);

private:
  string name;
  int code;
  int slistlen = 0, slistcap = 0;
  Student **slist = nullptr;
};
ostream &operator<<(ostream &os, Course &course);
#endif
