vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    int n = A.size();
    vector<int>ans(n), temp(n);
    
    for(int i=0; i<n; i++){
        temp[i] = i;
    }
    
    vector<pair<int, int> > p;
    for(int i=0; i<n; i++){
        p.push_back(make_pair(A[i], B[i]));
    }
    
    sort(p.begin(), p.end());
    
    for(int i=0; i<n; i++){
        ans[temp[p[i].second]] = p[i].first;
        auto it = temp.begin() + p[i].second;
        temp.erase(it);
    }
    
    return ans;
}
