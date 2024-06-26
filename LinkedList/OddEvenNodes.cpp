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

Node *oddEvenList(Node *head)
{
  // Making two nodes with 0 val
  Node evenHead(0);
  Node oddHead(0);

  // Making there two node ptrs
  Node *even = &evenHead;
  Node *odd = &oddHead;

  // Initializing counter
  int counter = 0;

  // If counter is odd add it in odd node otherwise in even node
  while (head)
  {
    counter++;
    if (counter & 1)
    {
      odd->next = head;
      odd = odd->next;
    }
    else
    {
      even->next = head;
      even = even->next;
    }
    head = head->next;
  }

  // Join even with odd and return odd
  odd->next = evenHead.next;
  even->next = NULL;
  return oddHead.next;
}