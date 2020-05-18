#include <string>
#include <iostream>
std::string roman(int num) {
  std::string ret;
  //Check largest value to smallest value:
  while (num) {
    if (num >= 1000) {
      ret += 'M';
      num -= 1000;
    } else if(num >= 900) {
      ret += "CM";
      num -= 900;
    } else if(num >= 500) {
      ret += "D";
      num -= 500;
    } else if(num >= 400) {
      ret += "CD";
      num -= 400;
    } else if(num >= 100) {
      ret += "C";
      num -= 100;
    } else if(num >= 90) {
      ret += "XC";
      num -= 90;
    } else if(num >= 50) {
      ret += "L";
      num -= 50;
    } else if(num >= 40) {
      ret += "XL";
      num -= 40;
    } else if(num >= 10) {
      ret += "X";
      num -= 10;
    } else if(num >= 9) {
      ret += "IX";
      num -= 9;
    } else if(num >= 5) {
      ret += "V";
      num -= 5;
    } else if(num >= 4) {
      ret += "IV";
      num -= 4;
    } else {
      ret += "I";
      num--;
    }
  }
  return ret;
}


int main() {
  int A = 1994;
  std::cout << roman(A) << std::endl;
  return  0;
}


/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/