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

Node *removeNthFromEnd(Node *head, int n)
{
  // For empty and single element LL
  if (head == NULL || head->next == NULL)
  {
    return NULL;
  }

  // Initialize 2 pointers
  Node *fast = head;
  Node *slow = head;

  // Move fast ahead of slow by steps equal to the n
  // provided
  while (n--)
  {
    fast = fast->next;
  }

  // If after taking steps equal to the n
  // provided, the fast ptr reaches to the end of the
  // linked list, then we have to remove the header of
  // linked list so we return the next element of  the
  // header
  if (fast == NULL)
  {
    return head->next;
  }

  // Now,if fast is not NULL, then it is exactly n steps
  // ahead of slow
  // Now we move it until it's next node reaches NULL and
  // simultaneously move ahead slow thus maintainig
  // the distance of n steps between them
  while (fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next;
  }

  // If fast's next node is NULL, means that the node
  // to slow is the node to be deleted which is nth
  //  node from behind

  // Remove it.
  slow->next = slow->next->next;

  return head;
}
