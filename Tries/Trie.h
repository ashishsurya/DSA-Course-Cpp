#include "TrieNode.h"

#include <string>

#include<vector>

using namespace std;
class Trie
{

  TrieNode *root;

public:
  Trie()
  {
    root = new TrieNode('\0');
  }

  void insertWord(TrieNode *root, string word)
  {
    // HELPER FUNCTION
    if (word.size() == 0)
    {
      root->isTerminal = true;
      return;
    }

    int index = word[0] - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }
    else
    {
      child = new TrieNode(word[0]);
      root->children[index] = child;
    }

    // RECURSIVE CALL
    insertWord(child, word.substr(1));
  }

  // FOR USER
  void insertWord(string word)
  {
    insertWord(root, word);
  }

  bool search(TrieNode *root, string word)
  {
    // HELPER FUNCTION
    if (word.size() == 0)
    {
      return root->isTerminal;
    }

    int index = word[0] - 'a';
    if (root->children[index] != NULL)
    {
      return search(root->children[index], word.substr(1));
    }
    else
    {
      return false;
    }
  }

  // FOR USER
  bool search(string word)
  {
    // Write your code here
    return search(root, word);
  }

  void remove(TrieNode *root, string word)
  {
    if (word.size() == 0)
    {
      root->isTerminal = false;
      return;
    }

    int index = word[0] - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }
    else
    {
      return;
    }
    remove(child, word.substr(1));

    // REMOVE CHILD NODE IF IT IS USELESS
    if (child->isTerminal == false)
    {
      for (int i = 0; i < 26; i++)
      {
        if (child->children[i] != NULL)
        {
          return;
        }
      }
      delete child;
      root->children[index] = NULL;
    }
  }

  // FOR USER
  void remove(string word)
  {
    return remove(root, word);
  }

  bool patternMatching(TrieNode *root, string pattern)
  {
    if (pattern == "")
      return true;

    int index = pattern[0] - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }
    else
    {
      return false;
    }
    return patternMatching(child, pattern.substr(1));
  }

  bool patternMatching(vector<string> vect, string pattern)
  {
    // Write your code here
    for (int i = 0; i < vect.size(); i++)
    {
      for (int j = 0; j < vect[i].size(); j++)
      {
        insertWord(vect[i].substr(j));
      }
    }

    return patternMatching(root, pattern);
  }
};