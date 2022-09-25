
#include <iostream>

using namespace std;

int maze[4][4] = {{0,0,0,1 }, // initialize 2d array
                {1,1,0,0 },
                {0,1,0,1 },
                {0,0,1,0 } };
                
int visited[4][4] = {{0,0,0,0 }, // initialize visited array
                    {0,0,0,0 },
                    {0,0,0,0 },
                    {0,0,0,0 }};
                    
int dirx[4] = { 1, -1, 0, 0 }; // easy way to check neighbors
int diry[4] = { 0, 0, 1, -1 };
int filled = 0;

bool CanFill(int rowNew, int colNew)
{
    if (rowNew < 0 || rowNew >= 4){
        return false;
    }   
    if (colNew < 0 || colNew >= 4){
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
    // mark visited, increase filled number
    // check all neighbors, if can be filled, call function recursively
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
    fillMaze(0, 2); // start to fill
    cout << filled << endl;
}



