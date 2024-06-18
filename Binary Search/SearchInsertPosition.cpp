#include <bits/stdc++.h>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{
  int size = nums.size();

  int low = 0;
  int high = size - 1;
  int mid = low + (high - low) / 2;

  while (low <= high)
  {
    if (target == nums[mid])
    {
      return mid;
    }
    else if (target > nums[mid])
    {
      low = mid + 1;
    }
    else if (target < nums[mid])
    {
      high = mid - 1;
    }
    mid = low + (high - low) / 2;
  }

  return low;
}