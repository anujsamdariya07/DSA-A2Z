#include <bits/stdc++.h>

using namespace std;

int main()
{
  int matrix[5][5];
  int row1, col1;

  for (int i = 0; i < 5; ++i)
  {
    for (int j = 0; j < 5; ++j)
    {
      cin >> matrix[i][j];
      if (matrix[i][j] == 1)
      {
        row1 = i;
        col1 = j;
      }
    }
  }

  int moves = abs(row1 - 2) + abs(col1 - 2);
  cout << moves << endl;

  return 0;
}