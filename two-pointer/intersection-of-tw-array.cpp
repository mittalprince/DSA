vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B)
{
    int a = A.size();
    int b = B.size();

    vector<int> ans;
    int i = 0, j = 0;
    while (i < a && j < b)
    {
        if (A[i] == B[j])
        {
            ans.push_back(A[i]);
            i++;
            j++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return ans;
}
