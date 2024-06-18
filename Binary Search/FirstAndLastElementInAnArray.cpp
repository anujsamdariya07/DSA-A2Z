#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &nums, int target, bool lowBias)
{
  int size = nums.size();

  int low = 0, high = size - 1;
  int index = -1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (target > nums[mid])
    {
      low = mid + 1;
    }
    else if (target < nums[mid])
    {
      high = mid - 1;
    }
    else
    {
      index = mid;

      // Important
      if (lowBias)
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
  }

  return index;
}

vector<int> searchRange(vector<int> &nums, int target)
{
  int size = nums.size();

  int low = binarySearch(nums, target, true);
  int high = binarySearch(nums, target, false);

  return {low, high};
}