#include "Student.h"
#include "Course.h"
#include <iostream>

using namespace std;

//get set functions

Student::Student() : name(""), Id(0) {}

Student::Student(string newName, int newId) : name(newName), Id(newId) {}

int Student::getId() { return Id; }

void Student::setId(int newId) { Id = newId; }

string Student::getName() { return name; }

void Student::setName(string newName) { name = newName; }

//destructive function

Student::~Student() { delete[] clist; }

//Adding a course as a piecewise function

void Student::addCourse(Course &course) {
  if (len + 1 > cap) {
    int newCap = len * 2 + 1;
    Course **newArr = new Course *[newCap];

    for (int i = 0; i < len; ++i) {
      //When the capacity is reached, a new area is opened and copied.
      newArr[i] = clist[i];
    }
    delete[] clist;
    clist = newArr;
    cap = newCap;
  }

  clist[len] = &course;
  ++len;
}
//the course is deleted and you are reduced by 1

void Student::deleteCourse(Course &course) {
  if (len <= 0) {
    return;
  }
  int i;

  for (i = 0; i < len; ++i) {
    if (clist[i] == &course) {
      break;
    }
  }

  if (i == len) {
    return;
  }
  clist[i] = clist[len - 1];
  --len;
}

//checks if the course is in the list

bool Student::hasCourse(Course &course) {
  for (int i = 0; i < len; ++i) {
    if (clist[i] == &course) {
      return true;
    }
  }
  return false;
}
//function of writing courses

ostream &Student::printCourses(ostream &os) {
  for (int i = 0; i < len; ++i) {
    if (i > 0) {
      os << '\n';
    }
    os << *clist[i];
  }
  return os;
}
//writing student name and id

ostream &operator<<(ostream &os, Student &student) {

  os << student.getName() << ' ' << student.getId();

  return os;
}

