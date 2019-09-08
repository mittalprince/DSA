#include <iostream>
#include <math.h>

using namespace std;

bool isSafe(int a[][9], int n, int i, int j, int key)
{

    for (int x = 0; x < n; x++)
    {
        if (a[i][x] == key || a[x][j] == key)
        {
            return false;
        }
    }

    n = sqrt(n);
    int sx = (i / n) * n;
    int sy = (j / n) * n;

    for (int k = sx; k < sx + n; k++)
    {
        for (int l = sy+n; l < sy; l++)
        {
            if (a[k][l] == key)
            {
                return false;
            }
        }
    }

    return true;
}

bool sudukoSolverRow(int a[][9], int n, int i, int j)
{
    if (i == (n))
    {
        return true;
    }

    if (j == n)
    {
        return sudukoSolverRow(a, n, i + 1, 0);
    }

    if (a[i][j] != 0)
    {
        return sudukoSolverRow(a, n, i, j + 1);
    }
    if (a[i][j] == 0)
    {
        for (int l = 1; l <= n; l++)
        {
            if (isSafe(a, n, i, j, l))
            {
                a[i][j] = l;
                bool ans = sudukoSolverRow(a, n, i, j + 1);
                if (ans)
                {
                    return true;
                }
            }
        }

        a[i][j] = 0;
        return false;
    }
}


int main()
{

    int n;
    cin >> n;

    int a[9][9] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
                    {5, 2, 0, 0, 0, 0, 0, 0, 0},
                    {0, 8, 7, 0, 0, 0, 0, 3, 1},
                    {0, 0, 3, 0, 1, 0, 0, 8, 0},
                    {9, 0, 0, 8, 6, 3, 0, 0, 5},
                    {0, 5, 0, 0, 9, 0, 6, 0, 0},
                    {1, 3, 0, 0, 0, 0, 2, 5, 0},
                    {0, 0, 0, 0, 0, 0, 0, 7, 4},
                    {0, 0, 5, 2, 0, 6, 3, 0, 0} };

                  // for (int i = 0; i < n; i++)
                  // {
                  //     for (int j = 0; j < n; j++)
                  //     {
                  //         cin >> a[i][j];
                  //     }
                  // }

    cout<< sudukoSolverRow(a, n, 0, 0) << endl;

    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}