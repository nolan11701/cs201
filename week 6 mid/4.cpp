#include <iostream>
using namespace std;

// define glabal variables
int maze[10][10];

int visited[10][10];

int num[10][10];

bool found_path = false;
int n;
int m;
int t;
int x1, y1;
int x2, y2;
int c;
int best_path = 0;
void floodfill(int x, int y, int step_count) {
    if (x < 0 || y < 0 || x >= n || y >= m || visited[x][y] || maze[x][y] == 1){
        return;
    } else if ((x == x2 ) && (y == y2))  // reach end point
    {
        found_path = true;
        c++;
        best_path = max(best_path, step_count);
        return;
    }
    
    visited[x][y] = 1;
    step_count += num[x][y];
    floodfill(x + 1, y, step_count);
    floodfill(x - 1, y, step_count);
    floodfill(x, y + 1, step_count);
    floodfill(x, y - 1, step_count);
    visited[x][y] = 0;
    step_count -= num[x][y];
    
}


int main() {
    cin >> n >> m >> t;
    x1 = 0;
    y1 = 0;
    x2 = n-1;
    y2 = m-1;

    for (int i=0;i<n;i++){
        string line; 
        cin >> line;
        for (int j = 0; j < m; j++) {

            if (line[j]=='.'){
                maze[i][j] = 0;

            } else if (line[j]=='*'){
                maze[i][j] = 1;
            }  
        }   
        
    }
    cin >> x1 >> y1 >> x2 >> y2;
    

    floodfill(0, 0, 0);
    if (found_path){
        cout << best_path;
    } else {
        cout << -1;
    }
}