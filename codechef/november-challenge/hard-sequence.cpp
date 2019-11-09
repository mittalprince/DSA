#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        arr[0] = 0;

        unordered_map<int, int> freq, last_index;

        freq[0] = 1;
        last_index[0] = 0;
        for (int i = 1; i < n; i++)
        {
            // freq[arr[i-1]]++;
            if (freq[arr[i - 1]] == 1)
            {
                arr[i] = 0;
                freq[0]++;
            }
            // else if(freq[arr[i-1]] == 2){
            //     arr[i] = i-1-last_index[arr[i-1]];
            //     frq[arr[i]]++;
            //     last_index[arr[i]] = i;
            //     last_index[arr[i-1]] = i-1;
            // }
            else
            {
                arr[i] = i - 1 - last_index[arr[i - 1]];
                freq[arr[i]]++;
                if (freq[arr[i]] == 1)
                {
                    last_index[arr[i]] = i;
                }

                last_index[arr[i - 1]] = i - 1;
            }
        }

        // for(auto i: freq){
        //     cout<<i.first<<" -> "<<i.second<<endl;
        // }
        // cout<<endl;
        // for(auto i: last_index){
        //     cout<<i.first<<" -> "<<i.second<<endl;
        // }

        // for(auto i: arr){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        cout << freq[arr[n - 1]] << endl;
    }
}