#include <iostream>

#define N 9

using namespace std;

bool findEmptyPosition(int grid[N][N], int &row, int &col)
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (grid[i][j] == 0)
      {
        row = i;
        col = j;
        return true;
      }
    }
  }

  return false;
}

bool isSafeInRow(int grid[N][N], int row, int num)
{
  for (int i = 0; i < N; i++)
  {
    if (grid[row][i] == num)
    {
      return false;
    }
  }

  return true;
}

bool isSafeInCol(int grid[N][N], int col, int num)
{
  for (int i = 0; i < N; i++)
  {
    if (grid[i][col] == num)
    {
      return false;
    }
  }

  return true;
}

bool isSafeInGrid(int grid[N][N], int row, int col, int num)
{
  int rowFactor = row - (row % 3);
  int colFactor = col - (col % 3);

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (grid[i + rowFactor][j + colFactor] == num)
      {
        return false;
      }
    }
  }
  return true;
}

bool isSafe(int grid[N][N], int row, int col, int num)
{

  return isSafeInRow(grid, row, num) && isSafeInCol(grid, col, num) && isSafeInGrid(grid, row, col, num);
}

bool solveSudoku(int grid[N][N])
{
  // cout << "started" << endl;
  // find the empty position
  int row, col;
  if (!findEmptyPosition(grid, row, col))
  {
    return true;
  }

  // cout << row << " " << col << endl;

  // now from 1 to 9 check all possibilties
  for (int i = 1; i <= N; i++)
  {
    if (isSafe(grid, row, col, i))
    {
      grid[row][col] = i;
      if (solveSudoku(grid))
      {
        return true;
      }
      grid[row][col] = 0;
    }
  }
  return false;
}

int main()
{

  int grid[N][N];

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> grid[i][j];
    }
  }

  if(solveSudoku(grid)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  return 0;
}
