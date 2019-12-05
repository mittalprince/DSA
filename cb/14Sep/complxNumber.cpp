#include<iostream>
using namespace std;

class ComplexNumber{
    public: 
        int real;
        int img;

    ComplexNumber(){
        this->real = 0;
        this->img = 0;
    }

    ComplexNumber(int real, int img){
        this->real = real;
        this->img = img;
    }

    void printNo(ComplexNumber x){
        cout<<x.real<<" + "<<x.img<<"i"<<endl;
    }

    void operator[] (string type){
        if(type == "real"){
            cout << real << endl;
        }
        else{
            cout<< img <<endl;
        }
    }
};

ostream& operator<< (ostream& o, ComplexNumber& x){
    o<< x.real << " + " << x.img << "i" << endl;
    return o;
}

istream& operator>>(istream &i, ComplexNumber& x)
{
    i>> x.real>>x.img;
    return i;
}

void operator+ (ComplexNumber a, ComplexNumber b){
    cout<<(a.real+b.real)<<" + "<<(a.img+b.img)<<"i"<<endl;
}

void operator-(ComplexNumber a, ComplexNumber b)
{
    cout << (a.real - b.real) << " + " << (a.img - b.img) << "i" << endl;
}

int main(){
    ComplexNumber a;
    ComplexNumber b;
    cin>>a>>b;
    cout<<a<<b;
    a+b;
    a-b;
    a["real"];
    return 0;
}