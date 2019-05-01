#include "SortedLinkedList.h"
#include <iostream>
using namespace std;

SortedLinkedList :: SortedLinkedList(){
  length1 = 0;
  iterate=0;
}

//Deletes the node list starting from the first item until the last item indicated by length
SortedLinkedList :: ~SortedLinkedList(){
  while (length1>0) {
    ListNode *temp = head;
    head = head->next;
    delete[] temp;
    length1--;
  }//while 
}

//returns length
int SortedLinkedList :: length() const{
  return length1;
}

//nextIteration
void SortedLinkedList:: itrNext(){
  if(length1 == 0){
    cout<<"List is empty"<<endl;
    return;
  }
  else if(iterate == length1){
    cout<<"The end of the list has reached"<<endl;
    return;
  }
  
  ListNode* nodeVal = head;
  for(int i = 0; i < iterate; i++){
    nodeVal=nodeVal->next;
  }
  cout<<nodeVal->item.getValue()<<endl;
  iterate++;
}

//reset
void SortedLinkedList:: resetList(){
  iterate=0;
}

//Insert item after sorting
void SortedLinkedList:: insertItem(ItemType item){
  ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode *));
  ListNode* newLoc = NULL;
  ListNode* current = head;
  int location = 0;

  bool moreToSearch=(current!=NULL);
  while(moreToSearch){
    //less
    if(item.compareTo(current->item) == LESS){
      moreToSearch = false;                                                                                           
    //equal                                                                                    
    }else if(item.compareTo(current->item) == EQUAL){                                cout<<"Attempt to insert "<<item.getValue()<<" more than once. Duplicate elements not allowed."<<endl;
      return;                                                                  
    //more
    }else if(item.compareTo(current->item) == GREATER){                                                                
      newLoc=current;
      current=current->next;
      moreToSearch=(current!=NULL);
    }      
  }//while for searching
  
  newNode->item = item;
  if(newLoc == NULL && length1 == 0){
    head=newNode;
  }else if(newLoc == NULL && length1 > 0){
    newNode->next = head;
    head = newNode;
  }else{
    newNode->next=current;
    newLoc->next=newNode;
  }
  length1++;
}
//item list
void SortedLinkedList:: print(){
  if(length1==0){
    cout<<"List is empty"<<endl;
    return;
  }
  string list = "";
  int loc = 0;
  bool moreToRead = loc<length1;
  struct ListNode* temp = head;
  while(moreToRead){
    list = list + to_string(temp->item.getValue()) + " ";
    temp = temp->next;
    loc++;
    moreToRead = loc<length1;
  }
  cout<<list<<endl;
}

//delete Item
void SortedLinkedList:: deleteItem(ItemType item){
  struct ListNode* previous = head;
  struct ListNode* current = previous->next;
  int location = 1;
  bool moreToSearch = location < length1;

  if(length1==1 && item.compareTo(head->item)==EQUAL){
      ListNode *temp = head;
      head = head->next;
      delete[] temp;
      length1--;
      return;
  }//if one node
  
  while(moreToSearch){
    //if item is the same val as initial
    if(item.compareTo(head->item) == EQUAL){
    	head->item = head->next->item;
    	ListNode *temp;
    	temp = head->next; 
    	head->next = head->next->next;
    	delete temp; 
    	length1--;
    	return;
    }
    else if(item.compareTo(current->item) == EQUAL){
      moreToSearch = false;
      previous->next = current->next;
      delete current;
      length1--;
      moreToSearch=false;
      return;
    }else{
      location++;
      moreToSearch = location < length1;
      previous = current;
      current = current->next;
    }
  }
  cout<<"Entry not found in list"<<endl;
}//deleteItem

//finds item
int SortedLinkedList:: searchItem(ItemType &item){
  struct ListNode* current = head;
  int location = 0;
  bool moreToSearch = location < length1;
  while(moreToSearch){
    if(item.compareTo(current->item) == EQUAL){
      return location;
    }
    else{
      current = current->next;
      location++;
      moreToSearch = location < length1;
    }
  }//while
  return -1;//error code
}
