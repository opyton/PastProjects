#ifndef ListNode_h
#define ListNode_h

#include "ItemType.h"
struct ListNode{
public:
  ItemType item;
  ListNode *next;
  ListNode(ItemType &item);
};
#endif