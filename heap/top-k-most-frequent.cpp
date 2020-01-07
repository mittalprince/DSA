#include <bits/stdc++.h>
using namespace std;

#define ppi pair<int, int>

class mycompare
{
public:
    bool operator()(ppi a, ppi b)
    {
        if (a.second == b.second)
        {
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, temp;
        cin >> n >> k;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            m[temp]++;
            priority_queue<ppi, vector<ppi>, mycompare> pq(m.begin(), m.end());
            // for(auto it: m){
            //     pq.push(make_pair(it.first, it.second));
            // }
            int ct = 0;
            while (!pq.empty() && ct < k)
            {
                cout << pq.top().first << " ";
                pq.pop();
                ct++;
            }
        }

        cout << endl;
    }
}