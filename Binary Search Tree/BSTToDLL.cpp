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

Node *inOrderToBST(int inOrder[], int start, int end)
{
  if (start > end)
  {
    return NULL;
  }

  int mid = (start + end) / 2;
  int middleElement = inOrder[mid];

  Node *root = new Node(middleElement);

  root->left = inOrderToBST(inOrder, start, mid - 1);
  root->right = inOrderToBST(inOrder, mid + 1, end);

  return root;
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

void BSTtoDLL(Node *root, Node *&head)
{
  if (root == NULL)
  {
    return;
  }

  // RNL
  // R
  BSTtoDLL(root->right, head);
  // N
  root->right = head;
  if (head != NULL)
  {
    head->left = root;
  }
  head = root;
  // L
  BSTtoDLL(root->left, head);
}

Node* DLLtoBST(Node* &head, int n)
{
  if (head == NULL || n <= 0)
  {
    return NULL;
  }

  // L
  Node* leftTree = DLLtoBST(head, n/2);
  // N
  Node* root = head;
  root->left = leftTree;
  // Updating head
  head = head->right;
  // R
  Node* rightTree = DLLtoBST(head, n-(n/2)-1);
  root->right = rightTree;

  return root;  
}

void printLL(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << "<->";
    temp = temp->right;
  }
}

int main()
{
  // Node *root = NULL;
  // createBST(root);
  int inOrder[] = {5, 50, 60, 100, 200, 300};
  int start = 0;
  int end = 5;
  Node *root = inOrderToBST(inOrder, start, end);
  levelOrder(root);

  Node *head = NULL;
  BSTtoDLL(root, head);
  printLL(head);

  root = DLLtoBST(head, 6);
  levelOrder(root);
}