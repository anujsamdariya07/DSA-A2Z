#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string s, string t)
{
  if (s.length() != t.length())
  {
    return false;
  }

  int sArr[256]{0};

  for (auto ch : s)
  {
    sArr[ch]++;
  }

  int tArr[256]{0};

  for (auto ch : t)
  {
    tArr[ch]++;
  }

  for (auto ch : t)
  {
    if (sArr[ch] != tArr[ch])
    {
      return false;
    }
  }

  return true;
}