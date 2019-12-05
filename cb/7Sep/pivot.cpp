// #include<bits/stdc++.h>
// using namespace std;

// // int pivot(int arr[], int s, int e){
    
// //     if(s >= e){
// //         return -1;
// //     }
// //     int mid = (s+e)/2;

// //     if(arr[mid] < arr[mid-1] && arr[mid]<arr[mid+1]){
// //         return mid;
// //     }
// //     if(arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1]){
// //         return pivot(arr, mid, e);
// //     }
// //     else{
// //         return pivot(arr, s, mid);
// //     }

// int pivot(int arr[], int s, int e, int key){
//     int mid = (s+e)/2;
//     if(arr[s]< arr[mid]){
//         if(key > arr[s] && key < arr[mid]){
//             pivot(arr, s, mid, key);
//         }
//         else{
//             pivot(arr, mid+1, e, key);
//         }
//     }
//     else if(arr[mid] < arr[s]){
//         if(key > arr[mid] && key < arr[e]){
//             pivot(arr, mid )
//         }
//     }


// }

// // }



// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//     }

//     int pv = pivot(arr, 0, n);
//     int key;
//     cin>>key;
//     int start, end;
//     if(key > arr[pv] && key < arr[n-1]){
//        start =  pv;
//        end = n-1;
//     }
//     else{
//         start = 0;
//         end = pv-1;
//     }

//     while(start <= end){
//         int mid= (start+end)/2;
//         if(arr[mid])
//     }
//     return 0;
// }