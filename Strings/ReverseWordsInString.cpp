#include <bits/stdc++.h>

using namespace std;

void reverseWords(string &s, int length)
{
  int start = 0;
  int end = 0;

  while (start < length)
  {
    while (start < length && s[start] == ' ')
    {
      start++;
    }

    end = start;
    while (end < length && s[end] != ' ')
    {
      end++;
    }

    reverse(s.begin() + start, s.begin() + end);
    start = end; // Move start to the end of the current word
  }
}

string removeTrailingSpaces(string &s, int length)
{
  int start = 0;
  int end = 0;

  while (end < length)
  {
    while (end < length && s[end] == ' ')
    {
      end++;
    }
    while (end < length && s[end] != ' ')
    {
      s[start++] = s[end++];
    }
    while (end < length && s[end] == ' ')
    {
      end++;
    }
    if (end < length)
    {
      s[start++] = ' ';
    }
  }

  return s.substr(0, start);
}

string reverseWords(string s)
{
  reverse(s.begin(), s.end());
  reverseWords(s, s.length());
  string ans = removeTrailingSpaces(s, s.length());
  return ans;
}