#include<iostream>
#include <string>
using namespace std;

string phonepad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num <= 1) return 1;
    int n = num % 10;
    int shorterSize = keypad(num / 10, output);
    int copies = phonepad[num%10].size() - 1;



    for (int i = 1; i < phonepad[n].size();i++) {
      for (int j = 0; j < shorterSize;j++) {
        output[j + i * shorterSize] = output[j] + phonepad[n][i];
      }
    }

    for (int i = 0; i < shorterSize;i++) {
      output[i] += phonepad[n][0];
    }

    return shorterSize * phonepad[n].size();
}

int main(int argc, char const *argv[])
{
  string *s = new string[1000];
  int num = 356;
  int size = keypad(num, s);
  for (int i = 0; i < size;i++) {
    cout << s[i] << endl;
  }
    return 0;
}
