class myCompare{
    public:
    bool operator()(int a, int b){
        return a > b;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, myCompare> pq;
        
        int n = nums.size();
        int ct = 0;
        for(int i=0; i<n; i++){
            if(ct < k){
                pq.push(nums[i]);
                ct++;
            }
            else{
                if(nums[i] > pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        
        return pq.top();
    }
};