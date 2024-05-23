#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = ((a > b && a < c) || (a > c && a < b)) ? a : (((b > a && b < c) || (b > c && b < a)) ? b : c);
        cout << ans << endl;
    }
}
