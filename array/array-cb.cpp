#include <iostream>
using namespace std;

void linearSearch(int n, int *arr, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "At index " << i << "\n";
            break;
        }
    }

    if (i == n)
    {
        cout << "Not found \n";
    }
}

void subarray(int n, int *arr)
{
    int tot = (n * (n + 1)) >> 1;
    cout << "Total subarray " << tot << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << arr[k] << ",";
            }
            cout << "\n";
        }
    }
}

// naive approach complexity n^3
void maxSumSubArr(int n, int arr[])
{
    int sum = 0, currSum = 0;
    int start, end;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            currSum = 0;
            for (int k = i; k <= j; k++)
            {
                currSum += arr[k];
            }
            if (sum < currSum)
            {
                sum = currSum;
                start = i;
                end = j;
            }
        }
    }
    cout << "Max Subarray sum " << sum << " -> ";
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Cumulative SUm appraoch, complexity n^2
void maxSumSubArr2(int n, int arr[])
{
    int cumSum[n];
    cumSum[0] = arr[0];
    for(int i=1; i<n; i++){
        cumSum[i] = cumSum[i-1] + arr[i];
    }
    int currSum = 0, sum = 0, start, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            currSum = cumSum[j] - cumSum[i-1];
            if (sum < currSum)
            {
                sum = currSum;
                start = i;
                end = j;
            }
        }
    }
    cout << "Max Subarray sum " << sum << " -> ";
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void KadanesAlgo(int n, int arr[]){
    int cs = 0, ms = 0;
    int start = 0, end = 0, s=0;
    for(int i=0; i<n; i++){
        cs += arr[i];
        if(cs < 0){
            cs = 0;
            s = i+1;
        }
        if(ms < cs){
            ms = cs;
            start = s;
            end = i;
        }
    }
    cout << "Max Subarray sum " << ms << " -> ";
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void chewbacca(char *number){
    int i=0; 
    if(number[i] == '9'){
        i++;
    }
    for(; number[i] != '\0'; i++){
        int digit = number[i] - '0';
        if(digit >= 5){
            digit = 9 - digit;
            number[i] = digit + '0';
        }
    }

    cout<<number<<"\n";
}
 
void helper()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 3;
    linearSearch(n, arr, key);

    subarray(n, arr);

    int arr1[] = {-4, 1, 3, -2, 6, 2, -8, -9, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    maxSumSubArr(n1, arr1);
    maxSumSubArr2(n1, arr1);
    KadanesAlgo(n1, arr1);

    char number[50] = "4545";
    chewbacca(number);
}

int main(int argc, char **argv)
{
    cout << "Total argument " << argc - 1 << "\n";
    for (int i = 1; i < argc; i++)
    {
        cout << argv[i] << "\n";
    }

    helper();
    return 0;
}