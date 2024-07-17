#include <bits/stdc++.h>

using namespace std;

class Queue
{
public:
  int size;
  int *arr;
  int front, rear;

  Queue(int size)
  {
    this->size = size;
    arr = new int[size];
    front = 0;
    rear = 0;
  }

  void enQueue(int x)
  {
    if (rear == size)
    {
      // Overflow
      cout << "Queue Overflow" << endl;
      return;
    }
    arr[rear] = x;
    rear++;
  }

  void deQueue()
  {
    if (front == rear)
    {
      // Underflow
      cout << "Queue Underflow" << endl;
      return;
    }
    arr[front] = 0;
    for (int i = 0; i < rear; i++)
    {
      arr[i] = arr[i + 1];
    }
    arr[rear - 1] = 0;
    rear--;
  }

  void front()
  {
    return arr[front];
  }

  void rear()
  {
    return arr[rear];
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
  Queue q(10);

  q.enQueue(4);
  q.print();

  q.enQueue(1);
  q.print();

  q.enQueue(3);
  q.print();

  q.deQueue();
  q.print();

  q.enQueue(8);
  q.print();

  q.deQueue();
  q.print();
}