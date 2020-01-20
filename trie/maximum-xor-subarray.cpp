#include<iostream>
using namespace std;
#define max 31

class node{
    public:
    int val, index;
    node *left, *right;

    node(){
        val = 0;
        index = -1;
        left = right= NULL;
    }
};

class Pair{
    public:
    int pre_xor, start, end;

    Pair(){
        pre_xor = 0;
        start = -1;
        end = -1;
    }
};

class trieNode{
    node *root;

    public:

    trieNode(){
        root = new node();
    }

    void insert(int pre_xor, int index){
        node *temp = root;
        for(int i=max; i>=0; i--){
            int val = pre_xor & (1<<i);
            if(!val){
                if(!temp->left){
                    temp->left = new node();
                }
                temp = temp->left;
            }
            else{
                if(!temp->right){
                    temp->right = new node();
                }
                temp = temp->right;
            }
        }

        temp->val = pre_xor;
        temp->index = index;
    }

    Pair maxXor(int pre_xor, int i){
        Pair p;
        node *temp = root;
        for(int i=max; i>=0; i--){
            int val = pre_xor&(1<<i);
            if(val){
                if(temp->left){
                    temp = temp->left;
                }
                else{
                    temp = temp->right;
                }
            }
            else{
                if(temp->right){
                    temp = temp->right;
                }
                else{
                    temp = temp->left;
                }
            }
        }

        p.pre_xor = pre_xor^temp->val;
        p.start = temp->index+1;
        p.end = i;
        return p;
    }

    Pair helper(int arr[], int n){
        Pair ans;
        int pre_xor = 0;
        insert(pre_xor, -1);

        for(int i=0; i<n; i++){
            pre_xor = pre_xor^arr[i];
            insert(pre_xor, i);

            Pair p = maxXor(pre_xor, i);
            if(ans.pre_xor < p.pre_xor){
                ans.pre_xor = p.pre_xor;
                ans.start = p.start;
                ans.end = p.end;
            }
        }

        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    trieNode root;
    Pair p = root.helper(arr, n);
    cout<<p.pre_xor<<endl;
    // cout<<p.start<<" "<<p.end<<endl;
    return 0;
}
