#include <bits/stdc++.h>

using namespace std;

int romanToInt(string s)
{
  int num = 0;

  for (int i = s.length() - 1; i >= 0; i--)
  {
    char ch = s[i];

    if (ch == 'I')
    {
      num += 1;
    }
    else if (ch == 'V')
    {
      if (i > 0 && s[i - 1] == 'I')
      {
        num += 4;
        i--;
      }
      else if ((i > 0 && s[i - 1] != 'I') || (i == 0))
      {
        num += 5;
      }
    }
    else if (ch == 'X')
    {
      if (i > 0 && s[i - 1] == 'I')
      {
        num += 9;
        i--;
      }
      else if ((i > 0 && s[i - 1] != 'I') || (i == 0))
      {
        num += 10;
      }
    }
    else if (ch == 'L')
    {
      if (i > 0 && s[i - 1] == 'X')
      {
        num += 40;
        i--;
      }
      else if ((i > 0 && s[i - 1] != 'X') || (i == 0))
      {
        num += 50;
      }
    }
    else if (ch == 'C')
    {
      if (i > 0 && s[i - 1] == 'X')
      {
        num += 90;
        i--;
      }
      else if ((i > 0 && s[i - 1] != 'X') || (i == 0))
      {
        num += 100;
      }
    }
    else if (ch == 'D')
    {
      if (i > 0 && s[i - 1] == 'C')
      {
        num += 400;
        i--;
      }
      else if ((i > 0 && s[i - 1] != 'C') || (i == 0))
      {
        num += 500;
      }
    }
    else if (ch == 'M')
    {
      if (i > 0 && s[i - 1] == 'C')
      {
        num += 900;
        i--;
      }
      else if ((i > 0 && s[i - 1] != 'C') || (i == 0))
      {
        num += 1000;
      }
    }
  }

  return num;
}