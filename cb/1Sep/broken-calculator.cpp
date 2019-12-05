#include <bits/stdc++.h>
using namespace std;

#define max 1000000

long long multiply(long long n, int result[], long result_size)
{
    int carry = 0;
    for (int i = 0; i < result_size; i++)
    {
        int digit = result[i] * n + carry;
        result[i] = digit % 10;
        carry = digit / 10;
    }
    while (carry)
    {
        result[result_size] = carry % 10;
        carry = carry / 10;
        result_size++;
    }
    return result_size;
}

void factorial(long long n)
{
    int result[max];

    result[0] = 1;
    long long result_size = 1;

    if (n == 0 || n == 1)
    {
        cout << "1" << endl;
        return;
    }

    for (long long i = 2; i <= n; i++)
    {
        result_size = multiply(i, result, result_size);
    }

    for (long long i = result_size - 1; i >= 0; i--)
        cout << result[i];
    cout << endl;
}

int main()
{
    long long n;
    cin >> n;
    factorial(n);
    return 0;
}