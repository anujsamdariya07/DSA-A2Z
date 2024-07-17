#include <bits/stdc++.h>
using namespace std;
// If queue is reversed than operations are reversed as well
int main()
{
  int n;
  cin >> n;

  bool reverse = false;

  deque<int> d;

  while (n--)
  {
    string s;
    cin >> s;

    if (s == "toFront")
    {
      int val;
      cin >> val;

      if (!reverse)
      {
        d.push_front(val);
      }
      else
      {
        d.push_back(val);
      }
    }
    else if (s == "push_back")
    {
      int val;
      cin >> val;

      if (reverse)
      {
        d.push_front(val);
      }
      else
      {
        d.push_back(val);
      }
    }
    else if (s == "front")
    {
      if (d.empty())
      {
        cout << "No job for Ada?" << endl;
      }
      else
      {
        if (!reverse)
        {
          cout << d.front() << endl;
          d.pop_front();
        }
        else
        {
          cout << d.back() << endl;
          d.pop_back();
        }
      }
    }
    else if (s == "back")
    {
      if (d.empty())
      {
        cout << "No job for Ada?" << endl;
      }
      else
      {
        if (reverse)
        {
          cout << d.front() << endl;
          d.pop_front();
        }
        else
        {
          cout << d.back() << endl;
          d.pop_back();
        }
      }
    }
    else if (s == "reverse")
    {
      reverse = !reverse;
    }
  }

  return 0;
}