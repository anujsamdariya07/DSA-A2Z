#include <bits/stdc++.h>

using namespace std;

// Input Restricted Queue - Removal from only one
// side while input from both sides
class Queue
{
public:
  int size;
  int *arr;
  int front, rear;

  Queue(int size)
  {
    cout << "Circular Queue" << endl;
    this->size = size;
    arr = new int[size];
    front = -1;
    rear = -1;
  }

  void enQueue(int x)
  {
    // ! Important
    rear++;
    if (front == 0 && rear == size)
    {
      cout << "Queue Overflow" << endl;
      rear--;
      return;
    }
    else if (front != 0 && rear == size)
    {
      // Connect end to start
      rear = 0;
    }
    if (front == -1)
    {
      // First element inserted
      front = 0;
    }
    arr[rear] = x;
  }

  int deQueue()
  {
    if (front == -1)
    {
      // Underflow
      cout << "Queue Underflow" << endl;
      return -1;
    }
    if (front == rear)
    {
      // Single element Queue
      int x = arr[front];
      front = -1;
      rear = -1;
      return x;
    }
    // Storing the value to be popped
    int x = arr[front];
    arr[front] = 0;
    front++;
    if (front == size)
    {
      front = 0;
    }
    return x;
  }

  void print()
  {
    cout << "FRONT: " << arr[front] << endl;
    cout << "REAR: " << arr[rear] << endl;
    cout << "QUEUE: ";
    for (int i = 0; i < size; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main()
{
  Queue q(5);

  q.enQueue(1);
  q.print();

  q.enQueue(2);
  q.print();

  q.enQueue(3);
  q.print();

  q.enQueue(4);
  q.print();

  q.enQueue(5);
  q.print();

  q.enQueue(6);
  q.print();

  q.deQueue();
  q.print();

  q.enQueue(6);
  q.print();
}