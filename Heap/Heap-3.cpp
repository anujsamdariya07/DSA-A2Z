#include <bits/stdc++.h>

using namespace std;

class Info
{
public:
  char ch;
  int count;

  Info(char ch, int count)
  {
    this->ch = ch;
    this->count = count;
  }
};

class compare
{
public:
  bool operator()(Info a, Info b)
  {
    return a.count < b.count;
  }
};

// 1
int minStoneSum(vector<int> &piles, int k)
{
  // Push all values in a max heap
  priority_queue<int> pq;
  for (int i = 0; i < piles.size(); i++)
  {
    pq.push(piles[i]);
  }

  // Remove top, subtract floor(top/2) from it, and then push it back
  while (k--)
  {
    int top = pq.top();
    pq.pop();

    top = top - floor(top / 2);

    pq.push(top);
  }

  // FInd out sum of the heap by iterating over it
  int sum = 0;
  while (!pq.empty())
  {
    int top = pq.top();
    pq.pop();

    sum += top;
  }

  return sum;
}

// 2
string reorganizeString(string s)
{
  // If a letter occurs more than n/2 times than we can not rearrange it

  // Storing ther frequency of the chs in the string
  int freq[26]{0};
  for (int i = 0; i < s.length(); i++)
  {
    char ch = s[i];
    freq[ch - 'a']++;
  }

  // Making a max heap
  priority_queue<Info, vector<Info>, compare> pq;

  // Push all the chs in the heap whose frequency > 0
  for (int i = 0; i < 26; i++)
  {
    if (freq[i] > 0)
    {
      char ch = 'a' + i;
      int count = freq[i];
      Info temp(ch, count);
      pq.push(temp);
    }
  }

  string ans = "";

  // Iterate through the map
  while (pq.size() > 1)
  {
    Info first = pq.top();
    pq.pop();
    Info second = pq.top();
    pq.pop();

    ans.push_back(first.ch);
    first.count--;
    ans.push_back(second.ch);
    second.count--;

    if (first.count > 0)
    {
      pq.push(first);
    }
    if (second.count > 0)
    {
      pq.push(second);
    }
  }

  // If pq.size() == 1 -> one element still remaining
  if (pq.size() == 1)
  {
    Info first = pq.top();
    pq.pop();
    ans.push_back(first.ch);
    first.count--;

    if (first.count != 0)
    {
      // We cannot find the required string for this input
      return "";
    }
  }

  return ans;
}

// 3