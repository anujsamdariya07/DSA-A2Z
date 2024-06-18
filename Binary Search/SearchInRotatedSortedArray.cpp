#include <bits/stdc++.h>

using namespace std;

int search(vector<int> &nums, int target)
{
  int size = nums.size();

  int low = 0;
  int high = size - 1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (target == nums[mid])
    {
      return mid;
    }

    if (nums[low] <= nums[mid]) // nums[l..m] are sorted.
    {
      if (target >= nums[low] && target < nums[mid])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    else // nums[m..n - 1] are sorted.
    {
      if (target > nums[mid] && target <= nums[high])
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
  }

  return -1;
}