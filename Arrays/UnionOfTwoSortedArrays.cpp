#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  // arr1,arr2 : the arrays
  //  n, m: size of arrays
  // Function to return a list containing the union of the two arrays.
  vector<int> findUnion(int arr1[], int arr2[], int n, int m)
  {
    // Your code here
    // return vector with correct order of elements

    map<int, int> mp;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
      mp[arr1[i]]++;
      if (mp[arr1[i]] == 1)
      {
        v.push_back(arr1[i]);
      }
    }

    for (int i = 0; i < m; i++)
    {
      mp[arr2[i]]++;

      if (mp[arr2[i]] == 1)
      {
        v.push_back(arr2[i]);
      }
    }

    sort(v.begin(), v.end());

    return v;
  }
};