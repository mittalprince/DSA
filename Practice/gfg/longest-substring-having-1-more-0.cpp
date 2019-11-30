#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

typedef long long ll;

int longestSubstring(string s)
{
    unsigned int n = s.length();
    unordered_map<int, int> prevTrack;

    int sum = 0, maxlen = 0, currlen;
    for (unsigned int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            sum++;
        }
        else
        {
            sum--;
        }

        if (sum > 0)
        {
            maxlen = i + 1;
        }
        else{
            if(prevTrack.find(sum-1) != prevTrack.end()){
                currlen = i - prevTrack[sum-1];
                maxlen = max(currlen, maxlen);
            }
        }
        if(prevTrack.find(sum) == prevTrack.end()){
            prevTrack[sum] = i;
        }
    }
    return maxlen;
}
int main()
{
    string s;
    cin >> s;
    cout<<longestSubstring(s)<<endl;
}

//https://www.geeksforgeeks.org/longest-substring-with-count-of-1s-more-than-0s/