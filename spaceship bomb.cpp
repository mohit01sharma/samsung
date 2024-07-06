#include <bits/stdc++.h>
using namespace std;

void updateMatrix(int row, char **matrix)
{
    int limit = max(0, row - 4);
    for (int i = row; i >= limit; i--)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] == '2')
                matrix[i][j] = '0';
        }
    }
}

int solve(int i, int j, char **matrix, int bomb)
{
    if (i <= 0)
        return 0;
    int ans = 0;
    int y[3] = {-1, 0, 1};
    for (int k = 0; k < 3; k++)
    {
        int nx = i - 1;
        int ny = j + y[k];
        if (nx >= 0 && ny >= 0 && ny < 5)
        {
            if (matrix[nx][ny] == '1')
            {
                ans += 1 + solve(nx, ny, matrix, bomb);
            }
            if (matrix[nx][ny] == '0')
            {
                ans += solve(nx, ny, matrix, bomb);
            }
        }
    }
    if (ans == 0 && bomb)
    {
        updateMatrix(i - 1, matrix);
        ans += solve(i, j, matrix, 0);
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    for (int p = 1; p <= t; p++)
    {
        int row;
        cin >> row;
        char **matrix = new char *[row + 2];
        for (int i = 0; i < row; i++)
        {
            matrix[i] = new char[5];
            for (int j = 0; j < 5; j++)
            {
                cin >> matrix[i][j];
            }
        }
        cout << solve(1, 2, row, matrix, 1);
    }
}