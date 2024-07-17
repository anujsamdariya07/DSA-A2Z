#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node()
  {
    this->next = NULL;
  }

  Node(int data)
  {
    this->next = NULL;
    this->data = data;
  }
};

class Queue
{
public:
  Node *front;
  Node *rear;

  Queue()
  {
    front = NULL;
    rear = NULL;
  }

  void enQueue(int val)
  {
    Node *temp = new Node(val);
    if (front == NULL)
    {
      front = temp;
    }
    else
    {
      rear->next = temp;
    }
    rear = temp;
    rear->next = front;
  }

  void deQueue()
  {
    if (front == NULL)
    {
      // Underflow
      cout << "Queue Underflow" << endl;
      return;
    }
    if (front == rear)
    {
      Node *temp = front;
      front = NULL;
      rear = NULL;
      delete temp;
      return;
    }
    Node *temp = front;
    front = front->next;
    rear->next = front;
    delete temp;
  }

  void print()
  {
    Node *temp = front;
    cout << "FRONT: " << front->data << endl;
    cout << "REAR: " << rear->data << endl;
    cout << "QUEUE: ";
    cout << temp->data << " ";
    temp = temp->next;
    while (temp != front)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main()
{
  Queue q;

  q.enQueue(10);
  q.print();

  q.enQueue(20);
  q.print();

  q.enQueue(30);
  q.print();

  q.enQueue(40);
  q.print();

  q.deQueue();
  q.print();

  q.deQueue();
  q.print();
}