#include <iostream>
using namespace std;

// define glabal variables
int maze[5][5] = {{0, 0, 0, 0, 0},
                  {0, 1, 1, 1, 0},
                  {0, 1, 0, 0, 0},
                  {0, 1, 0, 1, 0},
                  {0, 0, 0, 1, 0}};

int visited[5][5] = {{0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0}};
int d[2][8] = {{-1, 1, -1, 1, 0, 1, 1, 0}, {0, 0, 1, 1, 1 - 1, -1, -1}};

bool found_path = false;
int n = 4;

void floodfill(int x, int y) {
    if (x < 0 || y < 0 || x > n || y > n || visited[x][y] || maze[x][y]) return;
    if ((x == n) && (y == n))  // reach end point
    {
        found_path = true;
        return;
    }
    visited[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        floodfill(x + d[0][i], y + d[1][i]);
    }
}

int main() {
    floodfill(0, 0);
    if (found_path)
        cout << "YES";
    else
        cout << "NO";
}