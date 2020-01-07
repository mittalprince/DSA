#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class cars
{
public:
    int x;
    int y;
    int id;

    cars(int id, int x, int y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    int dist()
    {
        return x * x + y * y;
    }

    void print(){
        cout <<"ID "<<id << " Locations " << x << " " << y << endl;
    }
};

class carCompare{
    public:

    bool operator()(cars a, cars b){
        return a.dist() > b.dist();
    }
};

int main()
{

    priority_queue<cars, vector<cars>, carCompare> pq;
    int x[10] = {5,6,17,18,9,11,0,3};
    int y[10] = {1,-2,8,9,0,91,1,2};

    for(int i=0; i<8; i++){
        cars c(i, x[i], y[i]);
        pq.push(c);
    }

    while (!pq.empty())
    {   
        cars c = pq.top();
        c.print();
        pq.pop();
    }

    // priority_queue<int, vector<int>, greater<int> > pq;
    // int arr[10] = {5,8,1,2,5,0,10,7};

    // for(int i=0; i<8; i++){
    //     pq.push(arr[i]);
    // }

    // while (!pq.empty())
    // {
    //     cout<<pq.top()<<" ";
    //     pq.pop();
    // }
    // cout<<endl;
}