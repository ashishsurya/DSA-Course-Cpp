#include<iostream>
#include<queue>
using namespace std;
#include "TreeNode.h"
void postorder(TreeNode<int> * root) {
  if (root == NULL )
    return;
  for (int i = 0; i < root->children.size();i++) {
    postorder(root->children[i]);
  }
  cout << root->data << " ";
}
void preOrder(TreeNode<int> * root) {
  if (root == NULL )
    return;
  cout << root->data << " ";
  for (int i = 0; i < root->children.size();i++) {
    preOrder(root->children[i]);
  }
}

int heightOfTree(TreeNode<int> * root) {
  if (root == NULL)
    return 0;
  int max = 0;
  for (int i = 0; i < root->children.size();i++) {
    int childheight = heightOfTree(root->children[i]);
    if (childheight > max) {
      childheight = max;
    }
  }
  return max+1;
}

// returns node with maximum data (each node has unique data).
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
   if(root == NULL){
        return root;
    }
    
    TreeNode<int> *maximum = root;
    
    for(int i = 0; i < root -> children.size() ;i++) {
        TreeNode<int> *temp = maxDataNode(root -> children[i]);
        if(temp -> data > maximum -> data) {
            maximum = temp;
        }	
    }
    return maximum;
}

// return no of nodes
int countNodes(TreeNode<int> * root) {
  if (root == NULL)
    return 0;
  int ans = 0;
  for (int i = 0; i < root->children.size();i++) {
    ans += countNodes(root->children[i]);
  }

  return ans + 1;
}

// taking input level wise
TreeNode<int> * takeInputLevelWise() {
  int rootData;
  cout << "Enter root data" << endl;
  cin >> rootData;
  TreeNode<int> *root = new TreeNode<int>(rootData);

  queue<TreeNode<int> *> pendingNodes;

  pendingNodes.push(root);

  while(!pendingNodes.empty()) {
    TreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    int n;
    cout << "Enter no of children of " << front->data << endl;
    cin >> n;
    for (int i = 0; i < n;i++){
      int childData;
      cout << "Enter " << i << "th child of " << front->data << endl;
      cin >> childData;
      TreeNode<int> *childNode = new TreeNode<int>(childData);
      front->children.push_back(childNode);
      pendingNodes.push(childNode);
    }
  }

  return root;
}

// taking input top to bottom...
TreeNode<int> * takeInput() {
  int rootData;
  cout << "Enter root data" << endl;
  cin >> rootData;
  TreeNode<int> *root = new TreeNode<int>(rootData);


  int n;
  cout << "Enter how many children for " << rootData << endl;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    TreeNode<int> *child = takeInput();
    root->children.push_back(child);
  }

  return root;
}

void printTree(TreeNode<int> * root) {

// edge case not a base case.
  if (root == NULL)
    return;

  cout << root->data << ":";
  for (int i = 0; i < root->children.size();i++) {
    cout << root->children[i]->data << ",";
  }
  cout << endl;
  for (int i = 0; i < root->children.size(); i++)
  {
    printTree(root->children[i]);
  }
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

int main() {
  // TreeNode<int> *root = new TreeNode<int>(1);
  // TreeNode<int> *node1 = new TreeNode<int>(2);
  // TreeNode<int> *node2 = new TreeNode<int>(3);

  // TreeNode<int> *node3 = new TreeNode<int>(4);
  // TreeNode<int> *node4 = new TreeNode<int>(5);


  // root->children.push_back(node1);
  // root->children.push_back(node2);

  // node1->children.push_back(node3);
  // node1->children.push_back(node4);

  TreeNode<int> *root = takeInputLevelWise();

  // printTree(root);
  cout << countNodes(root) << endl;


  cout << "Pre Order" << endl;
  preOrder(root);
  cout << endl;


  cout << "Post Order" << endl;
  postorder(root);
  cout << endl;

  // TODO delete the tree
  return 0;
}
