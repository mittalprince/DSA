auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class compare
{
public:
    bool operator()(pair<int, string> a, pair<int, string> b)
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> m;
        for (string s : words)
        {
            m[s]++;
        }
        vector<string> ans;

        auto it = m.begin();
        priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
        int ct = k;
        while (k--)
        {
            // cout<<it->first<<" "<<it->second<<endl;
            pq.push(make_pair(it->second, it->first));
            it++;
        }

        for (; it != m.end(); it++)
        {
            pair<int, string> top = pq.top();
            cout << it->first << " " << it->second << " " << top.first << " " << top.second << endl;
            if (top.first < it->second)
            {
                pq.pop();
                pq.push(make_pair(it->second, it->first));
            }
            else if (top.first == it->second)
            {
                if (top.second > it->first)
                {
                    pq.pop();
                    pq.push(make_pair(it->second, it->first));
                }
            }
        }

        while (!pq.empty())
        {
            pair<int, string> top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }

        reverse(ans.begin(), ans.end());

        //         // for(auto it: m){
        //         //     cout<<it.first<<" "<<it.second<<endl;
        //         // }
        //         // vector<pair<int, string>> v;
        //         // for(auto it: m){
        //         //     v.push_back(make_pair(it.second, it.first));
        //         }

        //         sort(v.begin(), v.end(), compare);
        //         vector<string> ans;
        //         for(int i=0; i<k; i++){
        //             ans.push_back(v[i].second);
        //         }
        return ans;
    }
};