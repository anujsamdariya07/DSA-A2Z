#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node()
  {
    this->data = 0;
    this->next = NULL;
  }

  Node(int val)
  {
    this->data = val;
    this->next = NULL;
  }
};

class Info
{
public:
  int data;
  int rowIndex;
  int columnIndex;

  Info(int data, int rowIndex, int columnIndex)
  {
    this->data = data;
    this->rowIndex = rowIndex;
    this->columnIndex = columnIndex;
  }
};



class compare
{
public:
  bool operator()(Info *a, Info *b)
  {
    return a->data > b->data;
  }
};

class compare
{
public:
  bool operator()(Node *a, Node *b)
  {
    return a->data > b->data;
  }
};

void mergeKSortedArrays(int arr[][4], int size, int k, vector<int> &ans)
{
  priority_queue<Info *, vector<Info *>, compare> pq;

  // Process first k elements
  for (int row = 0; row < k; row++)
  {
    int element = arr[row][0];
    Info *temp = new Info(element, row, 0);
    pq.push(temp);
  }

  while (!pq.empty())
  {
    Info *temp = pq.top();
    pq.pop();

    int topData = temp->data;
    int topDataRow = temp->rowIndex;
    int topDataColumn = temp->columnIndex;

    // Store in ans
    ans.push_back(topData);

    // Next Element for the same from where we popped the top
    if (topDataColumn + 1 < size)
    {
      // There are more elements present in the row
      Info *newInfo = new Info(arr[topDataRow][topDataColumn + 1], topDataRow, topDataColumn + 1);
      pq.push(newInfo);
    }
  }
}

Node *mergeKLists(vector<Node *> &lists)
{
  priority_queue<Node *, vector<Node *>, compare> pq;

  // Inserting the head of all the linked lists
  for (int i = 0; i < lists.size(); i++)
  {
    Node *element = lists[i];
    if (element != NULL)
      pq.push(element);
  }

  // Make tail and head for ans list to be returned
  Node *head = NULL;
  Node *tail = NULL;

  while (!pq.empty())
  {
    Node *topRoot = pq.top();
    pq.pop();

    // Check for null list
    if (head == NULL)
    {
      // NULL list
      head = topRoot;
      tail = topRoot;

      // Check whether list is completed or not
      if (tail->next != NULL)
      {
        // List is not completed
        pq.push(tail->next);
      }
    }
    else
    {
      // Non-null list
      // Insert at end
      tail->next = topRoot;
      tail = topRoot;

      // Check whether list is completed or not
      if (tail->next != NULL)
      {
        // List is not completed
        pq.push(tail->next);
      }
    }
  }

  return head;
}

vector<int> smallestRange(vector<vector<int>> &nums)
{
  priority_queue<Info *, vector<Info *>, compare> pq;

  int maxVal = INT_MIN;
  int minVal = INT_MAX;

  // Insert first k elements
  for (int i = 0; i < nums.size(); i++)
  {
    int element = nums[i][0];
    int row = i;
    int column = 0;
    Info *temp = new Info(element, row, column);
    pq.push(temp);
    maxVal = max(maxVal, element);
    minVal = min(minVal, element);
  }

  int ansStart = minVal;
  int ansEnd = maxVal;

  while (!pq.empty())
  {
    Info *topNode = pq.top();
    pq.pop();

    int topData = topNode->data;
    int topRow = topNode->rowIndex;
    int topColumn = topNode->columnIndex;

    minVal = topData;

    // Compare
    if ((ansEnd - ansStart) > (maxVal - minVal))
    {
      // Update ans
      ansStart = minVal;
      ansEnd = maxVal;
    }

    // Insert
    if (topColumn + 1 < nums[topRow].size())
    {
      int newElement = nums[topRow][topColumn + 1];
      maxVal = max(maxVal, newElement);

      Info *newInfo = new Info(newElement, topRow,
                               topColumn + 1);
      pq.push(newInfo);
    }
    else
    {
      // No element after popping top
      break;
    }
  }

  vector<int> ans;
  ans.push_back(ansStart);
  ans.push_back(ansEnd);
  return ans;
}


int main()
{
  int arr[3][4] = {
      {1, 4, 8, 11},
      {2, 3, 6, 10},
      {5, 7, 12, 14}};
  int size = 4;
  int k = 3;

  vector<int> ans;
  mergeKSortedArrays(arr, size, k, ans);

  cout << "Printing answer array:\n| ";
  for (auto num : ans)
  {
    cout << num << " | ";
  }
  cout << endl;
}