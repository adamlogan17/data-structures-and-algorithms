#include "iStack.h"
#include <iostream>
using namespace std;

iStack::iStack()
{
	pTos = NULL;
	stackSize = 0;
}

iStack::iStack(const iStack& isr)
{
	// push isr content into a temp stack in LIFO
	iStack* is_temp = new iStack;
	iStackNode* pisrTos = isr.pTos;
	while (pisrTos != NULL) {
		is_temp->push(pisrTos->item);
		pisrTos = pisrTos->pNextNode;
	}

	// push temp stack content into THIS stack in LIFO
	while (is_temp->pTos)
		push(is_temp->pop());
	delete is_temp;
}

iStack::~iStack()
{
	/*while (pTos != NULL) {
		iStackNode* pNewTos = pTos->pNextNode;
		delete pTos;
		pTos = pNewTos;
	}*/
	while (stackSize != 0)
		pop();
	cout << "Destructor called." << endl;
}

int iStack::push(int i)
{
	iStackNode* pNewTos = new iStackNode(i, pTos);
	pTos = pNewTos;
	stackSize++;
	return i;
}

int iStack::pop()
{
	if (pTos) {
		int item = pTos->item;
		iStackNode* pNewTos = pTos->pNextNode;
		delete pTos;
		pTos = pNewTos;
		stackSize--;
		return item;
	}
	exit(0);
}

int iStack::size()
{
	return stackSize;
}

int iStack::operator+(int i)
{
	return push(i);
}

int iStack::operator-()
{
	return pop();
}

// (1)
void iStack::print()
{
	iStackNode* pNewTos = pTos;
	while (pNewTos) {
		cout << pNewTos->item << endl;
		pNewTos = pNewTos->pNextNode;
	}
	cout << endl;
}

// (2)
int iStack::search(int key)
{
	iStackNode* pNewTos = pTos;
	int pos = stackSize;
	while (pos-- > 0) {
		if (pNewTos->item == key)
			return pos;
		pNewTos = pNewTos->pNextNode;
	}
	return -1;
}
