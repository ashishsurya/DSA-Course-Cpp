#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board(11, vector<int>(11, 0));

bool isPossible(int n, int row, int column)
{
  // CHECK FOR THE ENTIRE COLUMN
  for (int i = row; i >= 0; i--)
  {
    if (board[i][column] == 1)
    {
      return false;
    }
  }

  // CHECK UPPER LEFT DIAGNOL
  for (int i = row, j = column; i >= 0 && j >= 0; i--, j--)
  {
    if (board[i][j] == 1)
    {
      return false;
    }
  }

  for (int i = row, j = column; i >= 0 && j <= n; i--, j++)
  {
    if (board[i][j] == 1)
    {
      return false;
    }
  }

  return true;
}

void nQueenHelper(int n, int row)
{
  if (row >= n)
  {
    // PRINT THE CURRENT BOARD AND RETURN
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cout << board[i][j] << " ";
      }
    }
    cout << endl;
    return;
  }

  for (int j = 0; j < n; j++)
  {
    if (isPossible(n, row, j))
    {
      board[row][j] = 1;
      nQueenHelper(n, row + 1);
      // AFTER BACKTRACKING
      board[row][j] = 0;
    }
  }

  return;
}

void placeNQueens(int n)
{
  nQueenHelper(n, 0);
}

int main()
{
  int n;
  cin >> n;
  placeNQueens(n);
  return 0;
}
