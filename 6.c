#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    for (int i = 0; i < N; ++i) cin >> grid[i];

    int x, y;
    cin >> x >> y;
    --x; --y; // переводим в 0-индексацию

    // dist[i][j] = длина кратчайшего пути от старта до клетки (i,j), -1 если недостижима
    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int,int>> q;

    dist[x][y] = 0;
    q.push({x, y});

    // направления: вниз, вверх, вправо, влево
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = cx + dx[d], ny = cy + dy[d];
            // выходим за границы
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            // непроходимая клетка
            if (grid[nx][ny] == '#') continue;
            // уже посещали
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[cx][cy] + 1;
            q.push({nx, ny});
        }
    }

    // вывод матрицы расстояний
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << dist[i][j] << (j == M-1 ? '\n' : ' ');
        }
    }

    return 0;
}
