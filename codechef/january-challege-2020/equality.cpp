#include<iostream>
#include<climits>
using namespace std;
typedef long long ll;
#define ppi pair< pair<int, int>, int>

int main(){
    int n,q;
    cin>>n>>q;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    ppi one = make_pair(make_pair(INT_MIN, INT_MIN), 0);
    ppi two = make_pair(make_pair(INT_MIN, INT_MIN), 0);

    while(q--){
        int l,r;
        cin>>l>>r;

        int len=1;
        int max_sub = 0;
        int temp; 
        l--; r--;
        bool pre_cal__max = false;

        if(one.first.first <= l && one.first.second >= r){
            if(one.second == 1){
                max_sub = 1;
                pre_cal__max = true;
            }
        }

        if(!pre_cal__max){
            temp = arr[l];
            for (int i = l + 1; i <= r; i++)
            {
                // cout<<temp<<" "<<arr[i]<<" "<<len<<endl;
                if (arr[i] > temp)
                {
                    len++;
                }
                else
                {
                    if (len > 1)
                    {
                        max_sub++;
                    }
                    len = 1;
                }
                temp = arr[i];
            }

            if (len > 1)
            {
                max_sub++;
            }

            if(max_sub == 1){
                if (one.first.first > l && one.first.second < r){
                    one.first.first = max(one.first.first, l);
                    one.first.second = max(one.first.second, r);
                }
                one.second = 1;
            }
        }

        int min_sub = 0;
        temp = arr[r];
        len = 1;

        bool pre_cal__min = false;

        if (one.first.first <= l && one.first.second >= r)
        {
            if (one.second == 1)
            {
                min_sub = 1;
                pre_cal__min = true;
            }
        }

        if(!pre_cal__min){
            for (int i = r - 1; i >= l; i--)
            {
                // cout<<temp<<" "<<arr[i]<<" "<<len<<endl;
                if (arr[i] > temp)
                {
                    len++;
                }
                else
                {
                    if (len > 1)
                    {
                        min_sub++;
                    }
                    len = 1;
                }
                temp = arr[i];
            }

            if (len > 1)
            {
                min_sub++;
            }

            if (max_sub == 1)
            {
                if (one.first.first > l && one.first.second < r)
                {
                    one.first.first = max(one.first.first, l);
                    one.first.second = max(one.first.second, r);
                }
                one.second = 1;
            }
        }

        // cout<<max_sub<<" "<<min_sub<<endl;
        if(max_sub == min_sub){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}