#include "SchoolManagementSystem.h"
#include "Course.h"
#include "Student.h"
#include <iostream>
#include <ostream>

using namespace std;

SchoolManagementSystem::SchoolManagementSystem() {}

//destructive functions

SchoolManagementSystem::~SchoolManagementSystem() {
  for (int i = 0; i < slen; ++i) {
    delete slist[i];
  }
  delete[] slist;

  for (int i = 0; i < clen; ++i) {
    delete clist[i];
  }
  delete[] clist;
}

Course *SchoolManagementSystem::getCourseByIndex(int index) {
  if (index < 0 || index >= clen) {
    return nullptr;
  }

  return clist[index];
}
Student *SchoolManagementSystem::getStudentByIndex(int index) {
  if (index < 0 || index >= slen) {
    return nullptr;
  }

  return slist[index];
}

void SchoolManagementSystem::addCourse(string name, int code) {
  if (clen + 1 > ccap) {
    int newCap = clen * 2 + 1;
    Course **newArr = new Course *[newCap];

    for (int i = 0; i < clen; ++i) {
      newArr[i] = clist[i];
    }
    delete[] clist;
    clist = newArr;
    ccap = newCap;
  }

  clist[clen] = new Course(name, code);
  ++clen;
}
void SchoolManagementSystem::addStudent(string name, int id) {
  if (slen + 1 > scap) {
    int newCap = slen * 2 + 1;
    Student **newArr = new Student *[newCap];

    for (int i = 0; i < slen; ++i) {
      newArr[i] = slist[i];
    }
    delete[] slist;
    slist = newArr;
    scap = newCap;
  }

  slist[slen] = new Student(name, id);
  ++slen;
}
//the function where the course is deleted
void SchoolManagementSystem::deleteCourse(Course &course) {
  if (clen <= 0) {
    return;
  }
  int i;
  for (i = 0; i < clen; ++i) {
    if (clist[i] == &course) {
      break;
    }
  }

  if (i == clen) {
    return;
  }
  delete clist[i];
  clist[i] = clist[clen - 1];
  --clen;
}
//the function where the course is deleted
void SchoolManagementSystem::deleteCourse(int index) {
  deleteCourse(*clist[index]);
}

//the function where the student is deleted
void SchoolManagementSystem::deleteStudent(Student &student) {
  if (slen <= 0) {
    return;
  }

  int i;
  for (i = 0; i < slen; ++i) {
    if (slist[i] == &student) {
      break;
    }
  }

  if (i == slen) {
    return;
  }
  delete slist[i];
  slist[i] = slist[slen - 1];
  --slen;
}

//function that deletes from list to student

void SchoolManagementSystem::deleteStudent(int index) {
  deleteStudent(*slist[index]);
}
//Adding a student to the selected 
//course after the student is selected

void SchoolManagementSystem::addStudentToCourse(Student &student,
                                                Course &course) {
  student.addCourse(course);
  course.addStudent(student);
}
//deleting a student from the selected
// course after the student is selected
void SchoolManagementSystem::dropStudentFromCourse(Student &student,
                                                   Course &course) {
  student.deleteCourse(course);
  course.deleteStudent(student);
}
//function that prints student list

ostream &SchoolManagementSystem::printStudents(ostream &os) {
  for (int i = 0; i < slen; ++i) {
    if (i > 0) {
      os << '\n';
    }
    os <<*slist[i];
  }
  return os;
}
//function that prints course list
ostream &SchoolManagementSystem::printCourses(ostream &os) {
  for (int i = 0; i < clen; ++i) {
    if (i > 0) {
      os << '\n';
    }
    os << i + 1 << "  " << *clist[i];
  }
  return os;
}
//function that suppresses the courses it can take

ostream &SchoolManagementSystem::printUntakenCourses(ostream &os,
                                                     Student &student) {
  int printCount = 0;
  for (int i = 0; i < clen; ++i) {
    if (clist[i]->hasStudent(student)) {
      continue;
    }

    if (printCount > 0) {
      os << '\n';
    }
    os << printCount + 1 << *clist[i];
    ++printCount;
  }
  return os;
}

//Function that returns the index of non-existent courses
Course *SchoolManagementSystem::getUntakenCourseWithIndex(Student &student,
                                                          int index) {
  int untakenCount = 0;
  for (int i = 0; i < clen; ++i) {
    if (clist[i]->hasStudent(student)) {
      continue;
    }

    if (untakenCount == index) {
      return clist[i];
    }
    ++untakenCount;
  }
  return nullptr;
}
////function that gets the index of the student
int SchoolManagementSystem::getStudentIndex(string name, int Id) {
  int a = 0;
  for (int i = 0; i < slen; i++) {
    if (slist[i]->getName() == name && slist[i]->getId() == Id) {
      a = i;
      break;
    }
  }
  return a;
}

//function that gets the index of the course
int SchoolManagementSystem::getCourseIndex(string name, int code) {
  int a = 0;
  for (int i = 0; i < clen; i++) {
    if (clist[i]->getName() == name && clist[i]->getCode() == code) {
      a = i;
      break;
    }
  }
  return a;
}
