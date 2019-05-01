#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student{
 public:
  bool login(std::string username, std::string password);
  std::string getStudentName();
  int getProjectGrade();
  int getQuizGrade();
  int getMidtermGrade();
  int getFinalGrade();
  double getOverallGrade();
  void setStudentName(std::string fullName);
  void setProjectGrade(int grade);
  void setQuizGrade(int grade);
  void setMidtermGrade(int grade);
  void setFinalGrade(int grade);

 private:
  std::string fullName;
  int projectGrade;
  int quizGrade;
  int midtermGrade;
  int finalGrade;
};

#endif
