#include <bits/stdc++.h>
using namespace std;
int ans = INT_MAX;

void solve(int src, int dis, int cnt, int n, vector<int> vis, vector<vector<int>> arr)
{
    if (cnt == n-1)
    {
        if(arr[src][0]!=0){
            ans = min(ans, dis + arr[src[0]]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[src][i] == 0 && arr[src][i]!=0)
        {
            vis[src][i] = 1;
            solve(i, dis +arr[src][i] , cnt + 1,n, vis, arr);
            vis[src][i] = 0;
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
        vector<vector<int>> arr(n, vector<int>(n, 0));
        vector<int> vis(n, 0);
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                cin >> arr[i][j];
            }
        }
        solve(0, 0, 0, n, vis, arr);
        cout << ans << endl;
    }
}