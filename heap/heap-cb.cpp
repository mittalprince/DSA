#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int> v;
    /*
    minHeap is used to define the congfiguration og heap whether min or max;
    if minHeap is set means we use minHeap otherwise max heap;
    */
    bool minHeap; 

    bool compare(int a, int b){
        /*
            if we are using min heap then parent value should be less than chilren so a -> children & b -> parent
        */
        if(minHeap){
            return a<b;
        }
        else{
            return a>b;
        }
    }

    void heapify(int i){
        int left = 2*i;
        int right = 2*i+1;

        int minindex = i;

        if(left < v.size() && compare(v[left], v[i])){
            minindex = left;
        }
        if (right < v.size() && compare(v[right], v[minindex]))
        {
            minindex = right;
        }

        if(minindex != i){
            swap(v[i], v[minindex]);
            heapify(minindex);
        }
    }
    public:
    Heap(bool type=true){
        minHeap = type;
        v.push_back(-1);
    }

    void push(int data){
        v.push_back(data);
        int index = v.size()-1;
        int parent = index>>1;
        
        while(index>1 && compare(v[index], v[parent])){
            swap(v[index], v[parent]);
            index = parent;
            parent = parent>>1;
        }
    }

    bool empty(){
        return v.size()==1;
    }

    int top(){
        return v[1];
    }

    void pop(){
        int last = v.size()-1;
        swap(v[1], v[last]);
        v.pop_back();
        heapify(1);
    }
};

int main(){
    Heap h(false);
    h.push(5);
    h.push(15);
    h.push(20);
    h.push(3);
    h.push(2);
    h.push(10);

    while(!h.empty()){
        cout<<h.top()<<endl;
        h.pop();
    }
    return 0;
}