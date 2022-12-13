#include <iostream>
#include <vector>

using namespace std;
int n;

vector <vector<int> > maze;
vector <vector<int> > visited;

int filled = 0;

bool CanFill(int rowNew, int colNew)
{
    if (rowNew < 0 || rowNew >= n){
        return false;
    }   
    if (colNew < 0 || colNew >= n){
        return false;
    }   
    if (visited[rowNew][colNew]){
        return false;
    }
    if (maze[rowNew][colNew]){
        return false;
    }
    return true;
}
       
void fillMaze(int row, int col)
{
    if (!CanFill(row, col)){
        return   ;
    } else {
        visited[row][col] = 1;
        filled ++;
        fillMaze(row+1, col);
        fillMaze(row-1, col);
        fillMaze(row, col+1);
        fillMaze(row, col-1);
    }
    
}

int main() {

    cin >>n;
    int x, y;

    // assign m to maze, v to visited 
    string v;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        vector<int> row_v;

        cin >> v;

        for (int k = 0; k < n; k++) {
          
            if (v[k]=='_'){
                row.push_back(0);
            } else if (v[k]=='-'){
                row.push_back(1);
            } else if (v[k]=='*'){
                row.push_back(0);
                x = i;
                y = k;
            }
            row_v.push_back(0);
        }
        maze.push_back(row);

        visited.push_back(row_v);
    }
 
    fillMaze(x,y);

    cout << filled;

}
