int Solution::nchoc(int A, vector<int> &B)
{
    long long mod = 1000000007;

    priority_queue<int> pq;

    for (int i = 0; i < B.size(); i++)
    {
        pq.push(B[i]);
    }

    int ct = A;
    long long ans = 0;
    while (!pq.empty() && ct--)
    {
        int temp = pq.top();
        ans += temp;
        pq.pop();
        pq.push((temp >> 1));
    }

    ans = ans % mod;

    return ans;
}