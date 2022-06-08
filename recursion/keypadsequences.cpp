#include <iostream>
#include <string>
using namespace std;

string phonepad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void helper(int num, string output) {
    if(num == 0) {
        cout << output << endl; 
        return;
    }
    int x = num % 10;
    for(int i=0;i<phonepad[x].size();i++) {
        helper(num / 10, phonepad[x][i] + output);
    }
}


void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string s = "";
    helper(num, s);

}

int main(int argc, char const *argv[])
{
  int num = 23;
  printKeypad(23);
  return 0;
}
