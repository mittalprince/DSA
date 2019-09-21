class Queue{
    int *arr;
    int f,r,ms,cs;

    public:

    Queue(int ds=5){
        ms = ds;
        arr = new int[ms];
        cs = 0;
        f = 0;
        r = ms-1;
    }

    void push(int data){
        if(cs == ms){
            return;
        }
        else{
            r = (r+1)%ms;
            arr[r] = data;
            r++;
            cs++;
        }
    }

    void pop(){
        if(cs == 0){
            return;
        }
        f++;
        f = (f+1)%ms;
        cs--;
    }

    bool empty(){
        return cs==0;
    }

    bool full(){
        return cs==ms;
    }

    int front(){
        return arr[f];
    }
};

