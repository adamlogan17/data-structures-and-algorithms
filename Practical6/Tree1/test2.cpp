#include <iostream>
#include "TreeNode.h"

using namespace std;

int main()
{
	// build week day tree
	// leaf nodes
	TreeNode<string>* fri = new TreeNode<string>("Friday");
	TreeNode<string>* sat = new TreeNode<string>("Saturday");
	TreeNode<string>* thu = new TreeNode<string>("Thursday");
	TreeNode<string>* wed = new TreeNode<string>("Wednesday");
	// nodes on level 1
	TreeNode<string>* mon = new TreeNode<string>("Monday", fri, sat);
	TreeNode<string>* tue = new TreeNode<string>("Tuesday", thu, wed);
	// root node / whole tree
	TreeNode<string>* tree = new TreeNode<string>("Sunday", mon, tue);

	// search
	cout << "Which day you are searching for: ";
	string day;
	cin >> day;
	if (tree != NULL && tree->search(day))
		cout << "Found." << endl;
	else
		cout << "Not found." << endl;

	// depth
	if (tree != NULL)
		cout << "Depth of the tree = " << tree->depth() << endl;
	else
		cout << "Depth of the tree = 0" << endl;

	// free tree memory
	delete tree;

	return 0;
}
