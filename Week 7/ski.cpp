#include <iostream>
using namespace std;

// define glabal variables
int maze[200][200];

int visited[200][200];

int n, m;

int floodfill(int x, int y, int level) {
    if (x < 0 || y < 0 || x >= n || y >= m || visited[x][y] == 1) return 0;

    int current = maze[x][y];
    if (level < current) {
        return 0;
    }

    visited[x][y] = 1;
    int a = floodfill(x + 1, y, current);
    int b = floodfill(x - 1, y, current);
    int c = floodfill(x, y + 1, current);
    int d = floodfill(x, y - 1, current);
    visited[x][y] = 0;
    return max(max(a, b), max(c, d)) + 1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }
    int f_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int step_count = floodfill(i, j, maze[i][j]);
            f_count = max(step_count, f_count);
        }
    }

    cout << f_count;
 
}