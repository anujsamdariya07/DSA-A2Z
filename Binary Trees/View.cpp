#include <bits/stdc++.h>

using namespace std;

class Node {
public:
  int data;
  Node* left;
  Node* right;

  Node(int val)
  {
    this->data = val;
    this->left = NULL;
    this->right = NULL;
  }
};

Node* createTree()
{
  cout << "Enter value: ";
  int value;
  cin >> value;

  if (value == -1)
  {
    return NULL;
  }

  Node* root = new Node(value);

  cout << "Entering to the left of " << value << ": ";
  root->left = createTree();

  cout << "Entering to the right of " << value << ": ";
  root->right = createTree();

  return root;
}

void preOrder(Node* root)
{
  if (root == NULL)
  {
    return;
  }

  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(Node* root)
{
  if (root == NULL)
  {
    return;
  }

  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

void postOrder(Node* root)
{
  if (root == NULL)
  {
    return;
  }

  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

void levelOrderTraversal(Node* root)
{
  if (root == NULL)
  {
    return;
  }

  queue<Node*> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    Node* front = q.front();
    q.pop();

    if (front == NULL)
    {
      cout << endl;
      if (!q.empty())
      {
        q.push(NULL);
      }
    }
    else {
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

void leftViewUsingLevelOrderTraversal(Node *root)
{
  // TODO: Solve this using level order traversal
  // Using level order traversal printing the front element of the queue when NULL occurs
  // if (root == NULL)
  // {
  //   return;
  // }

  // queue<Node *> q;
  // q.push(root);
  // q.push(NULL);
  // cout << "LEVEL ORDER: " << '\n' << root->data << ' ';

  // while (!q.empty()) -> infinite loop for last NULL
  // while (q.size() > 1)
  // {
  //   Node *front = q.front();
  //   q.pop();

  //   if (front == NULL && q.size() > 1)
  //   {
  //     cout << q.front() << " ";
  //     q.push(NULL);
  //   }
  //   else
  //   {
  //     if (front->left != NULL)
  //     {
  //       q.push(front->left);
  //     }
  //     if (front->right != NULL)
  //     {
  //       q.push(front->right);
  //     }
  //   }
  // }
}

void leftViewUsingRecursion(Node* root, vector<int> &leftView, int level = 0) {
  if (root == NULL) {
    return;
  }

  if (level == leftView.size())
  {
    leftView.push_back(root->data);
  }

  leftViewUsingRecursion(root->left, leftView, level+1);
  leftViewUsingRecursion(root->right, leftView, level+1);
}

void rightViewUsingRecursion(Node* root, vector<int> &rightView, int level = 0) {
  if (root == NULL) {
    return;
  }

  if (level == rightView.size())
  {
    rightView.push_back(root->data);
  }

  rightViewUsingRecursion(root->right, rightView, level+1);
  rightViewUsingRecursion(root->left, rightView, level+1);
}

void printTopView(Node* root)
{
  map<int, int> hdToVal;
  queue< pair<Node*, int> > q;

  q.push(make_pair(root, 0));


  while (!q.empty())
  {
    pair<Node*, int> temp = q.front();
    q.pop();

    Node* frontNode = temp.first;
    int hd = temp.second;

    if (hdToVal.find(hd) == hdToVal.end())
    {
      // If we are here implies that hd is not present in the hdToVal map
      hdToVal[hd] = frontNode->data;
    }

    if (frontNode->left != NULL)
    {
      q.push(make_pair(frontNode->left, hd-1));
    }
    if (frontNode->right != NULL)
    {
      q.push(make_pair(frontNode->right, hd+1));
    }
  }

  cout << "Top View: ";
  for (auto i: hdToVal)
  {
    cout << i.second << " ";
  } cout << '\n';
}

void printBottomView(Node* root)
{
  map<int, int> hdToVal;
  queue< pair<Node*, int> > q;

  q.push(make_pair(root, 0));


  while (!q.empty())
  {
    pair<Node*, int> temp = q.front();
    q.pop();

    Node* frontNode = temp.first;
    int hd = temp.second;

    // if (hdToVal.find(hd) == hdToVal.end())
    // {
      // If we are here implies that hd is not present in the hdToVal map
    //   hdToVal[hd] = frontNode->data;
    // }

    hdToVal[hd] = frontNode->data;

    if (frontNode->left != NULL)
    {
      q.push(make_pair(frontNode->left, hd-1));
    }
    if (frontNode->right != NULL)
    {
      q.push(make_pair(frontNode->right, hd+1));
    }
  }

  cout << "Bottom View: ";
  for (auto i: hdToVal)
  {
    cout << i.second << " ";
  } cout << '\n';
}

void printLeftBoundary(Node* root)
{
  if (root == NULL || (root->left == NULL && root->right == NULL))
  {
    return;
  }

  cout << root->data << " ";
  if (root->left != NULL) {
    printLeftBoundary(root->left);
  } else {
    printLeftBoundary(root->right);
  }
}

void printLeafNodes(Node* root)
{
  if (root == NULL)
  {
    return;
  }

  // L
  printLeafNodes(root->left);
  
  // N
  if (root->left == NULL && root->right == NULL)
  {
    cout << root->data << " ";
  }

  // R
  printLeafNodes(root->right);
}

void printRightBoundary(Node* root)
{
  if (root == NULL || (root->left == NULL && root->right == NULL))
  {
    return;
  }

  if (root->right != NULL) {
    printRightBoundary(root->right);
  } else {
    printRightBoundary(root->left);
  }
  cout << root->data << " ";
}

void printBoundaryTraversal(Node* root)
{
  if (root == NULL)
  {
    return;
  }

  cout << "Boundary Traversal: ";
  printLeftBoundary(root);
  printLeafNodes(root);
  if (root->right != NULL) {
    printRightBoundary(root->right);
  } else {
    printRightBoundary(root->left);
  }
  cout << '\n';
}

int main()
{
  Node *root = createTree();
  cout << '\n';
  levelOrderTraversal(root);

  vector<int> leftView;
  leftViewUsingRecursion(root, leftView);
  // cout <<  "Left View: ";
  // for (auto node: leftView)
  // {
  //   cout << node << " ";
  // }
  
  vector<int> rightView;
  rightViewUsingRecursion(root, rightView);
  // cout << '\n' << "Right View: ";
  // for (auto node: rightView)
  // {
  //   cout << node << " ";
  // } cout << '\n';

  // printTopView(root);
  // printBottomView(root);

  cout << "Left Boundary: ";
  printLeftBoundary(root);
  cout << '\n';

  cout << "Leaf Nodes: ";
  printLeafNodes(root);
  cout << '\n';

  cout << "Right Boundary: ";
  printRightBoundary(root);
  cout << '\n';

  printBoundaryTraversal(root);
}

// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1