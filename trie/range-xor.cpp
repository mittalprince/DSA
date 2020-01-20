#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <vector>
using namespace std;
typedef long long ll;
#define max 31
#define N 100000

bool binarySearch(vector<ll> v, ll l, ll r)
{
    // cout<<key<<endl;
    ll s = 0;
    ll e = v.size() - 1;

    if(l<= v[s] && r >= v[e]){
        return true;
    }
    return false;
    // if(v[s] <= key && v[e] >= key){
    //     return true;
    // }
    // return false;

    // if(key >= v[s] && key <= v[e]){
    //     return true;
    // }
    // return false;
    // cout<<s<<" "<<e<<endl;
    // vector<int>::iterator it = v.begin();
    // for (; it != v.end(); it++)
    // {
    //     cout << *it << " -> ";
    // }
    // // cout << endl<<endl;
    // while (s <= e)
    // {
    //     // cout<<s<<" "<<e<<endl;
    //     int mid = (s + e)/2;
    //     if (key == v[mid])
    //     {
    //         return true;
    //     }
    //     else if (key < v[mid])
    //     {
    //         e = mid - 1;
    //     }
    //     else
    //     {
    //         s = mid + 1;
    //     }
    // }
    // return false;
}

class node
{
public:
    ll val;
    node *left, *right;
    map<int, bool> m;
    vector<ll> v;

    node()
    {
        val = 0;
        left = right = NULL;
    }
};

class trieNode
{
    node *root;

public:
    trieNode(ll n)
    {
        root = new node();
        root->m[0] = true;
        root->m[n - 1] = true;
    }

    void insert(ll val, ll index)
    {
        node *temp = root;
        for (int i = max; i >= 0; i--)
        {
            ll bit = val & (1 << i);
            // cout << "i "<<index << "\n";
            if (!bit)
            {
                if (!temp->left)
                {
                    temp->left = new node();
                }
                temp = temp->left;
                temp->m[i] = true;
            }
            else
            {
                if (!temp->right)
                {
                    temp->right = new node();
                }
                temp = temp->right;
                temp->m[i] = true;
            }
            temp->v.push_back(index);
            // vector<int>::iterator it = temp->v.begin();
            // for (; it != temp->v.end(); it++)
            // {
            //     cout << *it << " ";
            // }
            // cout << endl;
        }
        temp->val = val;
        // cout<<endl;
    }

    ll findMaxXor(ll l, ll r, ll y)
    {
        // cout<<l<<r<<y<<endl;
        node *temp = root;
        for (int i = max; i >= 0; i--)
        {
            ll bit = y & (1 << i);
            // cout<<bit<<" ";
            if (bit)
            {
                // bool check = (binarySearch(temp->left->v, l) || binarySearch(temp->left->v, r));
                // cout << check << endl;
                // cout<<"LEFT ";
                if (temp->left && (binarySearch(temp->left->v, l, r)))
                {
                    // cout<<"left \n";
                    temp = temp->left;
                }
                else
                {
                    // cout << "not left \n";
                    temp = temp->right;
                }
            }
            else
            {
                // vector<int>::iterator it = temp->right->v.begin();
                // for (; it != temp->right->v.end(); it++)
                // {
                //     cout << *it << " -> ";
                // }
                // cout << endl;
                // bool check = (binarySearch(temp->right->v, l) || binarySearch(temp->right->v, r));
                // cout<<check<<endl;
                // cout << "RIGHt ";
                if (temp->right && (binarySearch(temp->right->v, l, r)))
                {
                    // cout << "right\n ";
                    temp = temp->right;
                }
                else
                {
                    // cout << "not right\n ";
                    temp = temp->left;
                }
            }
        }

        return temp->val;
    }
    // int findMaxXor(int l, int r, int y){
    //     node *temp = root;
    //     map<int, bool>::iterator start, end;
    //     for(int i=max; i>=0; i--){
    //         // start = temp->m.begin();
    //         // end = temp->m.end();
    //         // cout<<start->first<<" "<<end->first<<" "<<i<<endl;
    //         // if(start->first >= l && end->first <= r){
    //             int bit = y & (1 << i);
    //             if(bit){
    //                 if (temp->left && temp->left->m.begin()->first >= l && temp->left->m.begin()->first <= r)
    //                 {
    //                     temp = temp->left;
    //                 }
    //                 else{
    //                     temp = temp->right;
    //                 }
    //             }
    //             else
    //             {
    //                 if (temp->right && temp->right->m.begin()->first >= l && temp->right->m.begin()->first <= r)
    //                 {
    //                     temp = temp->right;
    //                 }
    //                 else
    //                 {
    //                     temp = temp->left;
    //                 }
    //             }

    //         // }
    //     }

    //     return temp->val;
    // }
};

int main()
{
    ll q;
    cin >> q;
    trieNode root(N);
    // root.insert(0, -1);
    ll i = 0;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            int val;
            cin >> val;
            root.insert(val, i);
            i++;
        }
        else
        {
            ll l, r, y;
            cin >> l >> r >> y;
            l--;
            r--;
            ll ans = root.findMaxXor(l, r, y);
            cout << ans << endl;
        }
    }
}