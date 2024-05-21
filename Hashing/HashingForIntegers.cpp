#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int size)
{
    cout << "Array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void hashingForIntegers(int arr[], int size)
{
    int maxNum = arr[0];
    for (int i = 0; i < size; i++)
    {
        maxNum = max(arr[i], maxNum);
    }

    // Initiate the hash array with size one more than the maximum number of the given array
    int *hash = new int[maxNum + 1]{0};
    // You acnnot declare an integer array of size more than 10^6 inside main, outside main, you can declare array of size max 10^7
    // You cannot declare an boolean array of size more than 10^7
    for (int i = 0; i < size; i++)
    {
        hash[arr[i]] += 1;
    }
    printArray(hash, size + 1);
}

int main()
{
    int arr[] = {1, 2, 3, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);
    hashingForIntegers(arr, size);
}