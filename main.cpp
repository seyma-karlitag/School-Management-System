#include "Course.h"
#include "SchoolManagementSystem.h"
#include "Student.h"
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;
//-------------------------------------------------
//-------------------------------------------------
//-------------------------------------------------
//---------Main-----------------------------------
int main() {

  //identification of objects

  SchoolManagementSystem obj;
  Student std;
  Course crs;

//determination of parameters
  string name, cname, input, input0;
  int Id = 0, code = 0;

  int num0 = 0, num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0;
  do {

    //printing the main menu
    cout << "0 Exit\n";
    cout << "1 student\n";
    cout << "2 course\n";
    cout << "3 list_all_students\n";
    cout << "4 list_all_courses\n";
    cin >> num0;

    //If 3 is selected, printing the student list
    if (num0 == 3) {
      obj.printStudents(cout) << '\n';
    } 
    //If 4 is selected, printing the course list
    else if (num0 == 4) {
      obj.printCourses(cout) << '\n';
    }
   //If 1 is selected, creating the menu 
   //for adding students and selecting students
   
    while (num0 == 1) {
      cout << "0 up\n";
      cout << "1 add_student\n";
      cout << "2 select_student\n";
      cin >> num1;

      if (num1 == 0)
        num0 = -1;

      else if (num1 == 1) {
        name = "";
        while (cin >> input) {
          istringstream ss(input);
          if (ss >> Id) {
            break;
          }

          if (!name.empty()) {
            name += " ";
          }
          name += input;
        }

        obj.addStudent(name, Id);
        name = "";

      } else if (num1 == 2) {
        obj.printStudents(cout) << '\n';
        name = "";
        while (cin >> input) {
          istringstream ss(input);
          if (ss >> Id) {
            break;
          }

          if (!name.empty()) {
            name += " ";
          }
          name += input;
        }

        int index = obj.getStudentIndex(name, Id);
        Student *student = obj.getStudentByIndex(index);
        // if (student == nullptr) ana menu

        cout << " 0 up\n";
        cout << " 1 delete_student\n";
        cout << " 3 add_selected_student_to_a_course\n";
        cout << " 4 drop_selected_student_from_a_course\n";
        cin >> num2;
        if (num2 == 0)
          num0 = -1;
        else if (num2 == 1) {
          obj.deleteStudent(*student);
          num0 = -1;

        } else if (num2 == 3) {
          cout << "0 up\n";
          obj.printUntakenCourses(cout, *student) << '\n';
          cin >> num4;
          if (num4 == 0)
            num0 = -1;
          else {
            Course *course = obj.getUntakenCourseWithIndex(*student, num4 - 1);
            // if (course == nullptr) ana menu
            obj.addStudentToCourse(*student, *course);
          }

        } else if (num2 == 4) {
          cout << "o up\n";
          obj.printCourses(cout) << '\n';
          cin >> num4;
          if (num4 == 0)
            num0 = -1;
          else {
            Course *course = obj.getCourseByIndex(num4 - 1);
            // if (course == nullptr) ana menu
            obj.dropStudentFromCourse(*student, *course);
          }
        }
      }
    }
    while (num0 == 2) {
      cout << "0 up\n";
      cout << "1 add_course\n";
      cout << "2 select_course\n";
      cin >> num3;
      if (num3 == 0)
        num0 = -1;
      else if (num3 == 1) {
        while (cin >> input) {
          istringstream ss(input);
          if (ss >> code) {
            break;
          }

          if (!name.empty()) {
            name += " ";
          }
          name += input;
        }

        obj.addCourse(name, code);
        name = "";
      } else if (num3 == 2) {
        obj.printCourses(cout) << '\n';

        while (cin >> input) {
          istringstream ss(input);
          if (ss >> code) {
            break;
          }

          if (!name.empty()) {
            name += " ";
          }
          name += input;
        }
        cout << "0 up\n";
        cout << "1 delete_course\n";
        cout << "2 list_students_registered_to_the_selected_course\n";
        cin >> num5;
        if (num5 == 0)
          num0 = -1;
        else if (num5 == 1) {
          int b = obj.getCourseIndex(name, code);
          // if (b == -1) ana menu
          obj.deleteCourse(b);
        } else if (num5 == 2) {
          int b = obj.getCourseIndex(name, code);
          Course *course = obj.getCourseByIndex(b);
          // if (course == nullptr) ana menu
          course->printStudents(cout) << '\n';
        }
      }
    }

  } while (num0 != 0);

  return 0;
}