#include <bits/stdc++.h>

using namespace std;

int findFloor(vector<long long> nums, long long size, long long x)
{

  // Your code here
  long long k = INT_MIN;

  for (int i = 0; i < size; i++)
  {
    if (nums[i] > k && nums[i] <= x)
    {
      k = nums[i];
    }
  }

  int low = 0;
  int high = size - 1;
  int mid = low + (high - low) / 2;

  while (low <= high)
  {
    if (k == nums[mid])
    {
      return mid;
    }
    else if (k > nums[mid])
    {
      low = mid + 1;
    }
    else if (k < nums[mid])
    {
      high = mid - 1;
    }
    mid = low + (high - low) / 2;
  }

  return -1;
}