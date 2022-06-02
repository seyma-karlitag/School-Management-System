#include "Course.h"
#include "Student.h"
#include <iostream>

using namespace std;

Course::Course() : name(""), code(0) {}

Course::Course(string cname, int newCode) : name(cname), code(newCode) {}

//Writing get set functions

int Course::getCode() { return code; }

void Course::setCode(int newCode) { code = newCode; }

string Course::getName() { return name; }

//Writing get set functions

void Course::setName(string newName) { name = newName; }

Course::~Course() { delete[] slist; }

//As new students are added, the capacity
// increases and the student is added to the end of the list.

void Course::addStudent(Student &student) {

  if (slistlen + 1 > slistcap) {
    int newCap = slistlen * 2 + 1;

    Student **newArr = new Student *[newCap];

    for (int i = 0; i < slistlen; ++i) {
      newArr[i] = slist[i];
    }
    
    //copying to a new list takes place and the old list is deleted
    delete[] slist;
    slist = newArr;
    slistcap = newCap;
  }

  slist[slistlen] = &student;
  ++slistlen;
}

//delete student in list function

void Course::deleteStudent(Student &student) {
  if (slistlen <= 0) {
    return;
  }
  int i;

  for (i = 0; i < slistlen; ++i) {
    if (slist[i] == &student) {
      break;
    }
  }

  if (i == slistlen) {
    return;
  }
  slist[i] = slist[slistlen - 1];
  --slistlen;
}
//function that checks if a student is in the list

bool Course::hasStudent(Student &student) {
  for (int i = 0; i < slistlen; ++i) {
    if (slist[i] == &student) {
      return true;
    }
  }
  return false;
}

//writing a list of students

ostream &Course::printStudents(ostream &os) {
  for (int i = 0; i < slistlen; ++i) {
    if (i > 0) {
      os << '\n';
    }
    os << *slist[i];
  }
  return os;
}
//writing course name and code

ostream &operator<<(ostream &os, Course &course) {
  os << course.getName() << ' ' << course.getCode();
  return os;
}