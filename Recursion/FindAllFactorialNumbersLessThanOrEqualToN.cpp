// Confusing
#include <bits/stdc++.h>

using namespace std;

void pushFactorials(long long n, vector<long long> &v, long long fact, long long i)
{
    i++;
    if (fact > n)
        return;
    v.push_back(fact);
    pushFactorials(n, v, fact * i, i);
}
vector<long long> factorialNumbers(long long n)
{
    // Write Your Code here
    vector<long long> v;
    long long fact = 1;
    long long i = 1;
    pushFactorials(n, v, fact, i);
    return v;
}