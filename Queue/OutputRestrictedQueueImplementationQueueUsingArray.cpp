#include <bits/stdc++.h>

using namespace std;

// Input Restricted Queue - Removal from only one
// side while input from both sides
class Queue
{
public:
  int *arr;
  int size;
  int front, rear;

  Queue(int size)
  {
    cout << "Output Restricted Queue" << endl;
    this->size = size;
    arr = new int[size];
    front = 0;
    rear = 0;
  }

  void push_back(int x)
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

  void push_front(int x)
  {
    if (rear == size)
    {
      // Overflow
      cout << "Queue Overflow" << endl;
      return;
    }
    // Shifting array to right by 1
    for (int i = rear; i > 0; i--)
    {
      arr[i] = arr[i - 1];
    }
    arr[0] = x;
    rear++;
  }

  void pop()
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

  q.push_back(10);
  q.print();

  q.push_back(20);
  q.print();

  q.push_back(30);
  q.print();

  q.push_back(40);
  q.print();

  q.push_back(50);
  q.print();

  q.push_front(100);
  q.print();

  q.push_front(200);
  q.print();

  q.push_front(300);
  q.print();

  q.push_front(400);
  q.print();

  q.pop();
  q.print();

  q.pop();
  q.print();

  q.pop();
  q.print();
}