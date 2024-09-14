#include <bits/stdc++.h>

using namespace std;

class Heap
{
public:
  int *arr;
  int capacity;
  int size;

  Heap(int capacity)
  {
    this->arr = new int[capacity];
    this->capacity = capacity;
    this->size = 0;
  }

  void insertNode(int val)
  {
    if (size == capacity)
    {
      // Overflow
      cout << "Heap Overflow!" << endl;
      return;
    }
    
    size++;

    int index = size;
    arr[index] = val;

    while (index > 1)
    {
      // Find out parent index
      int parentIndex = index / 2;
      // Compare the value of child root with its parent root
      if (arr[index] > arr[parentIndex])
      {
        // Child root > parent root
        swap(arr[parentIndex], arr[index]);
        index = parentIndex;
      }
      else
      {
        // Parent root > child root
        break;
      }
    }
  }

  int deleteNode()
  {
    int ans = arr[1];

    // Replacement
    arr[1] = arr[size];

    // Delete last element
    size--;

    // Heapification
    int index = 1;
    // Here we are not giving the condition as index <= size as when 
    // index  = size, this means that we are at the rightmost element
    //  of the heap which means that there is no need to heapify it
    while (index < size)
    {
      // Take out children
      int leftIndex = 2*index;
      int rightIndex = 2*index+1;

      // Find out the greatest element
      int largestIndex = index;

      // Left child
      if (leftIndex <= size && arr[leftIndex] > arr[largestIndex])
      {
        largestIndex = leftIndex;
      }

      // Right child
      if (rightIndex <= size && arr[rightIndex] > arr[largestIndex])
      {
        largestIndex = rightIndex;
      }
      
      if (index == largestIndex)
      {
        break;
      } else {
        swap(arr[largestIndex], arr[index]);
        index = largestIndex;
      }
    }

    return ans;
  }

  void printHeap()
  {
    cout << "Printing the content of heap:" << endl;
    for (int i = 1; i <= size; i++)
    {
      cout << arr[i] << " ";
    } cout << endl;
  }
};

void heapify(int *arr, int size, int index)
{
  int leftIndex = 2*index;
  int rightIndex = 2*index+1;
  int largestIndex = index;

  if (leftIndex <= size && arr[leftIndex] > arr[largestIndex])
  {
    largestIndex = leftIndex;
  }
  if (rightIndex <= size && arr[rightIndex] > arr[largestIndex])
  {
    largestIndex = rightIndex;
  }
  if (largestIndex != index)
  {
    swap(arr[largestIndex], arr[index]);
    index = largestIndex;
    heapify(arr, size, index);
  }
}

void buildHeap(int arr[], int size)
{
  for (int i = size/2; i >= 1; i--)
  {
    heapify(arr, size, i);
  }
}

void heapSort(int arr[], int size)
{
  while (size != 1)
  {
    // Dont use size-1 as we are using 1 based indexing
    swap(arr[1], arr[size]);
    size--;
    heapify(arr, size, 1);
  }
}

int main()
{
  // Heap h(20);
  // h.insertNode(10);
  // h.insertNode(20);
  // h.insertNode(5);
  // h.insertNode(11);
  // h.insertNode(6);
  // h.printHeap();
  // h.deleteNode();
  // h.printHeap();


  int arr[] = {-1, 25, 20, 15, 5, 10, 12};
  int size = sizeof(arr)/sizeof(int)-1;

  buildHeap(arr, size);

  cout << "Printing array:\n";
  for (int i = 1; i <= size; i++)
  {
    cout << arr[i] << " ";
  } cout << endl;

  heapSort(arr, size);

  cout << "Printing array:\n";
  for (int i = 1; i <= size; i++)
  {
    cout << arr[i] << " ";
  } cout << endl;
}