#include <iostream>
#include "Student.h"
#include "Instructor.h"
#include <iomanip>

using namespace std;
int main(){
  Student stud;
  Instructor inst;
  bool login;
  string username, password;
  int i;
  
  do{
    do{
      cout<<"User types,\n\t1 - Intructor\n\t2 - Student\nSelect a login user type or enter 3 to exit: ";
      cin>>i;
    }while(i<1 || i>3);
  
	//exit condition of 3 is typed
    if(i == 3){
      return 0;
    }
    
    cout<<"Enter credentials to login,\n\tEnter username: ";

    cin>>username;
    cout<<"\tEnter password: ";
    cin>>password;
    //Student Login
    if(i == 2){
      login = stud.login(username, password);
      if(!login){
		  cout << stud.getStudentName();
	cout<<"Login as student failed"<<endl;
      }
    }
	//Instructor Login
    else if(i == 1){
      login = inst.login(username, password);
      if(!login){
		  cout<<"Login as instructor failed"<<endl;
      }
	  else {
		  cout << "You are now logged in as instructor " << inst.getInstructorName() << "." << endl;
	  }
    }  
  }while(!login);
  
  int queryOption;
  //Instructor Queries
  do{
    if(i == 1){//Instrutor
      do{
	cout<<"Query options,\n\t1 - view grades of a student\n\t2 - view stats\n\tEnter Option number: ";
	cin>>queryOption;
	if(queryOption < 1|| queryOption > 2){
	  cout<<"Invalid option. Please enter a valid option."<<endl;
	}
      }while(queryOption < 1 || queryOption > 2);
      //option 1
      if(queryOption == 1){
		string studentUsername;
		cout<<"Enter student username to view grades: ";
		cin>>studentUsername;
		Student gottenStudent = inst.getStudent(studentUsername);
		if(gottenStudent.getProjectGrade()>1){//check if gottenStudent exists
			cout << "Student name: " << gottenStudent.getStudentName() << endl;
			cout << "\tProject\t" << gottenStudent.getProjectGrade() << endl;
			cout << "\tQuiz\t" << gottenStudent.getQuizGrade() << endl;
			cout << "\tMidterm\t" << gottenStudent.getMidtermGrade() << endl;
			cout << "\tFinal\t" << gottenStudent.getFinalGrade() << endl;
			//cout << fixed;
			cout << setprecision(4);
			cout << "\tOverall\t" << gottenStudent.getOverallGrade() << endl;
											  //student shit
		}else{
		  cout<<"Student username is not valid."<<endl;
		}
      }
      //option 2
      if(queryOption == 2){
		  int whichGrade;
		  cout << "Grade types," << endl;
		  cout << "\t1 - Project grade" << endl;
		  cout << "\t2 - Quiz grade" << endl;
		  cout << "\t3 - Midterm grade" << endl;
		  cout << "\t4 - Final grade" << endl;
		  cout << "\t5 - Overall grade" << endl;
		  cout << "Select a grade type to view stats" << endl;
		  cin >> whichGrade;
		  if (whichGrade < 1 || whichGrade>5) {
			  cout << "Invalid option. Please enter a valid option" << endl;
		  }
		  //code for each query
		  else if (whichGrade==1){
			  Student studMin = inst.getMinStudent(whichGrade);
			  Student studMax = inst.getMaxStudent(whichGrade);
			  cout << "Overall grade stats," << endl;
			  cout << "\tmin\t" << studMin.getProjectGrade() << "\t(" << studMin.getStudentName()<< ")"<<endl;
			  cout << "\tmax\t" << studMax.getProjectGrade() << "\t(" << studMax.getStudentName() << ")" << endl;
			  cout << setprecision(4);
			  cout << "\tavg\t" << inst.getAvg(whichGrade) << endl;

		  }
		  else if (whichGrade == 2) {
			  Student studMin = inst.getMinStudent(whichGrade);
			  Student studMax = inst.getMaxStudent(whichGrade);
			  cout << "Overall grade stats," << endl;
			  cout << "\tmin\t" << studMin.getQuizGrade() << "\t(" << studMin.getStudentName() << ")" << endl;
			  cout << "\tmax\t" << studMax.getQuizGrade() << "\t(" << studMax.getStudentName() << ")" << endl;
			  cout << setprecision(4);
			  cout << "\tavg\t" << inst.getAvg(whichGrade) << endl;

		  }
		  else if (whichGrade == 3) {
			  Student studMin = inst.getMinStudent(whichGrade);
			  Student studMax = inst.getMaxStudent(whichGrade);
			  cout << "Overall grade stats," << endl;
			  cout << "\tmin\t" << studMin.getMidtermGrade() << "\t(" << studMin.getStudentName() << ")" << endl;
			  cout << "\tmax\t" << studMax.getMidtermGrade() << "\t(" << studMax.getStudentName() << ")" << endl;
			  cout << setprecision(4);
			  cout << "\tavg\t" << inst.getAvg(whichGrade) << endl;

		  }
		  else if (whichGrade == 4) {
			  Student studMin = inst.getMinStudent(whichGrade);
			  Student studMax = inst.getMaxStudent(whichGrade);
			  cout << "Overall grade stats," << endl;
			  cout << "\tmin\t" << studMin.getFinalGrade() << "\t(" << studMin.getStudentName() << ")" << endl;
			  cout << "\tmax\t" << studMax.getFinalGrade() << "\t(" << studMax.getStudentName() << ")" << endl;
			  cout << setprecision(4);
			  cout << "\tavg\t" << inst.getAvg(whichGrade) << endl;

		  }
		  else if (whichGrade == 5) {
			  Student studMin = inst.getMinStudent(whichGrade);
			  Student studMax = inst.getMaxStudent(whichGrade);
			  cout << "Overall grade stats," << endl;
			  cout << "\tmin\t" << studMin.getOverallGrade() << "\t(" << studMin.getStudentName() << ")" << endl;
			  cout << "\tmax\t" << studMax.getOverallGrade() << "\t(" << studMax.getStudentName() << ")" << endl;
			  cout << setprecision(4);
			  cout << "\tavg\t" << inst.getAvg(whichGrade) << endl;

		  }
      }
    }//Instructor
    //student query
    if(i == 2){//Student
		string gradeView;
		cout << "You are now logged in as student " << stud.getStudentName() << endl;
		cout << "Do you want to view grades (y/n)?";
		cin >> gradeView;
		if (gradeView == "y") {
			cout << "Student name: " << stud.getStudentName() << endl;
			cout << "\tProject\t" << stud.getProjectGrade() << endl;
			cout << "\tQuiz\t" << stud.getQuizGrade() << endl;
			cout << "\tMidterm\t" << stud.getMidtermGrade() << endl;
			cout << "\tFinal\t" << stud.getFinalGrade() << endl;
			//cout << fixed;
			cout << setprecision(4);
			cout << "\tOverall\t" << stud.getOverallGrade() << endl;
		}
		if (gradeView == "n"){
			return 0;
		}
    }
  }while(true);  
}
