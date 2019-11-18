#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            temp += a;
        }

        if (temp <= k)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    // your code goes here
    return 0;
}