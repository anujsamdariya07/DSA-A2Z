// Compare each pair of elements in the array (handling the edge case of the first element by using modulo indexing), and counts how many times nums[i - 1] > nums[i] occurs. This would equal zero for an unrotated sorted array and exactly one for a correctly rotated sorted array. If this count is greater than one, then there must be at least two decreases, indicating that the array is neither sorted nor a rotated version of a sorted array, so the function will return false. Otherwise, it returns true.

// For last element the pair will be of arr[last] & arr[0].

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  bool check(vector<int> &nums)
  {
    int size = nums.size();
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
      if (i < size - 1)
      {
        int *pair = new int[2];
        pair[0] = nums[i];
        pair[1] = nums[i + 1];

        if (pair[0] > pair[1])
        {
          counter++;
        }
      }
      else
      {
        int *pair = new int[2];
        pair[0] = nums[i];
        pair[1] = nums[0];

        if (pair[0] > pair[1])
        {
          counter++;
        }
      }
    }

    if (counter > 1)
    {
      return false;
    }

    return true;
  }
};