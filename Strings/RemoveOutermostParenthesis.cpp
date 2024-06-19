#include <bits/stdc++.h>

using namespace std;

string removeOuterParentheses(string s)
{
  int counter = 0;
  string ans;

  for (auto ch : s)
  {
    if (ch == '(')
    {
      counter++;
      if (counter > 1)
      {
        // '(' is not the outermost element
        // Include in the result
        ans += ch;
      }
    }
    else
    {
      // ch === ')'
      counter--;
      if (counter > 0)
      {
        // ')' is not the outermost element
        // Include the result
        ans += ch;
      }
    }
  }

  return ans;
}