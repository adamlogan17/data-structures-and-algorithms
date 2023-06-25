#ifndef iSTACK_NODE_H
#define iSTACK_NODE_H

class iStackNode
{
public:
	// parameterised constructor
	iStackNode(int i, iStackNode* pNxtNode);
	// destructor
	~iStackNode();

	// public members (data & functions)
	int item;
	iStackNode* pNextNode;

private:
	// private members (data & functions)
};

#endif
