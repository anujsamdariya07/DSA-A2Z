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

Node *detectCycle(Node *head)
{
  if (head == NULL)
    return NULL;

  // Make fast and slow ptrs
  Node *fast = head;
  Node *slow = head;

  while (fast != NULL)
  {
    fast = fast->next;

    if (fast != NULL)
    {
      fast = fast->next;
      slow = slow->next;
    }

    if (fast == slow)
      break;
  }

  if (fast == NULL)
    return NULL;

  slow = head;

  while (slow != fast)
  {
    fast = fast->next;
    slow = slow->next;
  }

  return slow;
}