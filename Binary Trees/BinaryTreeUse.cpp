#include<iostream>
#include "BinaryTreeNode.h"
using namespace std;


BinaryTreeNode<int> * takeInput() {
  int rootData;
  cout << "Enter  data" << endl;
  cin >> rootData;
  if (rootData == -1)
    return NULL;

  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

  BinaryTreeNode<int> *leftSubTree = takeInput();
  BinaryTreeNode<int> *rightSubTree = takeInput();

  root->left = leftSubTree;
  root->right = rightSubTree;

  return root;
}

void printTree(BinaryTreeNode<int> * root) {
  if (!root)
    return;
  cout << root->data << ":";
  if (root->left)
    cout << "L" << root->left->data << ",";
  if (root->right)
    cout << "R" << root->right->data;
  cout << endl;
  printTree(root->left);
  printTree(root->right);
}

int main() {
  /*
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
  BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
  BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);

  root->left = node1;
  root->right = node2;
*/

  BinaryTreeNode<int> *root = takeInput();


  printTree(root);
  delete root;
  return 0;
}
