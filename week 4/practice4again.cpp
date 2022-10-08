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

bool found_path = false;
int n = 4;
int step_count = 0;
int best_path = 99;
void floodfill(int x, int y, int step_count) {
    if (x < 0 || y < 0 || x > n || y > n || visited[x][y] || maze[x][y] == 1)
        return;
    
    if ((x == n) && (y == n))  // reach end point
    {
        found_path = true;
        best_path = min(best_path, step_count);
        return;
    }
    visited[x][y] = 1;
    step_count += 1;
    floodfill(x + 1, y, step_count);
    floodfill(x - 1, y, step_count);
    floodfill(x, y + 1, step_count);
    floodfill(x, y - 1, step_count);
    visited[x][y] = 0;
    step_count -= 1;
    
}

int main() {
    floodfill(0, 0, 0);
    if (found_path){
        cout << "YES";
        cout << best_path;
    }
    else
        cout << "NO";
}