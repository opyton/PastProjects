#include <unistd.h>
#include <sys/types.h> 
#include <iostream>
#include <sys/wait.h>

using namespace std;

/**
 * Prints process id, parent pid, forks to a child, then prints child
 * id followed by its parent(the original process) id.
 *
 * @author Nathaniel Lee
 * @author Miruna Cristian
 */
int main(){
/*	
	int pid;
	cout<<"process id: "<< getpid()<<endl;
	cout<<"parent of process id: "<< getppid()<<endl;
	int parentId = getpid();
	pid = fork(); 
	if(pid == 0){
		cout << "child id: " << getpid()<<endl;
		cout<<"parent of child id: "<<parentId<<endl;
	}
*/
	int pid;
	pid = fork(); 
	if(pid == 0){
		cout << "child id: " << getpid()<<endl;
		cout<<"parent of child id: "<<getppid() <<endl;
	}
	else{	
		cout<< "process id: "<< getpid()<<endl;
		cout<< "parent of process id: "<< getppid()<<endl;
		wait(NULL);
	}

}//main
