#include <bits/stdc++.h>

using namespace std;

void replacePi(char a[], int i)
{

    if (a[i] == '\0')
    {
        return;
    }

    if (a[i] == 'p' && a[i + 1] == 'i')
    {
        int j = i + 2;
        while (a[j] != '\0')
        {
            j++;
        }
        while (j >= (i + 2))
        {
            a[j + 2] = a[j];
            j--;
        }
        a[i] = '3';
        a[i + 1] = '.';
        a[i + 2] = '1';
        a[i + 3] = '4';
        replacePi(a, i + 4);
        return;
    }
    replacePi(a, i + 1);
}

int main()
{
    int t = 3;
    cin >> t;
    cin.ignore(256, '\n');
    while (t--)
    {
        char a[1000];
        cin.getline(a, 1000);
        replacePi(a, 0);
        cout << a << endl;
    }
    return 0;
}