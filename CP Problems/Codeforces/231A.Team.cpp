#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;

  int mainCounter = 0;

  while (n--) 
  {
    int counter = 0;
    int a, b, c;
    cin >> a >> b >> c;

    if (a == 1) counter++;
    if (b == 1) counter++;
    if (c == 1) counter++;

    if (counter >= 2) mainCounter++;
  }

  cout << mainCounter;
}