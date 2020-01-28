#include<iostream>
#include<unordered_map>
#include<climits>
using namespace  std;
#define M 256

int main(){
    int t;
    cin>>t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(t--){
        string A, B;
        getline(cin, A);
        getline(cin, B);

        int len1 = A.length();
        int len2 = B.length();

        if (len1 < len2)
        {
            cout << "No string\n";
        }
        else
        {
            int ct = 0;
            int start = 0, idx = -1, min_len = INT_MAX;
            int pat[M] ={0}, str[M]={0};
            for (int i=0; i<len2; i++)
            {
                pat[B[i]]++;
            }

            for (int i = 0; i < len1; i++)
            {
                str[A[i]]++;

                if (pat[A[i]] != 0 && str[A[i]] <= pat[A[i]])
                {
                    ct++;
                }

                if (ct == len2)
                {
                    while (str[A[start]] > pat[A[start]] || pat[A[start]] == 0)
                    {

                        if (str[A[start]] > pat[A[start]])
                            str[A[start]]--;
                        start++;
                    }
                    int len = i - start + 1;
                    if (min_len > len)
                    {
                        min_len = len;
                        idx = start;
                    }
                }
            }

            if (idx != -1)
            {
                for (int i = idx; i < idx + min_len; i++)
                {
                    cout << A[i];
                }
            }
            else
            {
                cout << "No string";
            }
            cout << endl;
        }
    }
}