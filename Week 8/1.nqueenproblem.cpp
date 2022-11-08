#include <iostream>
using namespace std;

int n;
int queen_count;

int board[100][100];

bool isconflict(int rowIndex, int colIndex){
    for (int i = 0; i < n; i++){
        if (board[rowIndex][i] != 0 || board[i][colIndex] != 0) {
            return true;
        }
    }
    int col, row;
    col = colIndex; 
    row = rowIndex;
    
    while (col < n && col >= 0 && row < n && row >= 0){
        if (board[row][col] != 0) return true;
        col++;
        row++;
    }

    col = colIndex; 
    row = rowIndex;
    
    while (col < n && col >= 0 && row < n && row >= 0){
        if (board[row][col] != 0) return true;
        col--;
        row++;
    }

    col = colIndex; 
    row = rowIndex;
    
    while (col < n && col >= 0 && row < n && row >= 0){
        if (board[row][col] != 0) return true;
        col++;
        row--;
    }

    col = colIndex; 
    row = rowIndex;
    
    while (col < n && col >= 0 && row < n && row >= 0){
        if (board[row][col] != 0) return true;
        col--;
        row--;
    }

    return false;
}

void nqueen(int row){
    if (row == n) {
        queen_count++;
        return;
    }

    for (int col = 0; col < n; col++){
        if (!isconflict(row, col)) {
            board[row][col] = 1;
            nqueen(row+1);
            board[row][col] = 0;
        }
    }
}

int main(){
    cin >> n;
    nqueen(0);
    cout << queen_count;
}