#include <bits/stdc++.h>
using namespace std;

int ans = INT_MIN;

void solve(int p1,int p2,vector<int> vis,vector<int> arr){
    if(p1==p2){
        ans = max(ans, p1);
    }
    for (int i = 0; i < n;i++){
        if(vis[i]==0){
            vis[i] = 1;
            solve(p1 + arr[i], p2, vis, arr);
            solve(p1, p2 + arr[i], vis, arr);
            vis[i] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> used(n);
    solve(0, 0, used, arr);
}