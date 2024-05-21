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

void hashingForCharacters(string str, int size)
{
    // For both uppercase and lowercase take 256 inplace of 26
    int hash[26]{0};
    for (int i = 0; i < size; i++)
    {
        hash[str[i] - 'a'] += 1;
    }
    printArray(hash, 26);
}

int main()
{
    string str = "abcdabehdfz";
    hashingForCharacters(str, str.length());
}