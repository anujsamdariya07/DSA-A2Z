#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        int totalMoney = x*5 + y*10;
        if (totalMoney < z) {
            cout << 0 << endl;
            break;
        }
        else if (totalMoney == z) {
            cout << 1 << endl;
            break;
        } else {
            cout << totalMoney/z << endl;
        }
    }
}
