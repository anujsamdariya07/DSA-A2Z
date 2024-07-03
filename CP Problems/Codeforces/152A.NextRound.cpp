#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  int counter = 0;
  vector<int> v(n);

  for (int i = 0; i < n; i++) 
  {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) 
  {
    // kth place starting from 1 = (k-1)th place starting from 0
    if (v[i] >= v[k-1] && v[i] > 0)
    {
      counter++;
    }
  }
  
  cout << counter;
}