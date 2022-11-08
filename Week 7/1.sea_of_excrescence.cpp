#include <iostream>
using namespace std;

// define glabal variables
int maze[100][100];

int visited[100][100];

int n, m;
int step_count;

void floodfill(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n || visited[x][y]==1 || maze[x][y] == 0)
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
        string line; 
        cin >> line;
        for (int j =0; j<m; j++) {
            maze[i][j] = (int)line[j]-'0';
        }
    }
    int f_count = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){   
            if (maze[i][j] != 0 && visited[i][j] == 0) {
                step_count = 0;
                floodfill(i, j);
                f_count = max(step_count, f_count);
            }
        }
    }

    cout << f_count;
    
}