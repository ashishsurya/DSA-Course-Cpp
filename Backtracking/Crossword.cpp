#include <bits/stdc++.h>
using namespace std;

void completeCrossWord(char crossword[10][10], vector<string> words, int index)
{
  // base case
  if (index >= words.size())
  {
    for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 10; j++)
      {
        cout << crossword[i][j] << " ";
      }
      cout << endl;
    }
    return;
  }

  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10;j++) {

    }
  }
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

  completeCrossWord(crossword, words, 0);

  return 0;
}
