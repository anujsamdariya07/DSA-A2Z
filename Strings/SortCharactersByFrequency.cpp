#include <bits/stdc++.h>

using namespace std;

static bool cmp(pair<char, int> &a, pair<char, int> &b)
{
  return a.second > b.second;
}

string frequencySort(string s)
{
  // Find out frequencies and store them in a map
  unordered_map<char, int> mp;
  for (auto ch : s)
  {
    mp[ch]++;
  }
  // Make a vector of pairs containing chars and there mapped frequencies
  vector<pair<char, int>> v(mp.begin(), mp.end());
  // Sort the vector in terms of frequencies
  sort(v.begin(), v.end(), cmp);
  // Make a result string and add vector values to it with .second, first and then .first
  string ans;
  for (auto &p : v)
  {
    ans += string(p.second, p.first);
  }

  return ans;
}