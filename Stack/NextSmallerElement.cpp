// Array = [2 | 1 | 4 | 6 | 3]
// Smaller element towards right if not then -1
// Ans = [1 | -1 | 3 | 3 | -1]

// Brute force: Compare every element with its previous one and stop only if smaller element found, if not found then keep iterating and return -1 if smaller element not found and array is complete
// Time Complexity: O(n^2)

// Optimal Approach: We know that the last element will always give -1 as it does not have any element to its right. So we will push -1 to a stack. Then we will compare the last element to the top of stack, if the element is greater than the stack, then we will push that element as this element can be the answer for the elements to the left of it and if it is lesser than top then we will pop the top element and the again compare and repeat the same process for the entire array

#include <bits/stdc++.h>

using namespace std;

vector<int> nextSmallerElement(vector<int> nums)
{
  int size = nums.size();

  vector<int> ans(size);
  stack<int> s;

  // For last element
  s.push(-1);

  for (int i = size-1; i >= 0; i--) 
  {
    int num = nums[i];

    while (s.top() >= num)
    {
      s.pop();
    }

    ans[i] = s.top();
    s.push(num);
  }

  return ans;
}

vector<int> previousSmallerElement(vector<int> nums)
{
  int size = nums.size();

  vector<int> ans(size);
  stack<int> s;

  // For last element
  s.push(-1);

  for (int i = 0; i < size; i++) 
  {
    int num = nums[i];

    while (s.top() >= num)
    {
      s.pop();
    }

    ans[i] = s.top();
    s.push(num);
  }

  return ans;
}

int main()
{
  vector<int> nums = {8, 4, 6, 2, 3};
  vector<int> ans = nextSmallerElement(nums);
  for(auto num: ans) 
  {
    cout << num << " ";
  } cout << endl;
  ans = previousSmallerElement(nums);
  for(auto num: ans) 
  {
    cout << num << " ";
  } cout << endl;
}