#include <bits/stdc++.h>

using namespace std;

// Using eucledian algorithm
long long findHcf(long long a, long long b)
{
    if (a == 0)
        return b;
    int max = a > b ? a : b;
    int min = a < b ? a : b;
    findHcf(max - min, min);
}
long long findLcm(long long a, long long b)
{
    return b * (a / findHcf(a, b));
}
vector<long long> lcmAndGcd(long long a, long long b)
{
    // code here
    vector<long long> ans;
    ans.push_back(findLcm(a, b));
    ans.push_back(findHcf(a, b));
    return ans;
}