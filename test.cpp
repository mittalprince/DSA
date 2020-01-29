#include <bits/stdc++.h>
#define maxN 2111111 //6
using namespace std;
int n, m, x[maxN], p[maxN], r[maxN], infix[maxN], pst[maxN], ct[maxN], ans[maxN];
vector<pair<int, int> > pr;
bool myComparison(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second > b.second;
    else
        return a.first < b.first;
}
int find_set(int x)
{
    if (x != p[x])
        p[x] = find_set(p[x]);
    return p[x];
}
void merge_set(int x, int y)
{
    int ax = find_set(x);
    int bx = find_set(y);
    if (r[ax] > r[bx]) // r -> c
        p[bx] = ax;
    else
        p[ax] = bx;
    if (r[ax] == r[bx])
        r[bx]++;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        // scanf("%d", &x[i]);
        p[i] = i;
        r[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        // scanf("%d%d", &a, &b);
        merge_set(x[a], x[b]);
    }

    //for(int i=1;i<=n;i++)cout<<p[ x[i] ]<<' ';cout<<endl;
    for (int i = 1; i <= n; i++)
        find_set(i);
    pr.push_back(make_pair(-1, -1));
    for (int i = 1; i <= n; i++)
        pr.push_back(make_pair(p[x[i]], x[i]));

    sort(pr.begin(), pr.end(), myComparison);

    for (int i = 1; i <= n; i++)
        if (infix[pr[i].first] == 0)
            infix[pr[i].first] = i;

    for (int pos = 1; pos <= n; pos++)
    {
        int i = p[x[pos]];
        pst[infix[i] + (ct[i])] = pos;
        ct[i]++;
    }

    for (int i = 1; i <= n; i++)
        ans[pst[i]] = pr[i].second;

    for (int i = 1; i <= n; i++)
        cout << ans[i];
    // printf("%d ", ans[i]);

    return 0;
}
