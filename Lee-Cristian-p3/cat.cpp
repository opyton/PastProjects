#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

//preprocessor BUFFSIZE used to avoid having to change value of buff size repeatedly
//this is set at 4 as of 4/4 for reader to read 4 at a time
#define BUFFSIZE 4 
/**
 * @author Nathaniel Lee
 * @author Miruna Cristian
 * <p>
 * Imitates Cat function in the Unix Environment. Typing in ./cat <filename> will thus
 * print out the contents of the specified file onto the screen.
 * Typing ./cat - fill default the system to repeat user input. quit will terminate
 * program from here.  
 * <p>
 * @param   filename    file to be read. '-' will result in the program taking in user input 
 * and will not terminate until quit is input.
 * 
 * @return  contents of file 
 */
int main(int argc, char** argv) {
    int n;
    char buf[BUFFSIZE];//character array of size BUFFSIZE
    int count = 1;
    //checks to ensure a file is specified
    if (argc > 1){
        //continues reading until all files specified are read
        while(argv[count]!=NULL){
            if (*argv[count]=='-'){     //if '-' is specified, switch to user input
               cout<<"System will now read from standard input type quit to quit."<<endl;
               while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) { 
                   for(int count=0; count<BUFFSIZE;count++){
                       if(buf[count]=='q' 
                               && buf[count+1]=='u'
                               && buf[count+2]=='i'
                               && buf[count+3]=='t'){
                           exit(0);
                        }
                   }
                   write(STDOUT_FILENO,buf,n);
            }
            }
    else{
            int fd = open(argv[count], O_RDONLY); //file descriptor fd set as a read only of file argument
            if(fd < 0) {      
               cout << "error opening" << endl;
               exit(1);
            }
            while((n = read(fd, buf, BUFFSIZE)) > 0) { //n will equal BUFFSIZE, buf will contain BUFFSIZE characters from file
                write(STDOUT_FILENO,buf,n);
            }
          if(n < 0) {
            cout << "error reading" << endl;
            exit(3);
          }
          close(fd);
          cout<<endl;
          count++;
        }
        }
    }
    else{
        cout<<"System will now read from standard input type quit to quit."<<endl;
               while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) { //n will equal BUFFSIZE, buf will contain BUFFSIZE characters from file
                   for(int count=0; count<BUFFSIZE;count++){
                       if(buf[count]=='q' 
                               && buf[count+1]=='u'
                               && buf[count+2]=='i'
                               && buf[count+3]=='t'){
                           exit(0);
                        }
                   }
                   write(STDOUT_FILENO,buf,n);
            }
    }
}
