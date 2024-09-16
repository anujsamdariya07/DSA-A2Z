#include<bits/stdc++.h>

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


pair<int, bool> CBTValidHeap(Node* root)
{
  // Base case
  if (root == NULL)
  {
    pair<int, bool> p;
    p.first = INT_MIN;
    p.second = true;
    return p;
  }
  if (root->left == NULL && root->right == NULL)
  {
    pair<int, bool> p;
    p.first = root->data;
    p.second = true;
    return p;
  }

  pair<int, bool> leftAns = CBTValidHeap(root->left);
  pair<int, bool> rightAns = CBTValidHeap(root->right);

  if (root->data > leftAns.first && root->data > rightAns.first && leftAns.second && rightAns.second)
  {
    pair<int, bool> p;
    p.first = root->data;
    p.second = true;
    return p;
  }
  else
  {
    pair<int, bool> p;
    p.first = max(root->data, max(leftAns.first, rightAns.first));
    p.second =  false;
    return p;
  }
  
}

bool levelOrderTraversal(Node *root)
{
  if (root == NULL)
  {
    return true;
  }

  queue<Node *> q;
  q.push(root);

  bool nullFound = false;

  while (!q.empty())
  {
    Node *front = q.front();
    q.pop();

    if (front == NULL)
    {
      nullFound = true;
    }
    else
    {
      if (nullFound)
      {
        return false;
      }
      q.push(front->left);
      q.push(front->right);
    }
  }
  return true;
}


int main()
{
  
}