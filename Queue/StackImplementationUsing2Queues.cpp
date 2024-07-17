#include <bits/stdc++.h>

using namespace std;

class Stack
{
public:
  queue<int> q1;
  queue<int> q2;

  void push(int x)
  {
    q2.push(x);
    while (!q1.empty())
    {
      q2.push(q1.front());
      q1.pop();
    }
    q1.swap(q2);
  }

  int pop()
  {
    int val = q1.front();
    q1.pop();
    return val;
  }

  int top()
  {
    if (q1.empty())
    {
      return -1;
    }
    return q1.front();
  }

  void print()
  {
    cout << "TOP: " << q1.front() << endl;
    cout << "STACK" << endl;
    queue<int> q = q1;
    while (!q.empty())
    {
      cout << q.front() << endl;
      q.pop();
    }
    cout << "---" << endl;
  }
};

int main()
{
  Stack st;

  st.push(10);
  st.print();

  st.push(20);
  st.print();

  st.push(30);
  st.print();

  st.push(40);
  st.print();

  st.push(50);
  st.print();

  st.pop();
  st.print();
}