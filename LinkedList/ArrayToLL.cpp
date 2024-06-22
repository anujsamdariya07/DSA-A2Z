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

Node *constructLL(vector<int> &nums)
{
  // code here
  int size = nums.size();

  if (nums.size() == 0)
  {
    return NULL;
  }

  Node *head = new Node(nums[0]);
  Node *current = head;

  for (int i = 1; i < size; i++)
  {
    current->next = new Node(nums[i]);
    current = current->next;
  }

  return head;
}