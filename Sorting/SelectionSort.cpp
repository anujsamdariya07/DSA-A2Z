#include <bits/stdc++.h>

using namespace std;

void selectionSort(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    int minIndex = i;
    for (int j = i; j < size; j++) 
    {
      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
      }
    }
    swap(arr[i], arr[minIndex]);
  }
}

void printArray (int arr[], int size) 
{
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  } cout << endl;
}

int main()
{
  int arr[] = {13, 46, 24, 52, 20, 9};
  int size = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, size);
  selectionSort(arr, size);
  printArray(arr, size);
}