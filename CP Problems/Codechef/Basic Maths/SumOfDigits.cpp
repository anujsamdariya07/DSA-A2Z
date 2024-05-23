#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int sum = 0;
        while (x)
        {
            int digit = x % 10;
            sum += digit;
            x /= 10;
        }
        cout << sum << endl;
    }
}
