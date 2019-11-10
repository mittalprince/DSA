#include<iostream>
using namespace std;
#define k 2

class Node{
public:
    int points[k];
    Node *left, *right;
    Node():right(NULL),left(NULL){
    }
};

Node* newNode(int arr[]){
    Node* temp = new Node();
    for (int i = 0; i < k; i++)
    {
        temp->points[i] = arr[i];
    }

    return temp;
}

Node* insertNode(Node* root, int point[], int depth){
    if(root == NULL){
        return newNode(point); 
    }

    int curr_depth = depth % k;

    if(point[curr_depth] < root->points[curr_depth]){
        root->left = insertNode(root->left, point, depth+1);
    }
    else{
        root->right = insertNode(root->right, point, depth+1);
    }

    return root;
}

bool isPointSame(int pt1[], int pt2[]){
    for(int i=0; i<k; i++){
        if(pt1[i] != pt2[i]){
            return false;
        }
    }
    return true;
}

bool searchNode(Node* root, int point[], int depth){
    if(root == NULL){
        return false;
    }

    int curr_depth = depth % k;

    if(isPointSame(root->points, point)){
        return true;
    }

    if(point[curr_depth] < root->points[curr_depth]){
        return searchNode(root->left, point, depth+1);
    }
    return searchNode(root->right, point, depth+1);
}

int main(){
    Node* root = NULL;
    int n;
    cin>>n;
    while(n--){
        int arr[k];
        for(int i=0; i<k; i++){
            cin>>arr[i];
        }
        root = insertNode(root, arr, 0);
    }

    int q;
    cin>>q;
    while(q--){
        int arr[k];
        for (int i = 0; i < k; i++)
        {
            cin >> arr[i];
        }

        if(searchNode(root, arr, 0)){
            cout<<"Found"<<endl;
        }
        else{
            cout<<"Not found"<<endl;
        }
    }

    return 0;
}