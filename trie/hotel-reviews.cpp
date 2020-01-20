#include<iostream>
#include<vector>
#include<map>
using namespace std;

class node{
    public:
    char val;
    bool isEnd;
    map<char, node*>m;
    
    node(char ch){
        val = ch;
        isEnd = false;
    }
};

class trieNode{
    node *root;
    
    public:
    
    trieNode(){
        root = new node('\0');
    }
    
    void insert(string s){
        
        for(int i=0; i<s.length(); i++){
            string t;
           node *temp = root;
           while(s[i] != '_' && s[i] != '\0'){
               t+= s[i];
               if(temp->m.find(s[i]) == temp->m.end()){
                   temp->m[s[i]] = new node(s[i]);
               }
               temp = temp->m[s[i]];
               i++;
           }
        //    cout<<t<<endl;
           temp->isEnd = true;
        }
    }
    
    bool search(string s){
        // cout<<s<<endl;
        node *temp = root;
        for(int i=0; i<s.length(); i++){
            if(temp->m.find(s[i]) == temp->m.end()){
                return false;
            }
            temp = temp->m[s[i]];
        }   
        return temp->isEnd;
    }
    
};

bool comparator(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solve(string A, vector<string> &B) {
    
    trieNode root;
    root.insert(A);
    
    vector<pair<int, int> >temp;
    int n = B.size();

    for(int i=0; i<n; i++){
        int ct = 0;
        for(int j=0; j<B[i].length(); j++){
            string stream;
            while(B[i][j] != '_' && B[i][j] != '\0'){
                stream+= B[i][j];
                j++;
            }
            // cout<<stream<<" -> "<<endl;
            if(root.search(stream)){
                ct++;
            }
        }
        temp.push_back(make_pair(ct, i));
    }

    
    sort(temp.begin(), temp.end(), comparator);
    vector<int> ans;
    
    for(auto it: temp){
        ans.push_back(it.second);
    }
    
    return ans;
    
}

int main(){
    string A = "cool_ice_wifi";
    vector<string> B;
    B.push_back("water_is_cool");
    B.push_back("cold_ice_drink");
    B.push_back("cool_wifi_speed");

    vector<int> ans = solve(A, B);
    for(auto i: ans){
        cout<<i<<endl;
    }
}
