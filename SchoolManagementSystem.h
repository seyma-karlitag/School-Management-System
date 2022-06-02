#ifndef SCHOOLMANAGEMENTSYSTEM_H
#define SCHOOLMANAGEMENTSYSTEM_H
#include "Course.h"
#include "Student.h"
#include <iostream>

using namespace std;
class Student;
class Course;
class SchoolManagementSystem {
public:
  SchoolManagementSystem();
  ~SchoolManagementSystem();
  int getStudentIndex(string name,int Id);
  int getCourseIndex(string name,int code);
  Course* getCourseByIndex(int index);
  Student* getStudentByIndex(int index);
  int getSlen() { return slen; };
  void setSlen(int newSlen) { slen = newSlen; };
  int getClen() { return clen; };
  void setClen(int newClen) { clen = newClen; };
  void addCourse(string name, int code);
  void addStudent(string name, int id);
  void deleteCourse(Course &course);
  void deleteCourse(int index);
  void deleteStudent(Student &student);
  void deleteStudent(int index);
  void addStudentToCourse(Student &student, Course &course);
  void dropStudentFromCourse(Student &student, Course &course);
  Course *getUntakenCourseWithIndex(Student &student, int index);
  ostream &printStudents(ostream &os);
  ostream &printCourses(ostream &os);
  ostream &printUntakenCourses(ostream &os, Student &student);

private:
  Course **clist = nullptr;
  Student **slist = nullptr;
  int slen = 0, scap = 0;
  int clen = 0, ccap = 0;
};
#endif