// TC for storing and fetching in a map is O(logN) for all the cases
// TC for storing and fetching in an unordered map is O(1) for average and best cases and O(logN) for the worst case.
// So we generally use unordered map for hashing

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
    map<int, int> mp;
    for (int i = 0; i < size; i++)
    {
        mp[arr[i]]++;
    }
    cout << "The hashed array will be: ";
    for (auto it: mp) 
    {
        cout << it.first << "->" << it.second << " ";
    } cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);
    hashingForIntegers(arr, size);
}