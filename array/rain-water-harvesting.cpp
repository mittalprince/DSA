#include<iostream>
using namespace std;

//Complexity n, auxilsry space n
void naiveApproach(int n, int arr[]){
    int left[n], right[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
    }

    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], arr[i]);
    }

    int units = 0;
    for(int i=0; i<n; i++){
        units += min(left[i], right[i]) - arr[i];
    }

    cout<<units<<"\n";

}

void betterAppraoch(int n, int arr[]){
    int units = 0;
    int left_max = 0, right_max = 0;
    int start = 0, end = n-1;

    while(start <= end){
        if(arr[start] < arr[end]){
            if(arr[start] > left_max){
                left_max = arr[start];
            }
            else{
                units += left_max - arr[start];
            }
            start++;
        }
        else{
            if(arr[end] > right_max){
                right_max = arr[end];
            }
            else{
                units += right_max - arr[end];
            }
            end--;
        }
    }

    cout << units << "\n";
}
int main(int argc, char **argv){

    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    naiveApproach(n, arr);
    betterAppraoch(n, arr);
}