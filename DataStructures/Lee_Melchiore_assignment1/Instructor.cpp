#include "Instructor.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/**
*If user and pswd match, return true and stop process, otherwise return false
*/
bool Instructor::login(string username, string password){
	ifstream instructorFile("instructors.txt");
	string line, userInFile, passwordInFile;
	
	while (getline(instructorFile, line)) {
		string first, last;
		istringstream ss(line);
		string str;
		while (getline(ss, str, '\t')) {
			userInFile = str;
			while (ss >> passwordInFile >> first >> last) {
				if ((username.compare(userInFile) == 0) && (password.compare(passwordInFile) == 0)) {
					fullName = first + " " + last;

					return true;

				}

			}
		}
	}
	return false;

}

void Instructor::setInstructorName(string fullName){
  this->fullName = fullName;
}

string Instructor::getInstructorName(){
  return fullName;
}

Student Instructor::getStudent(string username){
  //open file for students
  //search for student
  //load student;
  //return null but print student username if not valid;
	Student stud;
	ifstream studentFile("students.txt");
	string line, userInFile, passwordInFile, first,last;
	while (getline(studentFile, line)) {
		istringstream ss(line);
		string str;
		while (getline(ss, str, '\t')) {
			userInFile = str;
			while (ss >> passwordInFile >> first >> last >> projectGrade >> quizGrade >> midtermGrade >> finalGrade) {
				if (username.compare(userInFile) == 0) {
					fullName = first + " " + last;
					stud.setFinalGrade(finalGrade);
					stud.setMidtermGrade(midtermGrade);
					stud.setProjectGrade(projectGrade);
					stud.setQuizGrade(quizGrade);
					stud.setStudentName(fullName);
					return stud;

				}

			}
		}
	}
	return stud;
}
//gets Min val returns specified student
Student Instructor::getMinStudent(int gradeType){
	ifstream studentFile("students.txt");
	string line, user, password,first,last;
	Student stud;
	int tempProjectGrade = 100; int tempQuizGrade = 100; int tempMidTermGrade = 100; int tempFinalGrade = 100; double tempOverallGrade = 100;
	while (getline(studentFile, line)) {
		istringstream ss(line);
		string str;
		string tempName = "";
		while (getline(ss, str, '\t')) {
			user = str;
			while (ss >> password >> first >> last >> projectGrade >> quizGrade >> midtermGrade >> finalGrade) {
				double overall = projectGrade * .3 + quizGrade * .1 + midtermGrade * .2 + finalGrade * .4;
				if (gradeType == 1 && projectGrade < tempProjectGrade) {
					fullName = first + " " + last;
					tempProjectGrade = projectGrade; tempName = fullName;
					stud.setProjectGrade(tempProjectGrade);
					stud.setStudentName(tempName);
				}
				if (gradeType == 2 && quizGrade < tempQuizGrade) {
					fullName = first + " " + last;
					tempQuizGrade = quizGrade; tempName = fullName;
					stud.setQuizGrade(tempQuizGrade);
					stud.setStudentName(tempName);
				}
				if (gradeType == 3 && midtermGrade < tempMidTermGrade) {
					fullName = first + " " + last;
					tempMidTermGrade = midtermGrade; tempName = fullName;
					stud.setMidtermGrade(tempMidTermGrade);
					stud.setStudentName(tempName);
				}
				if (gradeType == 4 && finalGrade < tempFinalGrade) {
					fullName = first + " " + last;
					tempFinalGrade = finalGrade; tempName = fullName;
					stud.setFinalGrade(tempFinalGrade);
					stud.setStudentName(tempName);
				}
				if (gradeType == 5 && overall < tempOverallGrade) {
					fullName = first + " " + last;
					tempOverallGrade = overall; tempName = fullName;
					stud.setFinalGrade(finalGrade);
					stud.setMidtermGrade(midtermGrade);
					stud.setProjectGrade(projectGrade);
					stud.setQuizGrade(quizGrade);
					stud.setStudentName(fullName);
				}

			}
		}
	}
	return stud;
}

