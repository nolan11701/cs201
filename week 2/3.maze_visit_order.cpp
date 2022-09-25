#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > maze;
vector<vector<int> > visited;
int n, m;
int filled = 0;

bool CanFill(int rowNew, int colNew) {
    if (rowNew < 0 || rowNew >= n) {
        return false;
    }
    if (colNew < 0 || colNew >= m) {
        return false;
    }
    if (visited[rowNew][colNew]) {
        return false;
    }
    if (maze[rowNew][colNew]) {
        return false;
    }
    return true;
}

void fillMaze(int row, int col) {
    if (!CanFill(row, col)) {
        return;
    } else {
        filled++;
        visited[row][col] = filled;
        fillMaze(row-1, col);
        fillMaze(row, col-1);
        fillMaze(row, col + 1);
        fillMaze(row + 1, col);
    }
}

int main() {
    cin >> n >> m;
    int x = 0;
    int y = 0;
    // assign m to maze, v to visited
    int v;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        vector<int> row_v;
        for (int k = 0; k < m; k++) {
            cin >> v;
            row.push_back(v);
            row_v.push_back(0);
        }

        maze.push_back(row);
        visited.push_back(row_v);
    }

    fillMaze(x, y);

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cout << visited[i][k] << " ";
        }
        cout << "\n";
    }
}
