#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

//preprocessor BUFFSIZE used to avoid having to change value of buff size repeatedly
//this is set at 4 as of 4/4 for reader to read 4 at a time
#define BUFFSIZE 4 
/**
 * Method to read the first line of a declared text file.  
 * <p>
 * @return  String of characters as read by the first line of a text file.
 * This is denoted by the existence of a new line character. 
 */
int main(int argc, char** argv) {
    //this ensures that formatting correctly matches ./lab09 "file.txt"
    if(argc != 2) {
        cout << "incorrect usage of: "<<endl;
        cout << argv[0];
        exit(4);
    }
    int n;
    char buf[BUFFSIZE];//character array of size BUFFSIZE
    int fd = open(argv[1], O_RDONLY); //file descriptor fd set as a read only of file argument
    if(fd < 0) {      
       cout << "error opening" << endl;
       exit(1);
    }
    bool newLineDetect = false;//for detecting when to stop
    
    //start of read 1st line code
    while((n = read(fd, buf, BUFFSIZE)) > 0 && newLineDetect == false) { //n will equal BUFFSIZE, buf will contain BUFFSIZE characters from file
        for(int count = 0; count < n && newLineDetect == false; count++){
            if(buf[count]=='\n'){
                newLineDetect=true;   
                n = count;//used to correctly adjust n 
            }
        }   
            write(STDOUT_FILENO,buf,n);
    }

  if(n < 0) {
    cout << "error reading" << endl;
    exit(3);
  }
  close(fd);
  cout<<endl;
}
