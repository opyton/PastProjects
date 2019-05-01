#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "Student.h"

class Instructor{
 public:
  bool login(std::string username, std::string password);
  std::string getInstructorName();
  Student getStudent(std::string username);
  Student getMinStudent(int gradeType);
  Student getMaxStudent(int gradeType);
  double getAvg(int gradeType);
  void setInstructorName(std::string name);
  
 private:
  std::string fullName;
  int projectGrade;
  int quizGrade;
  int midtermGrade;
  int finalGrade;
  
};
#endif
