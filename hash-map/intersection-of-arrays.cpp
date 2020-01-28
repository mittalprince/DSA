#include<iostream>
#include<map>
#include<iterator>
#include<vector>
using namespace std;

int main() {
    int n,temp;
    cin>>n;
    map<int, int> m1, m2;
    for(int i=0; i<n; i++){
        cin>>temp;
        m1[temp]++;
    }
    for(int i=0; i<n; i++){
        cin>>temp;
        m2[temp]++;
    }
    
	map<int,int>::iterator it1 = m1.begin();
	map<int,int>::iterator it2 = m2.begin();

    vector<int> v;
	while(it1 != m1.end() && it2 != m2.end()){
		if(it1->first == it2->first){
            int temp = 0;
            if(it1->second <= it2->second){
                temp = it1->second;
            }
            else{
                temp = it2->second;
            }
			while(temp--){
                v.push_back(it1->first);
            }
            it1++;
            it2++;
		}
		else if(it1->first < it2->first){
			it1++;
		}
		else{
			it2++;
		}
        
	}
    cout<<"[";
    for(int i=0; i<v.size(); i++){
        if(i==0){
            cout<<v[i];
        }
        else{
            cout<<", "<<v[i];
        }
    }
    cout<<"]\n";
	return 0;
}

/*

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> m;
        for(int& n : nums1){
            m[n]++;
        }
        for(int& n : nums2){
            if(m.find(n) != m.end() && m[n] > 0){
                res.push_back(n);
                m[n]--;
            }
        }
        return res;
    }
};

*/