/*
  Note:
  To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
  This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y),
  down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include <iostream>
#include <vector>

using namespace std;


void ratinmaze(vector<vector<int> > maze,vector<vector<int> > visited,int n ,int row,int column) {


  if(row == n-1 && column == n-1) {
    visited[row][column] = 1;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cout << visited[i][j] << " ";
      }
    }
    cout << endl;
  }

  if (row>=n || row < 0 || column >= n || column < 0 || maze[row][column] == 0 || visited[row][column] == 1) {
    return;
  }

  visited[row][column] = 1;
  ratinmaze(maze, visited,n, row - 1, column);
  ratinmaze(maze, visited,n, row + 1, column);
  ratinmaze(maze, visited,n, row , column-1);
  ratinmaze(maze, visited,n, row, column+1);
  visited[row][column] = 0;
}

int main()
{

  // Write your code here

  int n;
  cin >> n;
  vector<vector<int> > maze(n , vector<int>(n,0));
  vector<vector<int> > visited(n, vector<int>(n, 0));

  //  TAKE INPUT
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> maze[i][j];
    }
  }

  

  ratinmaze(maze, visited, n, 0, 0);

  return 0;
}
