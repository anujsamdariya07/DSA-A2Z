#include <bits/stdc++.h>

using namespace std;

class Queue
{
public:
  stack<int> st1;
  stack<int> st2;

  void push(int val)
  {
    // * Instead of pushing the element at the top of st1 and then 
    // * popping all the elements from st1 and pushing them to st2,
    // * we can push the element at the bottom of st1 and then
    // * popping all the elements from st1 and pushing them to st2
    // * This way, the element is pushed at the bottom of st1 and
    // * the oldest element is at the top of st1
    if (st1.empty())
    {
      st1.push(val);
      return;
    }
    while (!st1.empty())
    {
      st2.push(st1.top());
      st1.pop();
    }
    st1.push(val);
    while (!st2.empty())
    {
      st1.push(st2.top());
      st2.pop();
    }
  }

  void pop()
  {
    if (st1.empty())
    {
      cout << "Queue Underflow" << endl;
      return;
    }
    st1.pop();
  }

  int frontElement()
  {
    if (st1.empty())
    {
      return -1;
    }
    return st1.top();
  }

  int backElement()
  {
    if (st1.empty())
    {
      return -1;
    }
    stack<int> st3 = st1;
    while (!st3.empty())
    {
      st2.push(st3.top());
      st3.pop();
    }
    st3.swap(st2);
    return st3.top();
  }

  void print()
  {
    cout << "FRONT: " << frontElement() << endl;
    cout << "BACK: " << backElement() << endl;
    cout << "QUEUE: ";
    stack<int> st3 = st1;
    while (!st3.empty())
    {
      cout << st3.top() << " ";
      st3.pop();
    }
    cout << endl;
  }
};

int main()
{
  Queue q;

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

  q.pop();
  q.print();
}
