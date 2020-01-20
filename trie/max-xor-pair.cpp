#include<iostream>
using namespace std;
#define max 31

class node{
    public:
    int val;
    node *left, *right;

    node(){
        int val = 0;
        left = right = NULL;
    }
};

class trieNode{
    node *root;

    public:

    trieNode(){
        root = new node();
    }

    int insert(int val){
        node *temp = root;
        node *temp_xor = root;
        int curr = 0;
        for(int i=max; i>=0; i--){
            int v = val&(1<<i);
            if(!v){
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

            if (v)
            {
                if (temp_xor->left)
                {
                    curr += (1 << i);
                    temp_xor = temp_xor->left;
                }
                else
                {
                    temp_xor = temp_xor->right;
                }
            }
            else
            {
                if (temp_xor->right)
                {
                    curr += (1 << i);
                    temp_xor = temp_xor->right;
                }
                else
                {
                    temp_xor = temp_xor->left;
                }
            }
        }
        temp->val = val;
        return curr;
    }

    int maxXorPair(int arr[], int n){
        int ans = 0;
        for(int i=0; i<n; i++){
            int curr_val = arr[i];
            int curr_max = 0;
            node *temp = root;
            for(int i=max; i>=0; i--){
                int val = curr_val&(1<<i);
                if(val){
                    if(temp->left){
                        curr_max += (1<<i);
                        temp = temp->left;
                    }
                    else{
                        temp = temp->right;
                    }
                }
                else{
                    if(temp->right){
                        curr_max += (1 << i);
                        temp = temp->right;
                    }
                    else{
                        temp = temp->left;
                    }
                }
            }

            if(curr_max > ans){
                ans = curr_max;
            }
        }

        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    int arr[n];
    trieNode root;
    int ans = 0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        int temp = root.insert(arr[i]);
        if(ans<temp){
            ans = temp;
        }
    }

    // int ans = root.maxXorPair(arr, n);
    cout<<ans<<endl;
    return 0;
}
