#include<iostream>
#include<string.h>
using namespace std;

void removeX(char s[]) {
    // Write your code here
	  if (strlen(s) == 0) {
        return;
    }
    removeX(s+1);
    if(s[0] == 'x') {
      for (int i = 0; i < strlen(s) - 1;i++) {
        s[i] = s[i+1];
      }
      s[strlen(s) - 1] = '\0';
    } else {
        return;
    }
}

int main(int argc, char const *argv[])
{
  char s[] = "xaxb";
  removeX(s);
  puts(s);
  return 0;
}

