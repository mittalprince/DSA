
priority_queue<int> pq_max;
priority_queue<int, vector<int>, greater<int>> pq_min;
double median = 0;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        pq_max = priority_queue<int>();
        pq_min = priority_queue<int, vector<int>, greater<int>>();
        median = 0;
    }
    
    void addNum(int num) {
        
        if(pq_max.empty() && pq_min.empty()){
            pq_max.push(num);
            return;
        }
        
        if(num <= median){
            pq_max.push(num);
        }
        else{
            pq_min.push(num);
        }

        int size1 = pq_max.size();
        int size2 = pq_min.size();
        
        if(size1 - size2 > 1){
            int temp = pq_max.top();
            pq_max.pop();
            pq_min.push(temp);
        }
        
        if(size2-size1 > 1){
            int temp = pq_min.top();
            pq_min.pop();
            pq_max.push(temp);
        }
        
    }
    
    double findMedian() {
        
        if(pq_max.empty() && pq_min.empty()){
            return median;
        }
        
        int size1 = pq_max.size();
        int size2 = pq_min.size();
        
        if(size1 == size2){
            cout<<pq_max.top()<<" "<<pq_min.top();
            median = (pq_max.top() + pq_min.top());
            median = (median/2);
        }
        else{
            if(size1 > size2){
                median = pq_max.top();
            }
            else{
                median = pq_min.top();
            }
        }
        
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */