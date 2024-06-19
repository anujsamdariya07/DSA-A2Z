#include <bits/stdc++.h>

using namespace std;

// Left shift
void shift(string &s)
{
  char temp = s[0];
  s.erase(0, 1);
  s += temp;
}

bool rotateString(string s, string goal)
{
  // Traversing through the string
  for (auto ch : s)
  {
    if (s == goal)
      return true;
    shift(s);
  }

  return false;
}