#include <bits/stdc++.h>

using namespace std;

// Using single queue
class Stack
{
public:
  queue<int> q;

  void push(int val)
  {
    // ! Important - Size must be taken before pushing the
    // ! new value, not after it
    int size = q.size();
    q.push(val);
    for (int i = 0; i < size; i++)
    {
      q.push(q.front());
      q.pop();
    }
  }

  void pop()
  {
    if (q.empty())
    {
      // Underflow
      cout << "Stack Underflow" << endl;
      return;
    }
    q.pop();
  }

  void print()
  {
    cout << "TOP: " << q.front() << endl;
    cout << "STACK" << endl;
    queue<int> q1 = q;
    while (!q1.empty())
    {
      cout << q1.front() << endl;
      q1.pop();
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
