#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
  int size = strs.size();

  if (size == 1)
  {
    return strs[0];
  }

  string common = strs[0];

  for (int i = 0; i < size; i++)
  {
    string str = strs[i];

    int j = 0;

    while (j < common.length() && j < str.length() && common[j] == str[j])
    {
      j++;
    }

    common = common.substr(0, j);

    if (common.empty())
    {
      return "";
    }
  }

  return common;
}