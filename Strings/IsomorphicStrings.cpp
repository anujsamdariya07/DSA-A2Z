#include <bits/stdc++.h>

using namespace std;

bool isIsomorphic(string s, string t)
{
  if (s.length() != t.length())
  {
    return false;
  }

  int arr1[256]{0};
  int arr2[256]{0};

  for (int i = 0; i < s.length(); i++)
  {
    if (arr1[s[i]] != 0 && arr1[s[i]] != t[i])
    {
      return false;
    }
    else if (arr1[s[i]] == 0 || arr1[s[i]] == t[i])
    {
      arr1[s[i]] = t[i];
    }
  }

  for (int i = 0; i < t.length(); i++)
  {
    if (arr2[t[i]] != 0 && arr2[t[i]] != s[i])
    {
      return false;
    }
    else if (arr2[t[i]] == 0 || arr2[t[i]] == s[i])
    {
      arr2[t[i]] = s[i];
    }
  }

  return true;
}