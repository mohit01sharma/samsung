#include <bits/stdc++.h>

using namespace std;

int cntw = 0;
int cntb = 0;

bool isSame(int x, int y, int size, vector<vector<int>> v)
{
    int num = v[x][y];
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (num != v[i][j])
                return false;
        }
    }
    return true;
}

void solve(int x, int y, int size, vector<vector<int>> v)
{
    if (isSame(x, y, k, v))
    {
        if (v[x][y] == 0)
            cntw++;
        if (v[x][y] == 1)
            cntb++;
        return;
    }
    solve(x, y, size / 2, v);
    solve(x, y + size / 2, size / 2, v);
    solve(x + size / 2, y, size / 2, v);
    solve(x + size / 2, y + size / 2, size / 2, v);
}

int main()
{
    int t;
    cin >> t;
    for (int p = 1; p <= t; p++)
    {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }
        solve(0, 0, n, v);
        cout << "Case #" << p << endl
             << cntw << " " << cntb << endl;
    }
}