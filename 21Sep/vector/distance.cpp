#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int distance(int x, int y){
    return sqrt((x*x)+(y*y));
}

bool comparator(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
    int x = a.second.first;
    int y = a.second.second;
    int d1 = distance(x,y);

    int X = b.second.first;
    int Y = b.second.second;
    int d2 = distance(X, Y);

    return d1<d2;
}

int main(){
    vector< pair<int , pair<int, int> > > v;

    int n;
    cin>>n;
    char ch;
    int x,y;
    for(int i=0; i<n; i++){
        cin>>ch>>x>>y;
        v.push_back(make_pair(ch, make_pair(x,y)));
    }

    sort(v.begin(), v.end(),comparator);
    
    int k;
    cin>>k;
    for(int i=0; i<k; i++){
        cout << (char)v[i].first << " " << v[i].second.first << " " << v[i].second.second<<endl;
    }
    return 0;
}