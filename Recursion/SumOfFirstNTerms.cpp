#include <bits/stdc++.h>

using namespace std;

long long sumOfSeries(long long n)
{
    // code here
    if (n == 1)
        return 1;
    return n * n * n + sumOfSeries(n - 1);
}