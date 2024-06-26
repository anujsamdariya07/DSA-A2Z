#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data;
  Node *next;

  // Default constructor
  Node()
  {
    data = 0;
    next = NULL;
  }

  // Parameterised Constructor
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};

Node *segregate(Node *head)
{
  // Add code here
  vector<int> v;

  Node *temp = head;
  while (temp != NULL)
  {
    v.push_back(temp->data);
    temp = temp->next;
  }

  sort(v.begin(), v.end());

  temp = head;
  int i = 0;
  while (temp != NULL)
  {
    temp->data = v[i];
    i++;
    temp = temp->next;
  }

  return head;
}
