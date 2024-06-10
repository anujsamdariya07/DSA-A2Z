#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j])
    {
      swap(arr[j-1], arr[j]);
      j--;
    }
  }
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  int arr[] = {13, 46, 24, 52, 20, 9};
  int size = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, size);
  insertionSort(arr, size);
  printArray(arr, size);
}