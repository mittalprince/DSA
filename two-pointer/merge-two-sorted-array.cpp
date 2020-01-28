void Solution::merge(vector<int> &A, vector<int> &B)
{
    int n1 = A.size();
    int n2 = B.size();

    int i = 0, j = 0;

    while (i < n1 && j < n2)
    {
        if (A[i] > B[j])
        {
            A.insert(A.begin() + i, B[j]);
            j++;
            n1++;
        }
        i++;
    }

    if (j < n2)
    {
        A.insert(A.end(), (B.begin() + j), B.end());
    }

    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}