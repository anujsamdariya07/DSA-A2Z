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

bool hasCycle(Node *head)
{
  if (head == NULL)
    return false;

  // Using map
  // map<Node*, int> mp;

  // Node* temp = head;

  // while (temp->next != NULL) {
  //   if (!mp[temp]) {
  //     mp[temp]++;
  //   } else {
  //     return true;
  //   }
  //   temp = temp->next;
  // }

  // return false;

  // Hare and tortoise algorithm
  // Fast and slow ptrs
  Node *fast = head;
  Node *slow = head;

  while (fast != NULL && fast->next != NULL)
  {
    // slow moves 1 step at a time and fast moves 2 steps at a time
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
      return true;
  }

  return false;
}