#include<bits/stdc++.h>

using namespace std;

int main()
{
  int w;
  cin >> w;

  if (w & 1) {
    cout << "NO";
    return 0;
  } else if (w == 2) {
    cout << "NO";
    return 0;
  } else {
    cout << "YES";
  }
}