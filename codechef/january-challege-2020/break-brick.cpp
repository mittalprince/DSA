#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int s;
        int w1, w2, w3;
        cin >> s >> w1 >> w2 >> w3;
        if (w1 + w2 + w3 <= s)
        {
            cout << "1\n";
        }
        else if (w1 + w2 <= s || w2 + w3 <= s)
        {
            cout << "2\n";
        }
        else
        {
            cout << "3\n";
        }
    }
    return 0;
}
