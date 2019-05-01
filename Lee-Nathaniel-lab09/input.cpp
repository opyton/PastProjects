#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;
/*
 * method to redirect input to file
 */
void write(int fd){
      dup2(fd, 2);
}
/*
 * method to revert back to standard input
 */
void write(int fd, int backup){
    dup2(backup,2);
}
int main(const int argc, const char * argv []){
  const char * filename = argv[1];                       // get filename
  int fd = open(filename, O_WRONLY | O_CREAT, 0777);     // open file

  if (fd == -1) perror("open");                          // error check open
  int backup = dup(STDIN_FILENO);                       // make a backup of stdout
  if (dup2(fd, STDIN_FILENO) == -1) perror("dup2");     // after first redirection
  if (dup2(backup, STDIN_FILENO) == -1) perror("dup2"); // restore backup
  if (close(fd) == -1) perror("close");                  // close file
  cout<<"redirect std input to file: "<<endl;
  write(fd);
  cout<<"revert back: "<<endl;
  write(fd,backup);
  return EXIT_SUCCESS;
} // main
