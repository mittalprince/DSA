vector<int> Solution::dNums(vector<int> &A, int B)
{

    int n = A.size();
    unordered_map<int, int> m;

    int ct = 0;
    vector<int> res;

    for (int i = 0; i < B; i++)
    {
        if (m[A[i]] == 0)
        {
            ct++;
        }
        m[A[i]]++;
    }

    res.push_back(ct);

    for (int i = B; i < n; i++)
    {
        if (m[A[i - B]] == 1)
        {
            ct--;
        }
        m[A[i - B]]--;
        if (m[A[i]] == 0)
        {
            ct++;
        }
        m[A[i]]++;
        res.push_back(ct);
    }

    return res;
}
