#include <bits/stdc++.h>

using namespace std;

bool search(vector<int> &nums, int target)
{
  int size = nums.size();

  int low = 0;
  int high = size - 1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (nums[mid] == target)
    {
      return true;
    }

    if (nums[mid] > nums[high])
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
    else if (nums[mid] < nums[high])
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
    // Important
    else
    {
      high--;
    }
  }

  return false;
}