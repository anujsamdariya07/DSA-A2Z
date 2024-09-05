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

bool solve(Node *root, long long int lowerBound, long long int upperBound)
{
  if (root == NULL)
  {
    return true;
  }

  bool cond1 = (root->data > lowerBound);
  bool cond2 = (root->data < upperBound);
  bool leftAns = solve(root->left, lowerBound, root->data);
  bool rightAns = solve(root->right, root->data, upperBound);

  if (cond1 && cond2 && leftAns && rightAns)
  {
    return true;
  }
  return false;
}

bool isValidBST(Node *root)
{
  // int lowerBound = INT_MIN;
  // int upperBound = INT_MAX;

  long long int lowerBound = -2147483657;
  long long int upperBound = 2147483657;

  bool ans = solve(root, lowerBound, upperBound);
  return ans;
}

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
  if (root == NULL)
  {
    return NULL;
  }

  // Both p, q present in lst
  if (p->data < root->data && q->data < root->data)
  {
    return lowestCommonAncestor(root->left, p, q);
  }
  // Both p, q present in rst
  else if (p->data > root->data && q->data > root->data)
  {
    return lowestCommonAncestor(root->right, p, q);
  }
  // p present in left of root and q present in right of root
  else if (p->data < root->data && q->data > root->data)
  {
    return root;
  }
  // p present in right of root and q present in left of root
  else if (p->data > root->data && q->data < root->data)
  {
    return root;
  }

  return root;
}

// * pass k by reference
int kthSmallest(Node *root, int &k)
{
  if (root == NULL)
  {
    return -1;
  }

  // LNR
  // L
  int leftAns = kthSmallest(root->left, k);
  if (leftAns != -1)
    return leftAns;
  // N
  k--;
  if (k == 0)
  {
    return root->data;
  }
  // R
  int rightAns = kthSmallest(root->right, k);
  if (rightAns != -1)
    return rightAns;

  return -1;
}

void toInOrder(Node *root, vector<int> &inOrder)
{
  if (root == NULL)
  {
    return;
  }
  // LNR
  // L
  toInOrder(root->left, inOrder);
  // N
  inOrder.push_back(root->data);
  // R
  toInOrder(root->right, inOrder);
}

bool findTarget(Node *root, int k)
{
  if (root == NULL)
  {
    return false;
  }

  vector<int> inOrder;
  toInOrder(root, inOrder);

  int start = 0;
  int end = inOrder.size() - 1;

  while (start < end)
  {
    int sum = inOrder[start] + inOrder[end];
    if (sum == k)
    {
      return true;
    }
    else if (sum < k)
    {
      start++;
    }
    else if (sum > k)
    {
      end--;
    }
  }

  return false;
}

int main()
{
  int inOrder[] = {10, 20, 30, 40, 50, 60, 70};
  int start = 0;
  int end = 6;
  Node *root = inOrderToBST(inOrder, start, end);
  levelOrder(root);
}