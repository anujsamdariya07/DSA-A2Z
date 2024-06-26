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

int countNodesinLoop(struct Node *head)
{
  // Initializing slow and fast pointers
  Node *fast = head;
  Node *slow = head;

  // Iterating through the list
  while (fast != NULL && fast->next != NULL)
  {
    // Moving the fast ptr by two steps
    fast = fast->next->next;
    // Moving the slow ptr by one step
    slow = slow->next;

    // If slow and fast ptr meet, a loop is present
    if (slow == fast)
    {
      // Finding the starting point of the loop
      slow = head;
      while (slow != fast)
      {
        slow = slow->next;
        fast = fast->next;
      }

      // Counting the number of nodes in the loop
      Node *temp = slow;
      int loopLength = 1;
      while (temp->next != slow)
      {
        temp = temp->next;
        loopLength++;
      }

      return loopLength;
    }
  }

  return 0; // No loop
}