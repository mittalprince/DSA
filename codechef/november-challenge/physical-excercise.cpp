#include <iostream>
#include<cmath>
#include<climits>
#include <iomanip>

using namespace std;
#define K 2

double dist(int pt1[], int pt2[]){
    double distance= 0;
    for(int i=0; i<K; i++){
        distance += ((pt1[i]-pt2[i]) * (pt1[i]-pt2[i]));
    }

    return sqrt(distance);
}

class Node
{
public:
    int points[K];
    Node *left, *right;
    Node() : right(NULL), left(NULL){}
};

Node *newNode(int arr[])
{
    Node *temp = new Node();
    for (int i = 0; i < K; i++)
    {
        temp->points[i] = arr[i];
    }

    return temp;
}

Node *insertNode(Node *root, int point[], int depth)
{
    if (root == NULL)
    {
        return newNode(point);
    }

    int curr_depth = depth % K;

    if (point[curr_depth] < root->points[curr_depth])
    {
        root->left = insertNode(root->left, point, depth + 1);
    }
    else
    {
        root->right = insertNode(root->right, point, depth + 1);
    }

    return root;
}

void searchNode(Node *root, int point[], int depth, double& min_dist, int* ans)
{ 
    if(root == NULL){
        return;
    }

    double curr_root_dist = dist(point, root->points);
    if(curr_root_dist < min_dist){
        min_dist = curr_root_dist;
        for (int i = 0; i < K; i++)
        {
            ans[i] = root->points[i];
        }
    }

    int curr_depth = depth % K;

    if(point[curr_depth] < root->points[curr_depth]){
        return searchNode(root->left, point, depth+1, min_dist, ans);
    }
    else{
        return searchNode(root->right, point, depth+1, min_dist, ans);
    }
    // return;
        
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int start_pt[K];
        for(int i=0; i<K; i++){
            cin>>start_pt[i];
        }

        int n,m,k;
        cin>>n>>m>>k;

        Node* N = NULL;
        for(int i=0; i<n; i++){
            int arr[K];
            for (int i = 0; i < K; i++)
            {
                cin >> arr[i];
            }

            N = insertNode(N, arr, 0);
        }

        Node* M = NULL;
        for (int i = 0; i < m; i++)
        {
            int arr[K];
            for (int i = 0; i < K; i++)
            {
                cin >> arr[i];
            }

            M = insertNode(M, arr, 0);
        }

        Node* E = NULL;
        for (int i = 0; i < n; i++)
        {
            int arr[K];
            for (int i = 0; i < K; i++)
            {
                cin >> arr[i];
            }

            E = insertNode(E, arr, 0);
        }

        int ans1[2] = {0};
        int ans2[2] = {0};
        double min_dist1 = __DBL_MAX__, min_dist2 = __DBL_MAX__;
        searchNode(N, start_pt, 0, min_dist1, ans1);
        searchNode(M, start_pt, 0, min_dist2, ans2);
        
        int ans3[2] = {0};
        int ans4[2] = {0};
        double min_dist3 = __DBL_MAX__, min_dist4 = __DBL_MAX__;
        searchNode(M, ans1, 0, min_dist3, ans3);
        searchNode(N, ans2, 0, min_dist4, ans4);

        cout<<"********** 1 ************"<<endl;
        cout << min_dist1 << endl;
        for (int i = 0; i < K; i++)
        {
            cout << ans1[i] << ", ";
        }
        cout << endl;
        cout << "********** 2 ************" << endl;
        cout << min_dist2 << endl;
        for (int i = 0; i < K; i++)
        {
            cout << ans2[i] << ", ";
        }
        cout << endl;

        if(min_dist1+min_dist3 < min_dist2+min_dist4){
            cout << "********** Combine ************" << endl;
            cout<<min_dist1<<" "<<min_dist3<<endl;
            for (int i = 0; i < K; i++)
            {
                cout << ans1[i] << ", ";
            }
            cout<<endl;
            for (int i = 0; i < K; i++)
            {
                cout << ans3[i] << ", ";
            }

            double min_dist5 = __DBL_MAX__;
            int ans5[2] = {0};
            searchNode(E, ans3, 0, min_dist5, ans5);
            cout <<endl<< "********** 5 ************" << endl;
            cout << min_dist5 << endl;
            for (int i = 0; i < K; i++)
            {
                cout << ans5[i] << ", ";
            }
            cout << fixed << setprecision(10) <<min_dist1 + min_dist3 + min_dist5 << endl;
        }
        else{
            cout <<endl<< "********** Combine ************" << endl;
            cout << min_dist2 << " " << min_dist4 << endl;
            for (int i = 0; i < K; i++)
            {
                cout << ans2[i] << ", ";
            }
            cout << endl;
            for (int i = 0; i < K; i++)
            {
                cout << ans4[i] << ", ";
            }
            double min_dist5 = __DBL_MAX__;
            int ans5[2] = {0};
            searchNode(E, ans4, 0, min_dist5, ans5);

            cout <<endl<< "********** 5 ************" << endl;
            cout << min_dist5 << endl;
            for (int i = 0; i < K; i++)
            {
                cout << ans5[i] << ", ";
            }
            cout <<fixed<<setprecision(10)<< min_dist2 + min_dist4 + min_dist5 << endl;
            ;
        }
        // cout << min_dist3 << endl;
        // for (int i = 0; i < K; i++)
        // {
        //     cout << ans3[i] << ", ";
        // }
        cout << endl;
    }
}