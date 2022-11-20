#include <iostream>
using namespace std;

// define glabal variables
char maze[101][101];

int visited[101][101];

int n, m;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void transfer(int &x, int &y) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == maze[x][y] && (i != x || j != y)) {
                x = i;
                y = j;
                return;
            }
        }
    }
}

void dfs(int x, int y) {
    if (x == n - 1 && y == m - 1) {
        return;
    }
    int step = visited[x][y];

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < n && 0 <= ny && ny < m && maze[nx][ny] != '1') {
            if (maze[nx][ny] >= 'A') {
                transfer(nx, ny);
            }
            if (step + 1 < visited[nx][ny]) {
                visited[nx][ny] = step + 1;
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            visited[i][j] = INT16_MAX;
        }
    }

    visited[0][0] = 0;

    dfs(0, 0);

    if (visited[n - 1][m - 1] != INT16_MAX) {
        cout << visited[n - 1][m - 1];
    } else {
        cout << "No Solution.";
    }
}