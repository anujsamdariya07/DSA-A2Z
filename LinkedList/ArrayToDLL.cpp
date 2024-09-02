#include <bits/stdc++.h>

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

Node *constructDLL(vector<int> &nums)
{
  // code here
  int size = nums.size();

  Node *head = new Node(nums[0]);
  head->prev = NULL;

  Node *temp = head;

  for (int i = 1; i < size; i++)
  {
    temp->next = new Node(nums[i]);
    temp->next->prev = temp;
    temp = temp->next;
  }

  return head;
}