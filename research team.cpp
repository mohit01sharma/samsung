#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n, r;
        vector<pair<int, int>> v(r);
        for (int i = 0; i < r; i++)
        {
            int x1, y1;
            cin >> x1 >> y1;
            v[i] = {x1, y1};
        }
        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        int ans = INT_MAX;
        int ans_x, ans_y;

        int x[4] = {-1, 0, 1, 0};
        int y[4] = {0, -1, 0, 1};

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = INT_MIN;
                for (int k = 0; k < n; k++)
                {
                    int tx = v[k].first;
                    int ty = v[k].second;
                    queue<pair<int, pair<int, int>>> q;
                    vector<vector<int>> vis(n, vector<int>(n, 0));
                    q.push({0, {i, j}});
                    while (!q.empty())
                    {
                        int lvl = q.front().first;
                        int fx = q.front().second.first;
                        int fy = q.front().second.second;
                        q.pop();
                        if (fx == tx && fy == ty)
                        {
                            temp = max(temp, lvl);
                            break;
                        }
                        for (int a = 0; a < 4; a++)
                        {
                            int nx = fx + x[a];
                            int ny = fy + y[a];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                            {
                                if (vis[nx][ny] == 0 && arr[nx][ny] == 1)
                                {
                                    vis[nx][ny] = 1;
                                    q.push({lvl + 1, {nx, ny}});
                                }
                            }
                        }
                    }
                }
                ans = min(ans, temp);
            }
        }
    }
}