#include <bits/stdc++.h>
using namespace std;

int main()
{
	// your code goes here
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] *= 10;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}
}
