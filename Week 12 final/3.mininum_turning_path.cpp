#include <iostream>
using namespace std;

// define glabal variables
int maze[101][101];

int visited[101][101];

bool found_path = false;
int n, m;
int x1, y1;
int x2, y2;

int dir_path = 999;
void floodfill(int x, int y, int step_count, int dir, int dir_count) {
    if (x < 0 || y < 0 || x >= n || y >= m || visited[x][y] || maze[x][y] == 1)
        return;

    if ((x == x2 - 1) && (y == y2 - 1))  // reach end point
    {
        found_path = true;
        dir_path = min(dir_path, dir_count);
        return;
    }
    visited[x][y] = 1;
    step_count += 1;
    if (dir == 1) {
        floodfill(x + 1, y, step_count, 1, dir_count);
    } else {
        floodfill(x + 1, y, step_count, 1, dir_count + 1);
    }

    if (dir == 2) {
        floodfill(x - 1, y, step_count, 2, dir_count);
    } else {
        floodfill(x - 1, y, step_count, 2, dir_count + 1);
    }

    if (dir == 3) {
        floodfill(x, y + 1, step_count, 3, dir_count);
    } else {
        floodfill(x, y + 1, step_count, 3, dir_count + 1);
    }

    if (dir == 4) {
        floodfill(x, y - 1, step_count, 4, dir_count);
    } else {
        floodfill(x, y - 1, step_count, 4, dir_count + 1);
    }

    visited[x][y] = 0;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    cin >> x1 >> y1 >> x2 >> y2;
    if (x1==x2 && y1 == y2) {
        found_path = true;
        dir_path = 1;
    }else {
        floodfill(x1 - 1, y1 - 1, 0, 0, 0);
    }
    

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << maze[i][j];
    //     }
    //     cout << "\n";
    // }

    if (found_path) {
        cout << dir_path-1;
    } else
        cout << -1;
}