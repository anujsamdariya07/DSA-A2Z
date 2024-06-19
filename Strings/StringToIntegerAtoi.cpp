#include <bits/stdc++.h>

using namespace std;

string removeSpaces(string s, int length)
{
  int i = 0;
  int j = 0;

  while (j < length)
  {
    while (j < length && s[j] == ' ')
    {
      j++;
    }
    while (j < length && s[j] != ' ')
    {
      s[i] = s[j];
      i++, j++;
    }
    while (j < length && s[j] == ' ')
    {
      j++;
    }
    if (j < length)
    {
      s[i] = ' ';
      i++;
    }
  }

  return s.substr(0, i);
}

int myAtoi(string s)
{
  // Removing the spaces
  s = removeSpaces(s, s.length());

  // If empty string return 0
  if (s.empty())
  {
    return 0;
  }

  // Initialising isNegative as false
  bool isNegative = false;
  int length = s.length();
  int ans = 0;

  int i = 0;
  // Checking for '+'/'-' sign
  if (i < length && (s[i] == '-' || s[i] == '+'))
  {
    isNegative = (s[i] == '-');
    i++;
  }

  // Remiving any trailing zeroes
  while (i < length && s[i] == '0')
  {
    i++;
  }

  // Skipping any character in string
  while (i < length && isdigit(s[i]))
  {
    int digit = s[i] - '0';

    // Checking overflow and underflow conditions
    if (ans > (INT_MAX - digit) / 10)
    {
      return isNegative ? INT_MIN : INT_MAX;
    }

    ans = ans * 10 + digit;
    i++;
  }
  return isNegative ? -ans : ans;
}