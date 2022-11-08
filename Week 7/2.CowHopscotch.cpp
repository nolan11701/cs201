#include <iostream>
using namespace std;

// define glabal variables
int maze[100][100];

int visited[100][100];

int n, m;
int step_count;

void floodfill(int x, int y) {

    if (x == n-1 && y == m-1){
        step_count++;
        return;
    }
    for (int i = x+1; i < n; i++){
        for (int j = y+1; j < m; j++){
            if (maze[x][y] != maze[i][j]){
                floodfill(i, j);
            }
        }
    }

    
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;  // RRRR -> "RRRR"

        for (int j = 0; j < m; j++) {
            if (line[j] == 'R')
                maze[i][j] = 0;
            else
                maze[i][j] = 1;
        }
    }

    floodfill(0,0);
    cout << step_count;
}