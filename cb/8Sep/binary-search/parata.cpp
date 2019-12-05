// #include<bits/stdc++.h>
// using namespace std;

// int maxTime(int rank, int n){
//     int time = 0;
//     for(int i=1; i<=n; i++){
//         time += (rank*i);
//     }
//     return time;
// }

// bool canMake(int rank[], int r, int parta, int time){
//     int total_parata = 0;

//     for(int i=0; i<r; i++){
//         int ct = 0;
//         int temp = time;
//         int t = rank[i];
//         while(temp > 0){
//             temp -= t;
//             if (temp > 0)
//             {
//                 ct++;
//                 t += t;
//             }
//         }
//         // ct--;
//         total_parata +=  ct;
//     }
//     if(total_parata > parta){
//         return true;
//     }
//     return false;
// }
// int main(){
//     int p, r;
//     cin>>p>>r;
//     int rank[r];
//     for(int i=0; i<r; i++){
//         cin>>rank[i];
//     }
//     int s=0;
//     int e = maxTime(rank[0], p);
//     int mid,ans=0;
//     while(s<=e){
//         mid = (s+e)>>1;
//         if(canMake(rank, r, p, mid)){
//             ans = mid;
//             e = mid-1;
//         }
//         else{
//             s = mid+1;
//         }
//     }

//     cout<<ans<<endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll maxTime(ll rank, ll parata)
{
    ll time = 0;
    for (ll i = 1; i <= parata; i++)
    {
        time += (rank * i);
    }
    return time;
}

bool canMake(ll rank[], ll total_parata, ll total_cook, ll total_time)
{

    ll make_parata = 0;

    for (ll i = 0; i < total_cook; i++)
    {
        ll curr_cook_parata = 0;
        ll temp = total_time;
        ll curr_cook_time = rank[i];

        while ((temp - (curr_cook_time)) >= 0)
        {
            curr_cook_parata++;
            temp -= curr_cook_time;
            curr_cook_time += rank[i];
            // cout<<curr_cook_time<<endl;
            if ((curr_cook_parata + make_parata) >= total_parata)
            {
                // cout << "mid " << total_time << " " << curr_cook_parata << endl;
                return true;
            }
        }
        // cout << "mid "<< total_time<< " " <<curr_cook_parata << endl;
        make_parata += curr_cook_parata;
        if (make_parata >= total_parata)
        {
            return true;
        }
    }

    return false;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll p, c;
        cin >> p >> c;
        ll rank[c];
        for (ll i = 0; i < c; i++)
        {
            cin >> rank[i];
        }
        sort(rank, rank + c);
        ll s = 0;
        ll e = maxTime(rank[0], p);
        // cout << e << endl;
        ll mid, ans = 0;
        while (s <= e)
        {
            mid = (s + e) >> 1;
            if (canMake(rank, p, c, mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}