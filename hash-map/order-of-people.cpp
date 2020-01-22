#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

#define pp pair<int, int> 

vector<int> order(vector<int> &A, vector<int> &B) {
    
    int n = A.size();
    vector<int> ans(n, -1);
    if(n == 1){
        ans.push_back(A[0]);
        return ans;
    }

    vector<pair<int, int>> p;

    for(int i=0; i<n; i++){
        p.push_back(make_pair(A[i], B[i]));
    }
    sort(p.begin(), p.end());

    vector<int> temp(n);
    for(int i=0; i<n; i++){
        temp[i] = i;
    }

    for(int i=0; i<n; i++){
        ans[temp[p[i].second]] = p[i].first;
        auto it = temp.begin() + p[i].second;
        temp.erase(it);
    }

    return ans;
}

int main(){
    vector<int> A = {86, 77};
    vector<int> B = {0, 1};

    vector<int> ans = order(A, B);
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}