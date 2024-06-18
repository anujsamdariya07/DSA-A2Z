#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int> &nums)
{
  int size = nums.size();

  int low = 0;
  int high = size - 1;
  int minVal = INT_MAX;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (nums[mid] < minVal)
    {
      minVal = nums[mid];
    }

    if (nums[mid] > nums[high])
    {
      if (minVal > nums[low] && minVal < nums[mid])
      {
        minVal = nums[low];
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    else
    {
      if (minVal > nums[mid] && minVal < nums[high])
      {
        minVal = nums[high];
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
  }
  return minVal;
}