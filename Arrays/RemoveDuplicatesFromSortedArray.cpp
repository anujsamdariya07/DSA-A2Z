#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int size = nums.size();
    int count = 0;

    for (int i = 0; i < size; i++)
    {
      if (i < size - 1 && nums[i] == nums[i + 1])
      {
        continue;
      }

      nums[count] = nums[i];
      count++;
    }
    return count;
  }
};