//gets Max Val returns specified student

Student Instructor::getMaxStudent(int gradeType){
	ifstream studentFile("students.txt");
	string line, user, password, first, last;
	Student stud;
	int tempProjectGrade = 0; int tempQuizGrade = 0; int tempMidTermGrade = 0; int tempFinalGrade = 0; double tempOverallGrade = 0;
	while (getline(studentFile, line)) {
		istringstream ss(line);
		string str;
		string tempName = "";
		while (getline(ss, str, '\t')) {
			user = str;
			while (ss >> password >> first >> last >> projectGrade >> quizGrade >> midtermGrade >> finalGrade) {
				double overall = projectGrade * .3 + quizGrade * .1 + midtermGrade * .2 + finalGrade * .4;
				if (gradeType == 1 && projectGrade > tempProjectGrade) {
					fullName = first + " " + last;
					tempProjectGrade = projectGrade; tempName = fullName;
					stud.setProjectGrade(tempProjectGrade);
					stud.setStudentName(tempName);
				}
				if (gradeType == 2 && quizGrade > tempQuizGrade) {
					fullName = first + " " + last;
					tempQuizGrade = quizGrade; tempName = fullName;
					stud.setQuizGrade(tempQuizGrade);
					stud.setStudentName(tempName);
				}
				if (gradeType == 3 && midtermGrade > tempMidTermGrade) {
					fullName = first + " " + last;
					tempMidTermGrade = midtermGrade; tempName = fullName;
					stud.setMidtermGrade(tempMidTermGrade);
					stud.setStudentName(tempName);
				}
				if (gradeType == 4 && finalGrade > tempFinalGrade) {
					fullName = first + " " + last;
					tempFinalGrade = finalGrade; tempName = fullName;
					stud.setFinalGrade(tempFinalGrade);
					stud.setStudentName(tempName);
				}
				if (gradeType == 5 && overall > tempOverallGrade) {
					fullName = first + " " + last;
					tempOverallGrade = overall; tempName = fullName;
					stud.setFinalGrade(finalGrade);
					stud.setMidtermGrade(midtermGrade);
					stud.setProjectGrade(projectGrade);
					stud.setQuizGrade(quizGrade);
					stud.setStudentName(fullName);
				}

			}
		}
	}
	return stud;
}
//gets Average returns double
double Instructor::getAvg(int gradeType){
	ifstream studentFile("students.txt");
	string line, user, password, first, last;
	Student stud;
	int tempProj= 0, tempQuiz=0, tempMid=0, tempFinal =0, tempOverall=0; 
	double count= 0.0; 
	while (getline(studentFile, line)) {
		istringstream ss(line);
		string str;
		while (getline(ss, str, '\t')) {
			user = str;
			while (ss >> password >> first >> last >> projectGrade >> quizGrade >> midtermGrade >> finalGrade) {
				double overall = projectGrade * .3 + quizGrade * .1 + midtermGrade * .2 + finalGrade * .4;
				if (gradeType == 1 ) {
					tempProj+=projectGrade;
					count++;					
				}
				if (gradeType == 2 ) {
					tempQuiz += quizGrade;
					count++;
				}
				if (gradeType == 3 ) {
					tempMid += midtermGrade;
					count++;
				}
				if (gradeType == 4  ) {
					tempFinal += finalGrade;
					count++;
				}
				if (gradeType ==  5) {
					tempOverall += overall;
					count++;
				}

			}
		}
	}

	switch (gradeType) {
	case 1: return double(tempProj / count); break;
	case 2: return double(tempQuiz / count); break;
	case 3: return double(tempMid / count); break;
	case 4: return double(tempFinal / count); break;
	case 5: return double(tempOverall /count); break;
		
	}
}
