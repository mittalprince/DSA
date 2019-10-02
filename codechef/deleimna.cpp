#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int j = 0;
        int ans = 0;
        while (s[j] != '\0')
        {
            if (s[j] == '1')
            {
                ans++;
            }
            j++;
        }

        if (ans & 1)
        {
            cout << "WIN" << endl;
        }
        else
        {
            cout << "LOSE" << endl;
        }
    }

    return 0;
}
