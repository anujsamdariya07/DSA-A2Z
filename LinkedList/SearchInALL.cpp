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

// Function to count nodes of a linked list.
bool searchKey(int n, struct Node *head, int key)
{
  // Code here
  struct Node *temp = head;

  while (temp->next != NULL)
  {
    if (temp->data == key)
      return true;
    temp = temp->next;
  }

  return false;
}