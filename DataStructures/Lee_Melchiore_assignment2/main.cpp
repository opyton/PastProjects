#include <string>
#include <fstream>
#include <iostream>
#include "SortedLinkedList.h"
#include "ItemType.h"

using namespace std;
int main(const int argc, const char * argv []) {
  SortedLinkedList list;
  ItemType item = ItemType(0);
  int input;
  std::fstream fs;
  fs.open(argv[1],std::fstream::in);
  //insert items into nodelist
  if(fs.is_open()){
    while(fs>>input){
      item.initialize(input);
      list.insertItem(item);
    }
  }else{
    std::cout<<"Failed to open input file"<<endl;
    return 1;
  }
  fs.close();

  string inp;
  bool running = true;
  //directives
  while(running){
    cout<<endl<<endl<<"Commands:"<<endl;
    cout<<"(i) - INSERT "<<endl;
    cout<<"(d) - DELETE "<<endl;
    cout<<"(s) - SEARCH "<<endl;
    cout<<"(n) - ITR_NEXT"<<endl;
    cout<<"(r) - RESET_ITR"<<endl;
    cout<<"(p) - PRINT_ALL"<<endl;
    cout<<"(l) - LENGTH"<<endl;
    cout<<"(q) - QUIT"<<endl<<endl<<endl<<"Enter Command: ";
    cin>>inp;

    if(inp.compare("i")==0){
      cout<<"Enter number: ";
      int x;
      cin>>x;
      list.print();
      item.initialize(x);
      list.insertItem(item);
      list.print();
    }//insert
    else if(inp.compare("d")==0){
      list.print();
      cout<<"Enter value to delete: ";
      int x;
      cin>>x;
      item.initialize(x);
      list.deleteItem(item);
      list.print();
    }//delete
    else if(inp.compare("s")==0){
      cout<<"Enter number for searching: ";
      int x;
      cin>>x;
      item.initialize(x);
      int search = list.searchItem(item);
      if(search==-1) cout<<x<<" is not included in the list"<<endl;
      else cout<<x<<" is the "<<search<<" index of the list"<<endl;
      list.print();
    }//search
    else if(inp.compare("n")==0){
      list.itrNext();
    }//ITR_NEXT
    else if(inp.compare("r")==0){
      list.resetList();
      cout<<"Iterator has been reset."<<endl;
    }//RESET_ITR
    else if(inp.compare("p")==0){
      list.print();
    }//PRINT_ALL
    else if(inp.compare("l")==0){
      cout<<"List Length: "<<list.length()<<endl;
    }//LENGTH
    else if(inp.compare("q")==0){
      running=false;
      return 0;
    }//Quit
    else{
      cout<<"INVALID COMMAND, try again."<<endl;
    }
  }
}