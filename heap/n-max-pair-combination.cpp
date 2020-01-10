#define ppi pair<int, pair<int, int>>

vector<int> Solution::solve(vector<int> &a, vector<int> &b)
{

    int i, j, sum;

    int n = a.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    sum = a[n - 1] + b[n - 1];
    priority_queue<ppi> pq;
    map<pair<int, int>, bool> m;

    pair<int, int> idx_pr = make_pair(n - 1, n - 1);
    ppi temp = make_pair(sum, idx_pr);

    pq.push(temp);
    m[idx_pr] = true;

    vector<int> ans;
    for (int k = 0; k < n; k++)
    {
        temp = pq.top();
        pq.pop();

        ans.push_back(temp.first);
        i = temp.second.first;
        j = temp.second.second;

        sum = a[i - 1] + b[j];

        idx_pr = make_pair(i - 1, j);
        if (m.find(idx_pr) == m.end())
        {
            m[idx_pr] = true;
            temp = make_pair(sum, idx_pr);
            pq.push(temp);
        }
        sum = a[i] + b[j - 1];

        idx_pr = make_pair(i, j - 1);
        if (m.find(idx_pr) == m.end())
        {
            m[idx_pr] = true;
            temp = make_pair(sum, idx_pr);
            pq.push(temp);
        }
    }

    return ans;
}
