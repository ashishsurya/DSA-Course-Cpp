// WRONG CODE ...❌❌❌❌❌❌❌

#include <vector>
#include <string>
using namespace std;

bool dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, string word, int n, int m, int x, int y)
{
  if (!(x >= 0 && x < n && y >= 0 && y < m))
    return false;
  // BASE CASE..
  if (word == "")
    return true;

  visited[x][y] = true;

  bool ans1, ans2, ans3, ans4, ans5, ans6, ans7, ans8;

  // checking for all possibilties.

  if (!visited[x - 1][y - 1] && board[x - 1][y - 1] == word[0])
    ans1 = dfs(board, visited, word.substr(1), n, m, x - 1, y - 1);

  if (!visited[x - 1][y] && board[x - 1][y] == word[0])
    ans2 = dfs(board, visited, word.substr(1), n, m, x - 1, y);
  if (!visited[x - 1][y + 1] && board[x - 1][y + 1] == word[0])
    ans3 = dfs(board, visited, word.substr(1), n, m, x - 1, y + 1);

  if (!visited[x][y - 1] && board[x][y - 1] == word[0])
    ans4 = dfs(board, visited, word.substr(1), n, m, x, y - 1);

  if (!visited[x - 1][y + 1] && board[x - 1][y + 1] == word[0])
    ans5 = dfs(board, visited, word.substr(1), n, m, x, y + 1);

  if (!visited[x + 1][y - 1] && board[x + 1][y - 1] == word[0])
    ans6 = dfs(board, visited, word.substr(1), n, m, x + 1, y - 1);

  if (!visited[x + 1][y] && board[x + 1][y] == word[0])
    ans7 = dfs(board, visited, word.substr(1), n, m, x + 1, y);

  if (!visited[x + 1][y + 1] && board[x + 1][y + 1] == word[0])
    ans8 = dfs(board, visited, word.substr(1), n, m, x + 1, y + 1);

  if (ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8)
  {
    return true;
  }

  return false;
}

bool hasPath(vector<vector<char>> &board, int n, int m)
{
  // Write your code here.
  string word = "CODINGNINJA";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      vector<vector<bool>> visited(n, vector<bool>(m, false));
      if (board[i][j] == 'C')
      {
        if (dfs(board, visited, word.substr(1), n, m, i, j))
        {
          return true;
        }
        else
        {
          continue;
        }
      }
    }
  }

  return false;
}