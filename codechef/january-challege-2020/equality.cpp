#include<iostream>
#include<climits>
using namespace std;
#define Pair pair< pair<int, int>, int>

Pair one = make_pair(make_pair(INT_MIN, INT_MIN), 0);
Pair two = make_pair(make_pair(INT_MIN, INT_MIN), 0);

bool findQuery(int arr[], int l, int r){
    int length = 1;
    int mx = 0, mi=0;
    int temp;
    bool pcm = false, pcmi=false;

    if (one.first.first <= l && one.first.second >= r)
    {
        if (one.second == 1)
        {
            mx = 1;
            pcm = true;
        }
    }

    if (!pcm)
    {
        temp = arr[l];
        for (int i = l + 1; i <= r; i++)
        {
            if (arr[i] > temp)
            {
                length++;
            }
            else
            {
                if (length > 1)
                {
                    mx++;
                }
                length = 1;
            }
            temp = arr[i];
        }

        if (length > 1)
        {
            mx++;
        }

        if (mx == 1)
        {
            if (one.first.first > l && one.first.second < r)
            {
                one.first.first = max(one.first.first, l);
                one.first.second = max(one.first.second, r);
            }
            one.second = 1;
        }
    }

    temp = arr[r];
    length = 1;

    if (one.first.first <= l && one.first.second >= r)
    {
        if (one.second == 1)
        {
            mi = 1;
            pcmi = true;
        }
    }

    if (!pcmi)
    {
        for (int i = r - 1; i >= l; i--)
        {
            if (arr[i] > temp)
            {
                length++;
            }
            else
            {
                if (length > 1)
                {
                    mi++;
                }
                length = 1;
            }
            temp = arr[i];
        }

        if (length > 1)
        {
            mi++;
        }

        if (mx == 1)
        {
            if (one.first.first > l && one.first.second < r)
            {
                one.first.first = max(one.first.first, l);
                one.first.second = max(one.first.second, r);
            }
            one.second = 1;
        }
    }

    if(mi == mx){
        return true;
    }
    return false;
}

int main(){
    int n,q;
    cin>>n>>q;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        if(findQuery(arr,l,r)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}