// Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a mapped value. No two mapped values can have the same key values.

// Syntax: map<key_object_type, value_object_type> variable_name;

#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Create a map of strings to integers
    map<string, int> mp;

    // Insert some values into the map
    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;

    // Get an iterator pointing to the first element in the
    // map
    map<string, int>::iterator it = mp.begin();

    // Iterate through the map and print the elements
    while (it != mp.end())
    {
        cout << "Key: " << it->first
             << ", Value: " << it->second << endl;
        ++it;
    }

    // Create a map of strings to integers
    map<string, int> map;

    // Insert some values into the map
    map["one"] = 1;
    map["two"] = 2;
    map["three"] = 3;

    // Print the size of the map
    cout << "Size of map: " << map.size() << endl;
}