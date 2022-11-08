#include <iostream>
using namespace std;

// define glabal variables
int maze[200][200];

int visited[200][200];

int n, m;
int step_count;

void floodfill(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n || visited[x][y]==1)
        return;

    step_count++;
    visited[x][y] = 1;
    floodfill(x + 1, y);
    floodfill(x - 1, y);
    floodfill(x, y + 1);
    floodfill(x, y - 1);
}

int main() {
    cin >> n >> m;

    for (int i=0;i<n;i++){
        for (int j =0; j<m; j++) {
            cin >> maze[i][j];
        }
    }
    int f_count = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){  
                step_count = 0;
                floodfill(i, j);
                f_count = max(step_count, f_count);
            }
        }

    cout << f_count;
    
}