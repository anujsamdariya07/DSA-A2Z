#include <bits/stdc++.h>
using namespace std;

int main()
{
	// your code goes here
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		int totalAmount = 0;
		if (x < y)
		{
			totalAmount += x * 1 + (y - x) * 2;
		}
		else
		{
			totalAmount += y * 1;
		}
		cout << totalAmount << endl;
	}
}
