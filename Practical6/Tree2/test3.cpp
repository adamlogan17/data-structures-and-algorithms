#include "TreeNode.h"
#include <iostream>

using namespace std;

// search with insertion
template<typename T>
TreeNode<T>* search(T key, TreeNode<T>* tree)
{
    if (tree == NULL) // key not in tree, insert
        tree = new TreeNode<T>(key);
    else if (key < tree->item)
        tree->leftTree = search(key, tree->leftTree);
    else if (key > tree->item)
        tree->rightTree = search(key, tree->rightTree);
    return tree;
}

TreeNode<int>* bst()
{
    // given 6, 23, 12, 69, 17, 29, 7
    // after sorting: 6, 7, 12, 17, 23, 29, 69

    // using search with insertion method to build the balanced BST
    TreeNode<int>* tree = NULL;
    tree = search(17, tree);

    tree = search(7, tree);
    tree = search(6, tree);
    tree = search(12, tree);

    tree = search(29, tree);
    tree = search(23, tree);
    tree = search(69, tree);

    return tree;
}

int sigma(TreeNode<int>* tree)
{
    if (tree == NULL)
        return 0;
    else
        return tree->item + sigma(tree->leftTree) + sigma(tree->rightTree);
}

int maxnum(TreeNode<int>* tree)
{
    // return the smallest integer number defined in the system, 
    // so it is unlikely to be taken as the maximum number in the tree
    if (tree == NULL)
        return -INT_MAX;

    int max_n = tree->item;
    int temp_n = maxnum(tree->leftTree);
    if (temp_n > max_n)
        max_n = temp_n;
    temp_n = maxnum(tree->rightTree);
    if (temp_n > max_n)
        max_n = temp_n;

    return max_n;
}

int main()
{
    // build the bst
    TreeNode<int>* tree = bst();

    // sigma
    cout << "Sum of the nodes = " << sigma(tree) << endl;

    // maxnum
    cout << "Maximum number in the tree = " << maxnum(tree) << endl;

    // depth
    cout << "Depth of tree = " << tree->depth() << endl;
    // search using the search function in TreeNode class: 
    // 69 found in tree, return true (1)
    cout << tree->search(69) << endl;
    // 70, not found in tree, return false (0)
    cout << tree->search(70) << endl;

    // search using the search with insertion function: 
    // 69 found in tree, tree is unchanged
    tree = search(69, tree);
    // 70, not found in tree, 79 is inserted and new tree is returned
    tree = search(70, tree);
    cout << "Depth of tree = " << tree->depth() << endl;
    cout << "Maximum nuber in the tree = " << maxnum(tree) << endl;

    // free the tree memory
    delete tree;

    return 0;
}