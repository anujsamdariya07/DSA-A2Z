#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  void swap(int *a, int *b)
  {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

  void reverseArray(vector<int> &nums, int left, int right)
  {
    while (left < right)
    {
      swap(&nums[left], &nums[right]);
      left++, right--;
    }
  }

  void rotate(vector<int> &nums, int k)
  {
    // int size = nums.size();

    // // Reversing the array to take the first k elements in the front
    // reverseArray(nums, 0, size-1);

    // // Reversing the first k elements for ordering the rotated elements
    // reverseArray(nums, 0, k-1);

    // // Reversing the last n-k elements
    // reverseArray(nums, k, size-1);

    int num_elements = nums.size(); // Get the number of elements in the vector
    k %= num_elements;              // Ensure k is within the bounds of the vector's size

    // Reverse the entire vector
    reverse(nums.begin(), nums.end()); // This puts the last k elements in front

    // Reverse the first k elements to restore their original order
    reverse(nums.begin(), nums.begin() + k);

    // Reverse the remaining elements to restore their original order
    reverse(nums.begin() + k, nums.end());
  }
};