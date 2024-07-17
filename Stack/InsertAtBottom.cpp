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
  if (st.empty())
  {
    st.push(element);
    return;
  }

  int temp = st.top();
  st.pop();
  insertAtBottom(st, element);

  st.push(temp);
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

  int element = 40;
  insertAtBottom(st, element);

  print(st);
}