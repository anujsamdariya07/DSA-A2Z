#include<bits/stdc++.h>

using namespace std;

void kthSmallestElementInAnArray(int arr[], int size, int k)
{
  // Create a max heap
  priority_queue<int> pq;

  // Insert first k elements to it.
  int temp = k, i = 0;
  while(temp--)
  {
    pq.push(arr[i]);
    i++;
  }

  // Push next elements of the array only if they are smaller than the top element
  while (i < size)
  {
    if (arr[i] < pq.top())
    {
      pq.pop();
      pq.push(arr[i]);
    }
    i++;
  }

  // We now have k smallest numbers of the array and the top element is 
  // the kth smallest no. of the given array
  cout << pq.top() << endl;
}

void kthGreatestElementInAnArray(int arr[], int size, int k)
{
  // Create a min heap
  priority_queue<int, vector<int>, greater<int>> pq;

  // Insert first k elements to it.
  int temp = k, i = 0;
  while(temp--)
  {
    pq.push(arr[i]);
    i++;
  }

  // Push next elements of the array only if they are smaller than the top element
  while (i < size)
  {
    if (arr[i] > pq.top())
    {
      pq.pop();
      pq.push(arr[i]);
    }
    i++;
  }

  // We now have k greatest numbers of the array and the top element is 
  // the kth largest no. of the given array
  cout << pq.top() << endl;
}

int main()
{
  int arr[] = {3, 7, 4, 5, 8, 6, 9};
  int size = sizeof(arr)/sizeof(arr[0]);
  int k = 5;
  kthSmallestElementInAnArray(arr, size, k);
  kthGreatestElementInAnArray(arr, size, k);
}