#include <bits/stdc++.h>

using namespace std;

int binarySearch(int nums[], int size, int target, int lowBias)
{
  int low = 0;
  int high = size - 1;

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

int count(int nums[], int size, int target)
{
  // code here
  int low = binarySearch(nums, size, target, true);
  int high = binarySearch(nums, size, target, false);

  // if low is -1 then there will be no right as well so no need to mention it
  if (low == -1)
  {
    return 0;
  }

  return (high - low + 1);
}