#include<iostream>
using namespace std;

// char maze[21][21];
// int visited[21][21];
// int n, m, startX, startY;
                    
// int Path_Row[4] = {1,-1,0,0};
// int Path_Col[4] = {0,0,1,-1};
// int now_count = 0;

// bool CanWeMove(int rowNew, int colNew)
// {
//     if (rowNew < 0 || rowNew >= n){
//         return false;
//     }   
//     if (colNew < 0 || colNew >= m){
//         return false;
//     }   
//     if (visited[rowNew][colNew]){
//         return false;
//     }
//     if (maze[rowNew][colNew]){
//         return false;
//     }
//     return true;
// }
       
// void FindPathInMaze(int row, int col)
// {
//     if (!CanFill(row, col)){
//         return   ;
//     } else {
//         visited[row][col] = 1;
//         filled ++;
//         FindPathInMaze(row+1, col);
//         FindPathInMaze(row-1, col);
//         FindPathInMaze(row, col+1);
//         FindPathInMaze(row, col-1);
//     }
// }

// int main() {
//     while (true) {
//         cin >> m >> n; // note read m first
//         if (m == 0)
//             break;
            
//         for (int i = 0; i < n; i++) 
//             for(int j = 0; j < m; j++) // check starting point
//             {
//                 cin >> maze[i][j];
//                 if (maze[i][j] == '@'){
//                     startX = i;
//                     startY = j;
//                 }
//             }
// 		// reset variables
// 		memset(visited, 0, sizeof(visited));
//         now_count = 0;            
//         FindPathInMaze(startX, startY);
//         cout << now_count;
//     }
// }
int visited[100][100];
int path = 0;
void knightsTour(int x, int y, int steps){
    visited[x][y] = steps;
    if (steps == 25){
        path++;
        visited[x][y] = 0
        return;
    }
}