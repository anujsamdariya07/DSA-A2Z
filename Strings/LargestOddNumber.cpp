#include <bits/stdc++.h>

using namespace std;

string largestOddNumber(string num)
{
  // We start from (length-1) because we are given to find the largest string
  for (int i = num.length() - 1; i >= 0; i--)
  {
    // Take out the first element of the string
    int digit = (int)num[i];

    // If the digit is odd, then return the substring between 0 to i
    if ((digit & 1) == 1)
    {
      return num.substr(0, i + 1);
    }
  }

  return "";
}