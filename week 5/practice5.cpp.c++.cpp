#include<iostream>
using namespace std;

// define glabal variables
int maze[5][5] = { {0,0,0,0,0 },
                   {0,1,1,1,0 },
                   {0,1,0,0,0 },
                   {0,1,0,1,0 },
                   {0,0,0,1,0 } };

int visited[5][5] =  { {0,0,0,0,0 },
                     {0,0,0,0,0 },
                     {0,0,0,0,0 },
                     {0,0,0,0,0 },
                     {0,0,0,0,0 } };

bool found_path = false;
int n = 4;

bool floodfill(int x, int y)
{
    if (!isValid(x, y))
        return false;  
    if ((x == n) && (y == n)) // reach end point
        return true;
  
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (floodfill(nx, ny))
        return true;
    }
    return false;
}

int main() {
    floodfill(0, 0);
    if (found_path)
        cout << "YES";
    else
        cout << "NO";
}