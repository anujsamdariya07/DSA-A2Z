#include <bits/stdc++.h>

using namespace std;

void print(stack<int> st)
{
  cout << "Stack: ";
  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }
  cout << endl;
}

void insertAtBottom(stack<int> &st, int element)
{
  // Base condition
  if (st.empty())
  {
    st.push(element);
    return;
  }

  // 1 case
  int temp = st.top();
  st.pop();
  insertAtBottom(st, element);

  // Backtracking
  st.push(temp);
}

void reverseStack(stack<int> &st)
{
  // Base condition
  if (st.empty())
  {
    return;
  }
  
  // 1 case
  int temp = st.top();
  st.pop();

  // Recursion
  reverseStack(st);

  // Backtracking
  insertAtBottom(st, temp);
}

int main()
{
  stack<int> st;

  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);

  print(st);

  reverseStack(st);

  print(st);
}