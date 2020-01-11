class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &v, int k)
    {
        //         multiset<int> pq;

        //         int n = v.size();
        //         vector<int> ans;

        //         if(n == 0){
        //             return ans;
        //         }

        //         for(int i=0; i<k; i++){
        //             pq.insert(v[i]);
        //         }

        //         ans.push_back(*(pq.rbegin()));

        //         for(int i=k; i<n; i++){
        //             auto it = pq.find(v[i-k]);
        //             if(it != pq.end()){
        //                 pq.erase(it);
        //             }
        //             pq.insert(v[i]);
        //             ans.push_back((*(pq.rbegin())));
        //         }
        //         return ans;

        int n = v.size();
        vector<int> ans;

        if (n == 0)
        {
            return ans;
        }

        int mx = INT_MIN;
        int mx_idx = 0;

        for (int i = 0; i < k; i++)
        {
            if (v[i] >= mx)
            {
                mx = v[i];
                mx_idx = i;
            }
        }

        ans.push_back(mx);

        for (int i = k; i < n; i++)
        {

            if (mx <= v[i])
            {
                mx = v[i];
                mx_idx = i;
                ans.push_back(v[i]);
            }
            else if (mx_idx != i - k)
            {
                ans.push_back(mx);
            }
            else
            {
                mx = INT_MIN;
                for (int s = i - k + 1; s <= i; s++)
                {
                    if (v[s] >= mx)
                    {
                        mx = v[s];
                        mx_idx = s;
                    }
                }

                ans.push_back(mx);
            }
        }

        return ans;
    }
};