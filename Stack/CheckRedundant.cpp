#include <bits/stdc++.h>

using namespace std;

bool checkRedundant(string &s)
{
  stack<char> st;

  for (int i = 0; i < s.length(); i++)
  {
    char ch = s[i];

    if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
      st.push(ch);
    }
    else if (ch == ')')
    {
      int operatorCount = 0;
      while (!st.empty() && st.top() != '(')
      {
        char temp = st.top();
        if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
        {
          operatorCount++;
        }
        st.pop();
      }
      // You will reach here only when '(' has been found
      st.pop();

      if (operatorCount == 0)
      {
        return true;
      }
    }
  }
  // If we are here that means there is an operator for each () , then no redundanty brackets
  return false;
}

int main()
{
  string str = "(((a+b)*(c+d)))";
  bool ans = checkRedundant(str);

  if (ans)
  {
    cout << "Redundant Brackets Present" << endl;
  }
  else
  {
    cout << "Redundant Brackets Not Present" << endl;
  }
}