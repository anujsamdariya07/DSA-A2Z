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

int getCount(struct Node *head)
{
  // Code here
  if (head == NULL)
    return 0;

  int length = 1;
  Node *temp = head;

  while (temp->next != NULL)
  {
    ++length;
    temp = temp->next;
  }

  return length;
}