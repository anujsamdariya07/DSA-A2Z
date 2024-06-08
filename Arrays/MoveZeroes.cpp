#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  void moveZeroes(vector<int> &nums)
  {
    int size = nums.size();
    int index = 0;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
      if (nums[i] != 0)
      {
        nums[index] = nums[i];
        index++;
      }
      else
      {
        count++;
      }
    }

    while (index < size)
    {
      nums[index] = 0;
      index++;
    }
  }
};