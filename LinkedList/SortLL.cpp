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

Node *sortList(Node *head)
{
  // Intialize a vector array
  vector<int> v;

  Node *temp = head;
  while (temp != NULL)
  {
    // Store all the dataues of the list in the array
    v.push_back(temp->data);
    temp = temp->next;
  }

  // Sort  the array
  sort(v.begin(), v.end());

  temp = head;
  int i = 0;
  while (temp != NULL)
  {
    // Put all the dataues of the  sorted array
    temp->data = v[i];
    temp = temp->next;
    i++;
  }

  return head;
}
