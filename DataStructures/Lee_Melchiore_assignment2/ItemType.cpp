#include "ItemType.h"
using namespace std;

ItemType::ItemType(){
  value = 0;
  ValSet=true;
}

ItemType::ItemType(int num){
  value = num;
  ValSet=true;
}

//Checks if a valueset exists
bool ItemType::ValueSet(){
  return ValSet;
}

// Compares to current pointed item
Comparison ItemType :: compareTo(ItemType item){  
  if (value < item.value)
    return LESS;
  else if (value > item.value)
    return GREATER;
  else
    return EQUAL;    
}

//getValue
int ItemType :: getValue() const{
  return value;
}

//insert number
void ItemType :: initialize(int num) {
  value = num;
  ValSet=true;
}