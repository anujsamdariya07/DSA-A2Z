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

// Function to insert a node at the beginning of the linked list.
Node *insertAtBegining(Node *head, int x)
{
  // Your code here
  Node *newNode = new Node(x);

  if (head == NULL)
    return newNode;

  newNode->next = head;

  head = newNode;

  return head;
}

// Function to insert a node at the end of the linked list.
Node *insertAtEnd(Node *head, int x)
{
  // Your code here
  Node *newNode = new Node(x);

  if (head == NULL)
    return newNode;

  Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  temp->next = newNode;

  newNode->next = NULL;

  return head;
}