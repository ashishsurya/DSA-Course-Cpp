#include<iostream>
#include<string.h>
using namespace std;
// Change in the given string itself. So no need to return or print the changed string.
void pairStar(char input[]) {
  // Write your code here
  if(strlen(input) == 1) {
        return;
    }
    pairStar(input+1);
    if(input[0]==input[1]) {
      for(int i=strlen(input)-1;i>=1;i--) {
            input[i+1] = input[i];
        }
        input[1] = '*';
  cout << input << endl;

    } else {
  cout << input << endl;

        return;
    }
}



int main(int argc, char const *argv[])
{
  char s[] = "aaaaa";
  // puts(s);
  pairStar(s);
  for(char c:s) {
    // cout << c << endl;
  }
  // cout << s << endl;
  return 0;
}

