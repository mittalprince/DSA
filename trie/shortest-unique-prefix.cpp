class node{
    public:
    char val;
    bool isEnd;
    int ct;
    map<char, node*>m;
    
    node(char ch){
        val = ch;
        ct = 0;
        isEnd = false;
    }
    node(char ch, int n){
        val = ch;
        ct = n;
        isEnd = false;
    }
};

class trieNode{
    node* root;
    public:
    
    trieNode(int n){
        root = new node('\0');
    }
    
    void insert(string s){
        node *temp = root;
        for(int i=0; i<s.length(); i++){
            temp->ct++;
            if(temp->m.find(s[i]) == temp->m.end()){
                temp->m[s[i]] = new node(s[i]);
            }
            temp = temp->m[s[i]];
        }
        temp->isEnd = true;
        temp->ct++;
    }
    
    void search(string s, vector<string> &A){
        node *temp = root;
        string res;
        for(int i=0; i<s.length(); i++){
            res.push_back(s[i]);
            temp = temp->m[s[i]];
            if(temp->ct == 1 ){
                A.push_back(res);
                return;
            }
            
        }
    }
};
vector<string> Solution::prefix(vector<string> &A) {
    vector<string> ans;
    int n = A.size();
    trieNode root(n);
    for(int i=0; i<n; i++){
        root.insert(A[i]);
    }
    
    for(int i=0; i<n; i++){
        root.search(A[i], ans);
    }
    return ans;
}
