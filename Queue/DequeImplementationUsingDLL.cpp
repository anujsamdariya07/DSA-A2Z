#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;

  Node()
  {
    this->next = NULL;
    this->prev = NULL;
  }

  Node(int data)
  {
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
  }
};

class Deque
{
public:
  Node *front;
  Node *rear;

  Deque()
  {
    front = NULL;
    rear = NULL;
  }

  void push_front(int x)
  {
    Node *temp = new Node(x);
    if (front == NULL)
    {
      // Empty queue
      front = temp;
      rear = temp;
      return;
    }
    temp->next = front;
    front->prev = temp;
    front = temp;
  }

  void push_back(int x)
  {
    Node *temp = new Node(x);
    if (front == NULL)
    {
      // Empty queue
      front = temp;
      rear = temp;
      return;
    }
    rear->next = temp;
    temp->prev = rear;
    rear = temp;
  }

  void pop_front()
  {
    if (front == NULL)
    {
      // Underflow
      cout << "Queue Underflow" << endl;
      return;
    }
    Node *temp = front;
    if (front->next == NULL)
    {
      // Single element queue
      front = NULL;
      rear = NULL;
      delete temp;
    }
    front = front->next;
    front->prev = NULL;
  }

  void pop_back()
  {
    if (front == NULL)
    {
      // Underflow
      cout << "Queue Underflow" << endl;
      return;
    }
    Node *temp = rear;
    if (rear->prev == NULL)
    {
      // Single element queue
      front = NULL;
      rear = NULL;
      delete temp;
      return;
    }
    rear = rear->prev;
    rear->next = NULL;
    delete temp;
  }

  void print()
  {
    Node *temp = front;
    cout << "FRONT: " << ((front->data != NULL) ? (front->data) : (-1)) << endl;
    cout << "REAR: " << ((rear->data != NULL) ? (rear->data) : (-1)) << endl;
    cout << "QUEUE: ";
    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main()
{
  Deque d;

  d.push_front(10);
  d.print();

  d.push_front(20);
  d.print();

  d.push_front(30);
  d.print();

  d.push_back(40);
  d.print();

  d.push_back(50);
  d.print();

  d.pop_front();
  d.print();

  d.pop_back();
  d.print();
}