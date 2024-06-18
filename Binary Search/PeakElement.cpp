#include <bits/stdc++.h>

using namespace std;

int findPeakElement(vector<int> &nums)
{
  int size = nums.size();

  // Corner cases

  // Single element
  if (size == 1)
  {
    return 0;
  }
  // First Element is the peak
  if (nums[0] > nums[1])
  {
    return 0;
  }
  // Last element is the peak
  if (nums[size - 1] > nums[size - 2])
  {
    return size - 1;
  }

  // Implementation starts
  // Since, we will be comparing next and the previous element so take low and high accordingly.
  int low = 1;
  int high = size - 2;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
    {
      return mid;
    }

    // Elements to the left of peak element are in increasing order, so for left elements, nums[mid] > nums[mid-1]
    // Elements to the right of peak element are in decreasing order, so for right elements, nums[mid] < nums[mid-1]
    if (nums[mid] > nums[mid - 1])
    {
      // Left half
      // Eliminate
      low = mid + 1;
    }
    else
    {
      // Right
      // Eliminate
      high = mid - 1;
    }
  }

  return -1;
}