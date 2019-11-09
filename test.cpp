#include <bits/stdc++.h>
using namespace std;
#define max 32
#define M 100001

vector<int> Queries(vector<int> Index, vector<int> Bit, vector<int> Type, int N, int Q, int Type2)
{
    int prefix[M][max];

    // for(int i=0; i< max; i++){
    //     prefix[0][i] = 0;
    // }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < max; j++)
        {
            // if(i){
            prefix[i][j] = 0;
            // }
        }
    }

    vector<int> ans(N);
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        ans[i] = 0;
    }

    int i = 0;
    for (int i = 0; i < Q; i++)
    {
        if (Type[i] == 1)
        {
            int temp = ans[Index[i]] ^ (1 << (Bit[i]));
            ans[Index[i]] = temp;
            if (temp)
            {
                prefix[Index[i]][Bit[i]] = prefix[Index[i] - 1][Bit[i]] + 1;
            }
            else
            {
                prefix[Index[i]][Bit[i]] = prefix[Index[i] - 1][Bit[i]];
            }
        }
        else
        {
            int ct = 0;
            int mask = 1 << (Bit[i]);
            for (int j = 1; j < max; j++)
            {
                prefix[Index[i]][j] += prefix[Index[i]][j - 1];
            }
            cout << "ELSE *****" << prefix[Index[i]][Bit[i]] << endl;
            // cout<<mask<<"********"<<endl;
            for (int j = 1; j <= Index[i]; j++)
            {
                // cout<<"ANS "<<ans[j]<<" check mask "<<(mask & ans[j])<<endl;
                if (ans[j] & mask)
                {
                    ct++;
                }
            }
            v.push_back(ct);
        }

        // for(int i=0; i<N; i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j < max; j++)
            {
                cout << prefix[i][j] << " ";
            }
            cout << endl;
        }
        cout << "****************" << endl;
    }

    return v;
    // Write your code here
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, Q, Type2 = 0;
    cin >> N >> Q;
    vector<int> Type(Q), Index(Q), Bit(Q);
    for (int i_Type = 0; i_Type < Q; i_Type++)
    {
        cin >> Type[i_Type] >> Index[i_Type] >> Bit[i_Type];
        if (Type[i_Type] == 2)
            Type2++;
    }
    vector<int> out_;
    out_ = Queries(Index, Bit, Type, N, Q, Type2);
    for (int i_out_ = 0; i_out_ < out_.size(); i_out_++)
    {
        cout << out_[i_out_] << endl;
    }
}