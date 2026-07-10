#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // dp[i][j] — максимальное золото, которое можно собрать, придя в клетку (i, j)
    vector<vector<int>> dp(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int best = 0;
            if (i > 0) best = max(best, dp[i - 1][j]);      // сверху
            if (j > 0) best = max(best, dp[i][j - 1]);      // слева
            if (i > 0 && j > 0) best = max(best, dp[i - 1][j - 1]); // по диагонали
            dp[i][j] = a[i][j] + best;
        }
    }

    cout << dp[n - 1][m - 1] << '\n';
    return 0;
}
