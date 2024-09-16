#include <bits/stdc++.h>

using namespace std;

int main()
{
  // Max heap
  priority_queue<int> pq;

  pq.push(10);
  pq.push(20);
  pq.push(30);
  pq.push(40);
  pq.push(50);

  cout << "Top element of heap: " << pq.top() << endl;

  pq.pop();
  
  cout << "Top element of heap: " << pq.top() << endl;

  if (pq.empty())
  {
    cout << "Empty" << endl;
  } else {
    cout << "Not Empty" << endl;
  }

  // Min heap
  priority_queue<int, vector<int>, greater<int>> pq2;

  pq2.push(100);
  pq2.push(90);
  pq2.push(80);
  pq2.push(70);

  cout << "Top element of min heap: " << pq2.top() << endl;

  pq2.pop();
  
  cout << "Top element of min heap: " << pq2.top() << endl;
}