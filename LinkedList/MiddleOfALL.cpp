#include <iostream>

using namespace std;

class Node
{
public:
  Node *prev;
  int data;
  Node *next;

  Node()
  {
    prev = NULL;
    data = 0;
    next = NULL;
  }

  Node(int value)
  {
    prev = NULL;
    data = value;
    next = NULL;
  }
};

int getLength(Node *head)
{
  if (head == NULL)
    return 0;
  int length = 1;
  Node *temp = head;
  while (temp->next != NULL)
  {
    length++;
    temp = temp->next;
  }
  return length;
}

Node *middleNode(Node *head)
{
  // Calculate the length of LL
  int length = getLength(head);

  // calculate the middle element
  int mid = length / 2 + 1;

  int counter = 1;
  Node *temp = head;
  while (counter < mid)
  {
    counter++;
    temp = temp->next;
  }
  return temp;
}