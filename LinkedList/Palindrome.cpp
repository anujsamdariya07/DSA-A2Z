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

Node *reversedLL(Node *head)
{
  // Make the curr and prev elements
  Node *curr = head;
  Node *prev = NULL;

  Node *temp = NULL;

  // Iterate through the list
  while (curr != NULL)
  {
    temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }

  return prev;
}

bool isPalindrome(Node *head)
{
  // For empty or single element list
  if (head == NULL || head->next == NULL)
  {
    return true;
  }

  // Find the middle element o the list
  Node *fast = head;
  Node *slow = head;

  while (fast != NULL && fast->next != NULL)
  {
    fast = fast->next->next;
    slow = slow->next;
  }

  // Slow will be the  middle element

  // Reversing the other half of the list
  Node *reversedHead = reversedLL(slow);

  Node *temp = head;
  Node *reversedTemp = reversedHead;

  while (reversedTemp != NULL)
  {
    if (temp->data != reversedTemp->data)
    {
      return false;
    }
    temp = temp->next;
    reversedTemp = reversedTemp->next;
  }

  return true;
}
