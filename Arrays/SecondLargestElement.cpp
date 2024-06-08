#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  // Function returns the second
  // largest elements
  int print2largest(int arr[], int n)
  {
    // code here
    int maxNum = INT_MIN, secondMaxNum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      maxNum = max(maxNum, arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
      // The number must not be the maxNum and should be greater than secondMax
      if (arr[i] != maxNum)
      {
        secondMaxNum = max(secondMaxNum, arr[i]);
      }
    }

    if (secondMaxNum == INT_MIN)
    {
      return -1;
    }
    else
    {
      return secondMaxNum;
    }
  }
};