#include <iostream>
#include <sys/stat.h>
#include <ctime>
#include <fcntl.h>
#include <fstream>
#include <string.h>
#include <unistd.h>

using namespace std;

int main(int argc, char ** argv){
    if (argc != 4){
        cout << "incorrect usage of: "<<endl;
        cout << argv[0];
	cout<<endl;
        exit(1);
    }
        struct stat buf;
        struct stat buf1;

	//initialization of access modified and status change variables for both files
        int fd = open(argv[2], O_RDONLY);
            
            if(fd < 0) {      
                cout << "error opening" << endl;
                exit(2);
            }
        
        fstat(fd,&buf);
        time_t t1a = buf.st_atime;
        time_t t1m = buf.st_mtime;
        time_t t1c = buf.st_ctime;
       
        int fd1 = open(argv[3], O_RDONLY);
            if(fd1 < 0) {      
                cout << "error opening" << endl;
                exit(3);
            }
        fstat(fd1,&buf1);
  
        time_t t2a = buf.st_atime;
        time_t t2m = buf.st_mtime;
        time_t t2c = buf.st_ctime;
    
    	//options -a -m and -c
        if(strcmp(argv[1],"-a")==0){
            if (t1a>t2a){
                cout<<"The most recent accessed file is ";
                        cout<<argv[2]<<" at "<< ctime(&buf.st_atime);
            }
            else{
                cout<<"The most recent accessed file is ";
                        cout<<argv[3]<<" at "<< ctime(&buf1.st_atime);
            }
        }
        else if (strcmp(argv[1],"-m")==0){
            if (t1m>t2m){
                cout<<"The most recent modified file is ";
                        cout<<argv[2]<<" at "<< ctime(&buf.st_mtime);
            }
            else{
                cout<<"The most recent modified file is ";
                        cout<<argv[3]<<" at "<< ctime(&buf1.st_mtime);
            }
        }
         else if (strcmp(argv[1],"-c")==0){
            if (t1c>t2c){
                cout<<"The most recent status changed file is ";
                        cout<<argv[2]<<" at "<< ctime(&buf.st_ctime);
            }
            else{
                cout<<"The most recent status changed file is ";
                        cout<<argv[3]<<" at "<< ctime(&buf1.st_ctime);
            }
        }
	else{
		cout<<"incorrect option."<<endl;
		exit(4);
	}
	close(fd);
	close(fd1);        
}//main

