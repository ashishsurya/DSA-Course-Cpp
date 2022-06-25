#include <bits/stdc++.h>
using namespace std;

bool isValidVertical(char crossword[10][10], string word, int row, int col)
{
  if (10 - row < word.size())
    return false;

  for (int i = 0; i < word.size(); i++)
  {
    if (crossword[i + row][col] == '-' || crossword[i + row][col] == word[i])
    {
      continue;
    }
    else
    {
      return false;
    }
  }
  return true;
}

bool isValidHorizontal(char crossword[10][10], string word, int row, int col)
{
  if (10 - col < word.size())
    return false;

  for (int i = 0; i < word.size(); i++)
  {

    if (crossword[row][i + col] == '-' || crossword[row][i + col] == word[i])
    {
      continue;
    }
    else
    {
      return false;
    }
  }

  return true;
}

vector<bool> setVertical(char crossword[10][10], string word, int row, int col)
{
  vector<bool> placed(word.size(), false);
  for (int i = 0; i < word.size(); i++)
  {
    if (crossword[i + row][col] == '-')
    {
      crossword[i + row][col] = word[i];
      placed[i] = true;
    }
  }

  return placed;
}

void resetVertical(char crossword[10][10], vector<bool> placed, int row, int col)
{
  for (int i = 0; i < placed.size(); i++)
  {
    if (placed[i])
    {
      crossword[i + row][col] = '-';
    }
  }
}

vector<bool> setHorizontal(char crossword[10][10], string word, int row, int col)
{
  vector<bool> placed(word.size(), false);

  for (int i = 0; i < word.size(); i++)
  {
    if (crossword[row][i + col] == '-')
    {
      crossword[row][i + col] = word[i];
      placed[i] = true;
    }
  }

  return placed;
}

void resetHorizontal(char crossword[10][10], vector<bool> placed, int row, int col)
{
  for (int i = 0; i < placed.size(); i++)
  {
    if (placed[i])
    {
      crossword[row][i + col] = '-';
    }
  }
}

void completeCrossWord(char crossword[10][10], vector<string> words, int index)
{
  // base case
  if (index == words.size())
  {
    for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 10; j++)
      {
        cout << crossword[i][j] << "";
      }
      cout << endl;
    }
    return;
  }

  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (crossword[i][j] == '-' || crossword[i][j] == words[index][0])
      {
        if (isValidHorizontal(crossword, words[index], i, j))
        {
          vector<bool> placed = setHorizontal(crossword, words[index], i, j);
          completeCrossWord(crossword, words, index + 1);
          resetHorizontal(crossword, placed, i, j);
        }

        if (isValidVertical(crossword, words[index], i, j))
        {
          vector<bool> placed = setVertical(crossword, words[index], i, j);
          completeCrossWord(crossword, words, index + 1);
          resetVertical(crossword, placed, i, j);
        }
      }
    }
  }

  return;
}

int main()
{

  char crossword[10][10];
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      cin >> crossword[i][j];
    }
  }

  vector<string> words;
  string input;
  cin >> input;
  string s = "";
  for (int i = 0; i < input.size(); i++)
  {
    if (input[i] == ';')
    {
      words.push_back(s);
      s = "";
    }
    else
    {
      s += input[i];
    }
  }

  words.push_back(s);

  completeCrossWord(crossword, words, 0);

  // cout << input << endl;

  // for(auto s:words) {
  //   cout << s << endl;
  // }

  return 0;
}
