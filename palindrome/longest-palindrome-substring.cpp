#include <iostream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

/*
We observe that a palindrome mirrors around its center. 
Therefore, a palindrome can be expanded from its center, 
and there are only 2n - 12n−1 such centers.

You might be asking why there are 2n - 12n−1 but not nn centers? 
The reason is the center of a palindrome can be in between two letters. 
Such palindromes have even number of letters (such as "abba") and 
its center are between the two 'b's.
*/
int expandAroundCenter(string s, int left, int right)
{
    if (s.length() == 0 || left > right)
        return 0;

    while (left >= 0 && right < s.length() && s[left] == s[right])
    {
        left--;
        right++;
    }
    return right - left - 1;
}

string longestPalindrome(string s)
{
    int n = s.length();
    if (n <= 1)
        return s;
    int start = 0, end = 0, maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = max(len1, len2);
        if (len > maxLength)
        {
            maxLength = len;
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, end - start + 1);
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (t--)
    {
        string s;
        cin >> s;
        string ans = longestPalindrome(s);
        cout << ans << endl;
    }
    return 0;
}