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

Node *minVal(Node *root)
{
  if (root == NULL)
  {
    return NULL;
  }

  Node *temp = root;

  while (temp->left != NULL)
  {
    temp = temp->left;
  }
  return temp;
}

Node *maxVal(Node *root)
{
  if (root == NULL)
  {
    return NULL;
  }

  Node *temp = root;

  while (temp->right != NULL)
  {
    temp = temp->right;
  }
  return temp;
}

bool searchInBST(Node *root, int target)
{
  if (root == NULL)
  {
    return false;
  }

  bool currentAns = (root->data == target);

  bool leftAns = false;
  bool rightAns = false;
  if (target > root->data)
  {
    rightAns = searchInBST(root->right, target);
  }
  else
  {
    leftAns = searchInBST(root->left, target);
  }

  return currentAns || leftAns || rightAns;
}

Node *deleteFromBST(Node *root, int target)
{
  if (root == NULL)
  {
    return NULL;
  }

  else if (root->data == target)
  {
    // 4 cases

    // Leaf Node
    if (root->left == NULL && root->right == NULL)
    {
      delete root;
      return NULL;
    }

    // Left non-null and right null
    else if (root->left != NULL && root->right == NULL)
    {
      Node *childSubTree = root->left;
      delete root;
      return childSubTree;
    }

    // Left null and right non-null
    else if (root->left == NULL && root->right != NULL)
    {
      Node *childSubTree = root->right;
      delete root;
      return childSubTree;
    }

    // Left non-null and right non-null
    else
    {
      // Max value of left subtree
      Node *maxLeft = maxVal(root->left);
      // Min value of right subtree
      Node *minRight = minVal(root->right);

      // Replacement
      root->data = maxLeft->data;
      // * Delete maxLeft (Notice that we have to store this deleted value in our left sub-tree)
      root->left = deleteFromBST(root->left, maxLeft->data);

      return root;
    }
  }
  else if (root->data > target)
  {
    // Move left
    // * Notice that we have to store this deleted value in our left sub-tree
    root->left = deleteFromBST(root->left, target);
    return root;
  }
  else
  {
    // Move right
    // * Notice that we have to store this deleted value in our right sub-tree
    root->right = deleteFromBST(root->right, target);
    return root;
  }

  return root;
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

int main()
{
  Node *root = NULL;
  createBST(root);
  // levelOrder(root);
  // levelOrder(root);

  // cout << "Min Node: " << minVal(root)->data << '\n';
  // cout << "Max Node: " << maxVal(root)->data << '\n';

  // if (searchInBST(root, 800)) {
  //   cout << "Found\n";
  // } else {
  //   cout << "Not Found\n";
  // }

  // deleteFromBST(root, 50);
  // levelOrder(root);

  vector<int> inOrder;
  toInOrder(root, inOrder);

  for (auto i: inOrder) {
    cout << i << " ";
  }
}
// 50 30 40 20 60 55 70 80 25 -1