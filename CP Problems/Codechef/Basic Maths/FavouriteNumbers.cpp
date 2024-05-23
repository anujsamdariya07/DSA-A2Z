#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int alice, bob, charlie;
        int a;
        cin >> a;
        if (a % 14 == 0)
        {
            cout << "Alice" << endl;
        }
        else if (a % 2 != 0 && a % 9 == 0)
        {
            cout << "Bob" << endl;
        }
        else
        {
            cout << "Charlie" << endl;
        }
    }
}
