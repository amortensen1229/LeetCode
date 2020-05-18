#include <string>
#include <iostream>

int roman(std::string num) {
  int ret = 0;
  for (int i = 0; i < num.size(); ++i) {
    if (num[i] == 'I' && (num[i+1] == 'X' || num[i+1] == 'V')){
      ret--;
    } else if (num[i] == 'I') {
      ret++;
    }
    if (num[i] == 'V') ret += 5;
    if (num[i] == 'X' && (num[i+1] == 'L' || num[i+1] == 'C')) {
      ret -= 10;
    } else if (num[i] == 'X'){
      ret += 10;
    } 

    if (num[i] == 'L') ret += 50;
    if (num[i] == 'C' && (num[i+1] == 'D' || num[i+1] == 'M')) {
      ret -= 100;
    } else if (num[i] == 'C') {
      ret += 100;
    } 
    if (num[i] == 'D') ret += 500;
    if (num[i] == 'M') ret += 1000;  
  }
  return ret;
}


int main() {
  
}