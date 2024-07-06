#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x, y;
};

int ans = INT_MAX;

void solve(int sx, int sy, int dis, int cnt, int n, vector<int> vis, point p)
{
    if (cnt == n)
    {
        ans = min(ans, dis + abs(sx - p[n + 1].x) + abs(sy - p[n + 1].y));
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[p[i].x][p[i].y] == 0)
        {
            vis[p[i].x][p[i].y] = 1;
            solve(p[i].x, p[i].y, dis + abs(sx - p[i].x) + abs(sy - p[i].y), cnt + 1, vis, p);
            vis[p[i].x][p[i].y] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        point p[15];
        cin >> p[0].x >> p[0].y >> p[n + 1].x >> p[n + 1].y;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i].x >> p[i].y;
        }
        vector<int> vis(n + 2, 0);
        solve(p[0].x, p[0].y, 0, 0, n, vis, p);
        cout << ans << endl;
    }
}