#include <bits/stdc++.h>

using namespace std;

int countEvenlyDividingDigits(int N)
{
    int count = 0;
    int temp = N;
    while (temp)
    {
        int digit = temp % 10;
        // First check whether digit is not 0 because it will cause a floating exception
        if (digit != 0)
        {
            if (N % digit == 0)
            {
                count++;
            }
        }
        temp /= 10;
    }
    return count;
}