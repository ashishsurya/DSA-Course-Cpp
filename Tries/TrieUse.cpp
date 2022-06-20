#include<iostream>
#include "Trie.h"

using namespace std;

int main() {
  Trie T;
  T.insertWord("abc");
  T.insertWord("ashish");
  T.insertWord("and");
  T.insertWord("best");

  cout << T.search("ashish") << endl;
  cout << T.search("surya") << endl;

  T.remove("ashish");
  cout << T.search("ashish") << endl;


  return 0;
}
