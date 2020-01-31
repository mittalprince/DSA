int Solution::removeDuplicates(vector<int> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    vector<int> ans = A;
    A.clear();
    A.push_back(ans[0]);
    for (int i = 1; i < n; i++)
    {
        while (ans[i] == ans[i - 1])
        {
            i++;
        }
        if (i < n)
        {
            A.push_back(ans[i]);
        }
    }

    return A.size();
    // return m.size();
}
