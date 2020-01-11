class Solution
{
public:
    int kthSmallest(vector<vector<int>> &M, int k)
    {
        int n = M.size();
        priority_queue<int> pq;

        int i = 0, j = 0;
        for (int l = 0; l < k; l++)
        {
            pq.push(M[i][j]);
            j++;
            if (j == n)
            {
                j = 0;
                i++;
            }
        }
        // cout<<pq.top();

        while (i < n)
        {
            if (M[i][j] < pq.top())
            {
                pq.pop();
                pq.push(M[i][j]);
            }

            j++;
            if (j == n)
            {
                j = 0;
                i++;
            }
        }
        //         for(int I=i;I<n; I++){
        //             for(int J=0;J<n; J++){
        //                 // cout<<i<<j<<endl;
        //                 // cout<<pq.top()<<" "<<M[I][J]<<endl;
        //                 if(M[I][J] < pq.top()){
        //                     cout<<pq.top()<<"P ";
        //                     pq.pop();
        //                     pq.push(M[I][J]);
        //                 }
        //             }
        //         }

        return pq.top();
    }
};