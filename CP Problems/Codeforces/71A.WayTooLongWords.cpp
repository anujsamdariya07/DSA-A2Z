#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string str;
    string ans = "";
    cin >> str;
    
    int n = str.length();
    int n_n = str.length()-2;
    if (str.length() <= 10)
    {
      cout << str << endl;
    }
    else
    { 
      ans = ans + str[0] + to_string(n_n) + str[n-1];
      cout<< ans <<endl;
    }
  }
}