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

ListNode *reverseList(ListNode *head)
{
  if (head == NULL)
    return NULL;

  ListNode *curr = head;
  ListNode *prev = NULL;

  while (curr != NULL)
  {
    ListNode *temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }

  head = prev;

  return head;
}