#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    this->data = val;
    this->left = NULL;
    this->right = NULL;
  }
};

Node *insertIntoBST(Node *root, int data)
{
  if (root == NULL)
  {
    // This is the first node
    root = new Node(data);
    return root;
  }

  // Not the first node
  if (data > root->data)
  {
    root->right = insertIntoBST(root->right, data);
  }
  else
  {
    root->left = insertIntoBST(root->left, data);
  }

  return root;
}

void createBST(Node *&root)
{
  cout << "Enter data: ";
  int data;
  cin >> data;

  while (data != -1)
  {
    root = insertIntoBST(root, data);
    cout << "Enter data: ";
    cin >> data;
  }
}


void levelOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  cout << "Level Order Traversal:-" << '\n';

  while (!q.empty())
  {
    Node *front = q.front();
    q.pop();

    if (front == NULL)
    {
      cout << endl;
      if (!q.empty())
      {
        q.push(NULL);
      }
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

void storeInOrderTraversal(Node* root, vector<int> &inOrder)
{
  if (root == NULL) 
  {
    return;
  }

  // LNR
  storeInOrderTraversal(root->left, inOrder);
  inOrder.push_back(root->data);
  storeInOrderTraversal(root->right, inOrder);
}

void replaceUsingPostOrder(Node* root, vector<int> inOrder, int &index)
{
  if (root == NULL)
  {
    return;
  }
  
  // LRN
  replaceUsingPostOrder(root->left, inOrder, index);
  replaceUsingPostOrder(root->right, inOrder, index);
  root->data = inOrder[index];
  index++;
}

Node* convertBSTtoMaxHeap(Node* root) 
{
  // Store inorder
  vector<int> inOrder;
  storeInOrderTraversal(root, inOrder);

  // Replace node values with the inorder values using post order traversal
  int index = 0;
  replaceUsingPostOrder(root, inOrder, index);

  return root;
}

int main()
{
  Node *root = NULL;
  createBST(root);
  levelOrder(root);

  Node* heap = convertBSTtoMaxHeap(root);
  levelOrder(heap);

}