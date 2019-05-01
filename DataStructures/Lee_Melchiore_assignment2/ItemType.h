#ifndef ItemType_h
#define ItemType_h

enum Comparison {
	GREATER, LESS, EQUAL 
};
class ItemType{
	private:
  		int value;
  		bool ValSet=false;
 	public:
  		bool ValueSet();
  		ItemType(int value);
  		ItemType();
  		void initialize(int num);
  		Comparison compareTo(ItemType item);
  		int getValue() const;
};
#endif