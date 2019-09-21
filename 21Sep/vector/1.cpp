#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class fruit{
    public:
    char a;
    int cost;

    fruit(char name, int c):a(name),cost(c){}
};


bool compare(fruit a, fruit b){
    return a.cost < b.cost;
}

int main(){

    vector<fruit> v;
    char ch;
    int cost;
    for(int i=0; i<4; i++){
        cin>>ch>>cost;
        fruit a(ch, cost);
        v.push_back(a);
    }
    sort(v.begin(), v.end(), compare);
    for(auto i: v){
        cout<<i.a<<" "<<i.cost<<endl;
    }
    return 0;
}
