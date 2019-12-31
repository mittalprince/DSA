#include<iostream>
using namespace std;
#define max 1000

void swap(int *a, int *b){
    int *temp = a;
    a = b;
    b = temp;
}

void transpose(int mat[][max], int n){

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(i != j){
                swap(mat[i][j], mat[j][i]);
            }
        }
    }
}

void rotateClckWise(int mat[][max], int n){

   transpose(mat, n);
   for(int i=0; i<n; i++){
       int left = 0, right = n-1;
       while(left <= right){
           swap(mat[i][left], mat[i][right]);
           left++; right--;
       }
   }
}

void rotateAntiClckWise(int mat[][max], int n)
{

    transpose(mat, n);
    for (int i = 0; i < n; i++)
    {
        int top = 0, bottom = n - 1;
        while (top <= bottom)
        {
            swap(mat[top][i], mat[bottom][i]);
            top++;
            bottom--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    
    int mat[max][max];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
        }
    }

    // rotateClckWise(mat, n);
    // cout<<"Clock Wise\n";
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    rotateAntiClckWise(mat, n);
    // cout << "Anti Clock Wise\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}