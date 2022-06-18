#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
/*
   
*/

int main() {
  unordered_map<string, int> map;
  map["abc"] = 1;
  map["def"] = 2;
  map["ghi"] = 3;

  unordered_map<string, int>::iterator it = map.begin();
  while(it!=map.end()){
    cout << it->first << "-->" << it->second << endl;
    it++;
  }

  return 0;
}
