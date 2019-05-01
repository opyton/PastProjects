#ifndef SortedLinkedList_h
#define SortedLinkedList_h

#include "ListNode.h"
class SortedLinkedList{
 private:
  int iterate;
  int length1;
  ListNode *head;
  ListNode *currentPos;
   
 public:
  SortedLinkedList();
  ~SortedLinkedList();
  void random();
  int length() const;
  void insertItem(ItemType item);
  void deleteItem(ItemType item);
  int searchItem(ItemType &item);
  void clear();
  void reverse();
  void print();
  void itrNext();
  void resetList();    
};
#endif 