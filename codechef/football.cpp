#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int b[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int max = 0;
        int temp;
        for (int i = 0; i < n; i++)
        {
            temp = a[i] * 20 - (b[i] * 10);
            if (temp > max)
            {
                max = temp;
            }
        }
        cout << max << endl;
    }
}