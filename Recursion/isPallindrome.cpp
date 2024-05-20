#include <bits/stdc++.h>

using namespace std;

void reverseString(string &s, int left, int right) 
{
    if (left > right) return;
    swap(s[left], s[right]);
    left++, right--;
    reverseString(s, left, right);
}

void shiftLeft (string &str, int i)
{
    if (i >= str.length() - 1) {
        return;
    }
    str[i] = str[i+1];
    shiftLeft(str, i+1);
}

void modifyString(string &str, int i) 
{
    if (i > str.length()) return;
    if (str[i] <= 90 && str[i] >= 65)
    {
        str[i] = str[i] - 'A' + 97;
    }
    if ((str[i] == ' ') || (str[i] >= 32 && str[i] <= 47) || (str[i] >= 58 && str[i] <= 64) || (str[i] >= 91 && str[i] <= 96) || (str[i] >= 123 && str[i] <= 126)) 
    {
        shiftLeft(str, i);
        // When shifting left last element will be repeated one so poping it.
        str.pop_back();
    } else {
        i++;
    }
    modifyString(str, i);
}

bool isPallindrome(string str)
{
    modifyString(str, 0);
    int left = 0;
    int right = str.length() - 1;
    string temp = str;
    cout << temp << endl;
    reverseString(temp, left, right);
    cout << str << endl << temp << endl;
    return (str == temp);
}

int main()
{
    string str = "A man, a plan, a canal: Panama";
    cout << str << endl;
    cout << isPallindrome(str) << endl;
}