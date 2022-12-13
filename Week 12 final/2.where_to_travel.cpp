#include <iostream>
#include <vector>

using namespace std;
int n;

vector<vector<int> > maze;
vector<vector<int> > visited;

int best_path = 999;
int best_path_type;
bool found_path = false;

bool CanFill(int rowNew, int colNew) {
    if (rowNew < 0 || rowNew >= n) {
        return false;
    }
    if (colNew < 0 || colNew >= n) {
        return false;
    }
    if (visited[rowNew][colNew]) {
        return false;
    }
    if (maze[rowNew][colNew]==1) {
        return false;
    }
    return true;
}

void fillMaze(int row, int col, int step_count) {
    if (!CanFill(row, col)) {
        return;
    }    

    // cout << row << " " << col << " " << maze[row][col] << "\n"; 

    if (maze[row][col] == 3 || maze[row][col] == 4)  // reach end point
    {
        //cout << row << " " << col << " " << step_count << " " << best_path << "\n";

        found_path = true;
        best_path_type = maze[row][col];
        if (step_count < best_path) {
            best_path = step_count;
            best_path_type = maze[row][col];
        } else if (step_count == best_path) {
            best_path_type = 5;
        }
        return;
    }

    visited[row][col] = 1;
    step_count++;
    fillMaze(row + 1, col, step_count);
    fillMaze(row - 1, col, step_count);
    fillMaze(row, col + 1, step_count);
    fillMaze(row, col - 1, step_count);
    visited[row][col] = 0;
    step_count--;
}

int main() {
    cin >> n;
    int x, y;

    // assign m to maze, v to visited

    for (int i = 0; i < n; i++) {
        vector<int> row;
        vector<int> row_v;

        for (int j = 0; j < n; j++) {
            string v;
            cin >> v;
            if (v == ".") {
                row.push_back(0);
            } else if (v == "X") {
                row.push_back(1);
            } else if (v == "@") {
                row.push_back(0);
                x = i;
                y = j;
            } else if (v == "M") {
                row.push_back(3);
            } else if (v == "B") {
                row.push_back(4);
            }
            row_v.push_back(0);
        }
        maze.push_back(row);

        visited.push_back(row_v);
    }


    // for (int i=0;i < n; i++){
    //     for (int j=0; j<n; j++){
    //         cout << maze[i][j];
    //     }
    //     cout << "\n";
    // }
    fillMaze(x, y, 0);

    if (best_path_type == 3) {
        cout << "Mountains " << best_path;
    } else if (best_path_type == 4) {
        cout << "Beach " << best_path;
    } else {
        cout << "Either " << best_path;
    }

}
