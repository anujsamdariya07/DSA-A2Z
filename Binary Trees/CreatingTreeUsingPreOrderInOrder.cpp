#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node()
  {
    left = NULL;
    right = NULL;
  }

  Node(int data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

// It creates root node of the created root
Node *createTree()
{
  cout << "Enter value of node: ";
  int data;
  cin >> data;

  if (data == -1)
  {
    return NULL;
  }

  // 1. Create node
  Node *root = new Node(data);

  // 2. Create left subtree
  cout << "Left of node: " << root->data << endl;
  root->left = createTree();

  // 3. Create right subtree
  cout << "Right of node: " << root->data << endl;
  root->right = createTree();

  return root;
}

void preOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  // NLR
  // N
  cout << root->data << " ";
  // L
  preOrder(root->left);
  // R
  preOrder(root->right);
}

void inOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  // LNR
  // L
  inOrder(root->left);
  // N
  cout << root->data << " ";
  // R
  inOrder(root->right);
}

void postOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  // LRN
  // L
  postOrder(root->left);
  // R
  postOrder(root->right);
  // N
  cout << root->data << " ";
}

void levelOrderTraversal(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  queue<Node *> q;
  q.push(root);
  cout << "LEVEL ORDER: ";

  while (!q.empty())
  {
    Node *front = q.front();
    cout << front->data << " ";
    q.pop();
    if (front->left != NULL)
    {
      q.push(front->left);
    }
    if (front->right != NULL)
    {
      q.push(front->right);
    }
  }
}

// Printing level wise
void levelOrderTraversal2(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  queue<Node *> q;
  q.push(root);
  q.push(NULL);
  cout << '\n' << "LEVEL ORDER: " << '\n';

  // while (!q.empty()) -> infinite loop for last NULL
  while (q.size() > 1)
  {
    Node *front = q.front();
    q.pop();

    if (front == NULL)
    {
      cout << endl;
      q.push(NULL);
    }
    else
    {
      cout << front->data << " ";
      if (front->left != NULL)
      {
        q.push(front->left);
      }
      if (front->right != NULL)
      {
        q.push(front->right);
      }
    }
  }
}

int heightOfTree(Node *root)
{
  // Using recursion
  // Base case
  // if (root == NULL) return 0;

  // int leftHeight = maxDepth(root->left);
  // int rightHeight = maxDepth(root->right);
  // int height = 1 + max(leftHeight, rightHeight);
  // return height;

  // Using level-order traversal

  if (root == NULL)
  {
    return 0;
  }

  queue<Node *> q;
  q.push(root);
  q.push(NULL);
  int count = 1;
  cout << "LEVEL ORDER: ";

  // while (!q.empty()) -> infinite loop for last NULL
  while (q.size() > 1)
  {
    Node *front = q.front();
    q.pop();

    if (front == NULL)
    {
      cout << endl;
      count++;
      q.push(NULL);
    }
    else
    {
      cout << front->data << " ";
      if (front->left != NULL)
      {
        q.push(front->left);
      }
      if (front->right != NULL)
      {
        q.push(front->right);
      }
    }
  }
  return count;
}

int searchInOrder(int inOrder[], int size, int element)
{
  for (int i = 0; i < size; i++)
  {
    if (element == inOrder[i])
    {
      return i;
    }
  }
  return -1;
}

int createMapping(int inOrder[], int size, map<int, int> &mp) {
  for (int i = 0; i < size; i++)
  {
    int element = inOrder[i];
    int index = i;
    mp[element] = index;
  }
  
}

Node* constructTreeFromPreOrderAndInOrderTraversal(int preOrder[], int inOrder[], int size, int &preOrderIndex, int inOrderStartingIndex, int inOrderEndingIndex, map<int, int> &mp) // * Pass preOrderIndex by reference
{
  // Base case
  if (preOrderIndex >= size || inOrderStartingIndex > inOrderEndingIndex)
  {
    return NULL;
  }

  // 1. Solving 1 case
  int element = preOrder[preOrderIndex];
  preOrderIndex++;

  Node* root = new Node(element);

  // Search this element in inOrder[]
  // int position = searchInOrder(inOrder, size, element); --> O(n)
  // If not using mp, then remove it from the fucntion as well
  int position = mp[element];// O(1) complexity

  // * 2. Recursive Call(Order is very important) - NLR
  // Left Call
  root->left = constructTreeFromPreOrderAndInOrderTraversal(preOrder, inOrder, size, preOrderIndex, inOrderStartingIndex, position-1, mp);
  // Right Call
  root->right = constructTreeFromPreOrderAndInOrderTraversal(preOrder, inOrder, size, preOrderIndex, position+1, inOrderEndingIndex, mp);

  return root;
}

Node* constructTreeFromPostOrderAndInOrderTraversal(int postOrder[], int inOrder[], int size, int &postOrderIndex, int inOrderStartingIndex, int inOrderEndingIndex, map<int, int> &mp) // * Pass postOrderIndex by reference
{
  // Base case
  // * postOrderIndex < 0 instead of >= 0
  if (postOrderIndex < 0 || inOrderStartingIndex > inOrderEndingIndex)
  {
    return NULL;
  }

  // 1. Solving 1 case
  int element = postOrder[postOrderIndex];
  postOrderIndex--;

  Node* root = new Node(element);

  // Search this element in inOrder[]
  // int position = searchInOrder(inOrder, size, element); --> O(n)
  // If not using mp, then remove it from the fucntion as well
  int position = mp[element];// O(1) complexity

  // * 2. Recursive Call(Order is very important) - LRN
  // Right Call
  root->right = constructTreeFromPostOrderAndInOrderTraversal(postOrder, inOrder, size, postOrderIndex, position+1, inOrderEndingIndex, mp);
  // Left Call
  root->left = constructTreeFromPostOrderAndInOrderTraversal(postOrder, inOrder, size, postOrderIndex, inOrderStartingIndex, position-1, mp);

  return root;
}

int main()
{
  int preOrder[] = {2, 8, 10, 6, 4, 12};
  int inOrder[] = {10, 8, 6, 2, 4, 12};
  int size = 6;
  int preOrderIndex = 0;
  int inOrderStartingIndex = 0;
  int inOrderEndingIndex = 5;

  map<int, int> mp;
  createMapping(inOrder, size, mp);

  Node* root = constructTreeFromPreOrderAndInOrderTraversal(preOrder, inOrder, size, preOrderIndex, inOrderStartingIndex, inOrderEndingIndex, mp);

  cout << "Using Pre-order Traversal:" ;
  levelOrderTraversal2(root);

  int postOrder[] = {10, 6, 8, 12, 4, 2};
  int postOrderIndex = 5;

  root = constructTreeFromPostOrderAndInOrderTraversal(postOrder, inOrder, size, postOrderIndex, inOrderStartingIndex, inOrderEndingIndex, mp);

  cout << '\n' << "Using Post-order Traversal:" ;
  levelOrderTraversal2(root);
}