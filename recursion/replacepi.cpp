#include<iostream>
#include<string.h>
using namespace std;
// Change in the given string itself. So no need to return or print anything
void replacePi(char input[]) {
	// Write your code here
	if(strlen(input) <= 1) return;
    
    replacePi(input+1);
    if(input[0]=='p' && input[1]=='i') {
      for (int i = strlen(input) - 1; i >= 2;i--) {
        input[i + 2] = input[i];
      }
      input[0] = '3';
      input[1] = '.';
      input[2] = '1';
      input[3] = '4';

    } else {
      return;
    }
}




int main(int argc, char const *argv[])
{
  char input[] = "xpix";
  replacePi(input);
  puts(input);
  return 0;
}
