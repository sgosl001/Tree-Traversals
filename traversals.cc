#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <stack>
#include "helper.hh"

using namespace std;

template <typename T>
vector<T> preorderTraversalNoRecursion(Node<T>* root) {
  vector<T> preorder;
  stack<Node<T>*> st;
  Node<T>* n = root;
  if (root == NULL)
    return preorder;
  // 1. root
  while (n != NULL)
  {
    preorder.push_back(n->value);
    if (n->left != NULL)
    {
      if (n->right != NULL)
      {
        st.push(n->right);
      }
      n = n->left;
    }
    else if (n->right != NULL)
    {
      n = n->right;
    }
    else if (st.size() != 0)
    {
      n = (st.top());
      st.pop();
    }
    else
    {
      n = NULL;
    }
  }
}
  
  
  /*// 2. Preorder left
  vector<T> preorderLeft = preorderTraversalNoRecursion(root->left);
  preorder.insert(preorder.end(), preorderLeft.begin(), preorderLeft.end());
  // 3. Preorder right
  vector<T> preorderRight = preorderTraversalNoRecursion(root->right);
  preorder.insert(preorder.end(), preorderRight.begin(), preorderRight.end());
  return preorder;
}*/

template <typename T>
vector<T> inorderTraversalNoRecursion(Node<T>* root) {
  vector<T> inorder;
  stack<Node<T>*> st;
  Node<T>* n = root;
  
  if (n == NULL)
  {
    return inorder;
  }
  
  while (!st.empty() || n != NULL)
  {
    if (n != NULL)
    {
      st.push(n);
      n = n->left;
    }
    
    else
    {
      n = st.top();
      st.pop();
      inorder.push_back(n->value);
      n = n->right;
    }
  }
}
  /*// 1. Inorder left
  vector<T> inorderLeft = inorderTraversalNoRecursion(root->left);
  inorder.insert(inorder.end(), inorderLeft.begin(), inorderLeft.end());
  // 2. root
  inorder.push_back(root->value);
  // 3. Inorder right
  vector<T> inorderRight = inorderTraversalNoRecursion(root->right);
  inorder.insert(inorder.end(), inorderRight.begin(), inorderRight.end());

  return inorder; */

void testPreorder() {
  Node<int>* root = buildTree(vector<int>({1}), vector<int>({1}));
  vector<int> preorder = preorderTraversalNoRecursion(root);
  ASSERT_EQ(vector<int>({1}), preorder);
  delete(root);
  
  root = buildTree(vector<int>({10, 8, 3, 5, 2, 7}), vector<int>({3, 8, 5, 10, 7, 2}));
  preorder = preorderTraversalNoRecursion(root);
  ASSERT_EQ(vector<int>({10, 8, 3, 5, 2, 7}), preorder);
  delete(root);

  root = buildTree(vector<int>({1, 2, 3, 4, 5}), vector<int>({1, 4, 3, 2, 5}));
  preorder = preorderTraversalNoRecursion(root);
  ASSERT_EQ(vector<int>({1, 2, 3, 4, 5}), preorder);
  delete(root);
}


void testInorder() {
  Node<int>* root = buildTree(vector<int>({1}), vector<int>({1}));
  vector<int> inorder = inorderTraversalNoRecursion(root);
  ASSERT_EQ(vector<int>({1}), inorder);
  delete(root);
  
  root = buildTree(vector<int>({10, 8, 3, 5, 2, 7}), vector<int>({3, 8, 5, 10, 7, 2}));
  inorder = inorderTraversalNoRecursion(root);
  ASSERT_EQ(vector<int>({3, 8, 5, 10, 7, 2}), inorder);
  delete(root);
  
  root = buildTree(vector<int>({1, 2, 3, 4, 5}), vector<int>({1, 4, 3, 2, 5}));
  inorder = inorderTraversalNoRecursion(root);
  ASSERT_EQ(vector<int>({1, 4, 3, 2, 5}), inorder);
  delete(root);
}


int main() {
  testBuildTree();
  testPreorder();
  testInorder();
  
  Node<int>* root = buildTree(vector<int>({10, 8, 3, 5, 2, 7}), vector<int>({3, 8, 5, 10, 7, 2}));
  vector<int> preorder = preorderTraversalNoRecursion(root);
  vector<int> inorder = inorderTraversalNoRecursion(root);
  cout << "Preorder: " << preorder << endl
       << "Inorder: " << inorder << endl;
  cout << "Finished succesfully!" << endl;
}

