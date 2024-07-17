#include <bits/stdc++.h>

using namespace std;

// Input Restricted Queue - Input from only one
// side while removal from both sides
class Queue
{
public:
  int *arr;
  int size;
  int front, rear;

  Queue(int size)
  {
    cout << "Input Restricted Queue" << endl;
    this->size = size;
    arr = new int[size];
    front = 0;
    rear = 0;
  }

  void push(int x)
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

  void pop_back()
  {
    if (front == rear)
    {
      // Underflow
      cout << "Queue Underflow" << endl;
      return;
    }
    rear--;
  }

  void pop_front()
  {
    if (front == rear)
    {
      // Underflow
      cout << "Queue Underflow" << endl;
      return;
    }
    // Move array to left by 1 position
    for (int i = 0; i < rear - 1; i++)
    {
      arr[i] = arr[i + 1];
    }
    arr[rear - 1] = 0;
    rear--;
  }

  void print()
  {
    cout << "FRONT: " << arr[front] << endl;
    cout << "REAR: " << arr[rear - 1] << endl;
    cout << "QUEUE: ";
    for (int i = 0; i < rear; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main()
{
  Queue q(10);

  q.push(10);
  q.print();

  q.push(20);
  q.print();

  q.push(30);
  q.print();

  q.push(40);
  q.print();

  q.push(50);
  q.print();

  q.push(10);
  q.print();

  q.push(20);
  q.print();

  q.push(30);
  q.print();

  q.push(40);
  q.print();

  q.push(50);
  q.print();

  q.pop_front();
  q.print();

  q.pop_back();
  q.print();
}