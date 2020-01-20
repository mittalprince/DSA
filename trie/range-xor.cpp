#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <vector>
using namespace std;
typedef long long ll;
#define max 31

bool binarySearch(vector<ll> v, ll l, ll r)
{
    int start = 0, end = v.size()-1;
    while(start <= end){
        int mid = (start + end) / 2;
        int val = v[mid];
        if (val >= l && val <= r)
        {
            return true;
        }
        else if (val < l)
        {
            start = mid + 1;
        }
        else if (val > r)
        {
            end = mid - 1;
        }
    }

    return false;
}

class node
{
public:
    ll val;
    node *left, *right;
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
    trieNode()
    {
        root = new node();
    }

    void insert(ll val, ll index)
    {
        node *temp = root;
        for (int i = max; i >= 0; i--)
        {
            ll bit = val&(1<<i);
            if (!bit)
            {
                if (!temp->left)
                {
                    temp->left = new node();
                }
                temp = temp->left;
            }
            else
            {
                if (!temp->right)
                {
                    temp->right = new node();
                }
                temp = temp->right;
            }
            temp->v.push_back(index);
        }
        temp->val = val;
        temp->v.push_back(index);
    }

    ll findMaxXor(ll l, ll r, ll y)
    {
        // cout<<l<<r<<y<<endl;
        node *temp = root;
        for (int i = max; i >= 0; i--)
        {
            ll bit = y & (1 << i);
            if (bit)
            {
                if (temp->left && (binarySearch(temp->left->v, l, r)))
                {
                    temp = temp->left;
                }
                else
                {
                    if(temp->right){
                        temp = temp->right;
                    }
                }
            }
            else
            {
                if (temp->right && (binarySearch(temp->right->v, l, r)))
                {
                    temp = temp->right;
                }
                else
                {
                    if(temp->left){
                        temp = temp->left;
                    }
                }
            }
        }

        return temp->val;
    }
};

int main()
{
    ll q;
    cin >> q;
    trieNode root;
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