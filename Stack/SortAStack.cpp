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

void insertInASortedStack(stack<int> &st, int element)
{
  if (st.empty() || element >= st.top())
  {
    st.push(element);
    return;
  }

  // 1 case
  int temp = st.top();
  st.pop();

  // Recursion
  insertInASortedStack(st, element);

  // Bactrack
  st.push(temp);
}

void sortStack(stack<int> &st)
{
  if (st.empty())
  {
    return;
  }

  // 1 case
  int temp = st.top();
  st.pop();

  // Recursin
  sortStack(st);

  // Bactrack
  insertInASortedStack(st, temp);
}

int main()
{
  stack<int> st;

  st.push(100);
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);

  print(st);

  sortStack(st);

  print(st);
}