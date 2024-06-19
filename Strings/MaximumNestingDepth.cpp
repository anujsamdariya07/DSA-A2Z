#include <bits/stdc++.h>

using namespace std;

int maxDepth(string s)
{
  int counter = 0;
  int nd = 0;

  for (auto ch : s)
  {
    if (ch == '(')
    {
      counter++;
    }
    else if (ch == ')')
    {
      counter--;
    }
    nd = max(nd, counter);
  }

  return nd;
}