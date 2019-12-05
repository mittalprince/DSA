#include <iostream>
using namespace std;

int merge(int arr[], int s, int e)
{   int ct = 0;
    int mid = (s + e) / 2;
    int i = s, j = mid + 1, k = s;
    int temp[e];
    while (i <= mid && j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {   ct += mid-i+1;
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= e)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    for (int i = s; i <= e; i++)
    {
        arr[i] = temp[i];
    }

    return ct;
}
int  mergeSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return 0;
    }
    int mid = (s + e) / 2;
    int x = mergeSort(arr, s, mid);
    int y = mergeSort(arr, mid + 1, e);

    return x+y+merge(arr, s, e);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<mergeSort(arr, 0, n)<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}