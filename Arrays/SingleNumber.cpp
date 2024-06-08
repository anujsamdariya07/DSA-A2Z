#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    int size = nums.size();

    int singleNumber = 0;

    for (int i = 0; i < size; i++)
    {
      singleNumber ^= nums[i];
    }

    return singleNumber;
  }
};