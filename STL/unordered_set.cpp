// An unordered set in STL is a container that stores unique elements in no particular order. Every operation on an unordered set takes O(1) complexity in the average case and takes O(n) in the worst case.

// Syntax: unordered_set<object_type> variable_name;

#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_set<int> s;

    for (int i = 1; i <= 10; i++)
    {
        s.insert(i);
    }
    cout << "Elements present in unordered set are:";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "The size of the unordered set is: " << s.size() << endl;

    if (s.empty() == false)
        cout << "The unordered set is not empty " << endl;
    else
        cout << "The unordered set is empty" << endl;
    s.clear();
    cout << "Size of the unordered set after clearing all the elements: " << s.size() << endl;
}