#include <bits/stdc++.h>

using namespace std;

void print(int arr[], int size)
{
    cout << "Array is as follows: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverseArray(int arr[], int size, int left, int right) 
{
    if (left > right)
    {
        return;
    }
    swap(arr[left], arr[right]);
    left++, right--;
    reverseArray(arr, size, left, right);
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int left = 0, right = size - 1;
    print(arr, size);
    reverseArray(arr, size, left, right);
    print(arr, size);
}