#include "Student.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/**
*If user and pswd match, return true and stop process, otherwise return false 
*/
bool Student::login(string username, string password) {
	ifstream studentFile("students.txt");
	string line, userInFile, passwordInFile;

	while (getline(studentFile, line)) {
		string first, last;
		istringstream ss(line);
		string str;
		while (getline(ss, str, '\t')) {
			userInFile = str;
			while (ss >> passwordInFile >> first>>last >> projectGrade >> quizGrade >> midtermGrade >> finalGrade) {
				if ((username.compare(userInFile) == 0) && (password.compare(passwordInFile) == 0)) {
					fullName = first + " " + last;

					return true;

				}

			}
		}
	}
	return false;
	
}

void Student::setStudentName(string fullName){
  this->fullName = fullName;
}

string Student::getStudentName(){
  return fullName;
}

void Student::setProjectGrade(int projectGrade){
  this->projectGrade = projectGrade;
}

int Student::getProjectGrade(){
  return projectGrade;
}

void Student::setQuizGrade(int quizGrade){
  this->quizGrade = quizGrade;
}

int Student::getQuizGrade(){
  return quizGrade;
}

void Student::setMidtermGrade(int midtermGrade){
  this->midtermGrade = midtermGrade;
}

int Student::getMidtermGrade(){
  return midtermGrade;
}

void Student::setFinalGrade(int finalGrade){
  this->finalGrade = finalGrade;
}

int Student::getFinalGrade(){
  return finalGrade;
}

double Student::getOverallGrade(){
	if (projectGrade == NULL) {
		projectGrade = 0; midtermGrade = 0; finalGrade = 0;
	}
		
  double overall = projectGrade * .3 + quizGrade *.1 + midtermGrade * .2 + finalGrade * .4;
  return overall;
}
