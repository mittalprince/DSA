#include<bits/stdc++.h>
using namespace std;
#define ppi pair<int, int>

map<int, int> m;
list<int> l;
int cs = 0;
int capacity = 0;

// LRUCache::LRUCache(int capacity)
// {
//     m.clear();
//     l.clear();
//     capacity = 0;
//     cs = 0;
// }

int get(int key)
{
    if (m.find(key) != m.end())
    {
        if (l.front() == key)
        {
            return m[key];
        }
        else if (l.back() == key)
        {
            l.pop_back();
            l.push_front(key);
        }
        else
        {
            list<int>::iterator it = find(l.begin(), l.end(), key);
            if (it != l.end())
            {
                l.erase(it);
                l.push_front(key);
            }
        }

        return m[key];
    }
    else
    {
        return -1;
    }
}

void Set(int key, int value)
{

    if (m.find(key) != m.end())
    {
        m[key] = value;
        list<int>::iterator it = find(l.begin(), l.end(), key);
        l.erase(it);
        l.push_front(key);
        return;
    }

    if (l.size() < capacity)
    {
        m[key] = value;
        l.push_front(key);
    }

    else
    {
        map<int, int>::iterator it = m.find(l.back());
        if (it != m.end())
        {
            m.erase(it);
            l.pop_back();
            l.push_front(key);
            m[key] = value;
        }
    }
}

int main(){
    int n,x,y,temp;
    cin>>n>>capacity;
    char ch;
    while(n--){
        cin>>ch;
        if(ch == 'S'){
            cin>>x>>y;
            Set(x,y);
        }
        else{
            cin>>temp;
            cout<<get(temp)<<" ";
        }
    }
    cout<<endl;
}
