#include <bits/stdc++.h>

using namespace std;

int findKRotation(int nums[], int size)
{
  // code here
  // No of rotations = index of minimum elements

  int low = 0;
  int high = size - 1;

  int minVal = INT_MAX;
  int minIndex = -1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (minVal > nums[mid])
    {
      minVal = nums[mid];
      minIndex = mid;
    }

    if (nums[mid] > nums[high])
    {
      if (minVal > nums[low] && minVal < nums[mid])
      {
        minVal = nums[low];
        minIndex = low;
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
        minVal = nums[mid];
        minIndex = mid;
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
  }
  return minIndex;
}