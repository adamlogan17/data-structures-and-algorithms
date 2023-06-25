#ifndef iSTACK_H
#define iSTACK_H

#include "iStackNode.h"

class iStack
{
public:
	iStack();		 // parameter-less constructor
	iStack(const iStack& isr);	// copy constructor
	~iStack();		 // destructor

	int push(int i); // push item i onto stack
	int pop();		 // pop off top item 
	int size();		 // return number of items in stack

	int operator+(int i); // overload + for push
	int operator-();      // overload - for pop

	// (1)
	void print();
	// (2)
	int search(int key);

private:
	iStackNode* pTos;
	int stackSize;
};

#endif 