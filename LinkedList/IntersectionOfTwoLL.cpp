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

Node *getIntersectionNode(Node *headA, Node *headB)
{
  if (headA == NULL || headB == NULL)
  {
    return NULL;
  }

  Node *tempA = headA;
  Node *tempB = headB;
  while (tempA != NULL)
  {
    tempB = headB;
    while (tempB != NULL)
    {
      if (tempA == tempB)
      {
        return tempA;
      }
      tempB = tempB->next;
    }
    tempA = tempA->next;
  }

  return NULL;
}