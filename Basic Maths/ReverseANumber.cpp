#include<bits/stdc++.h>

using namespace std;

int reverse(int x)
{
    long long int ans = 0;
    while (x)
    {
        // For long long int input
        if (ans < INT_MIN / 10 || ans > INT_MAX / 10)
        {
            return 0;
        }
        int digit = x % 10;
        ans = ans * 10 + digit;
        x /= 10;
    }
    return ans;
}