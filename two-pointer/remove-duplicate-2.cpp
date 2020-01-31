int Solution::removeDuplicates(vector<int> &A)
{
    int n = A.size();
    if (!n)
    {
        return 0;
    }
    for (int i = 0; i < A.size() - 1; i++)
    {
        int j = 1;
        while (A[i] == A[i + 1] && i < A.size() - 1)
        {
            j++;
            i++;
        }

        // cout<<i<<" "<<j<<endl;
        if (j > 2)
        {
            A.erase(A.begin() + i - j + 2, A.begin() + i);
            i = i - j + 2;
        }
    }

    return A.size();

    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
