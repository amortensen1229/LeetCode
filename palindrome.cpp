#include <iostream>
#include <string>

bool isPalindrome(int x) {
  // Definition of palindromes: 
  // the 'inverted' number will be of 
  // the same value as the proper number...
  long int copy = x;
  long int ret = 0;
  while (copy > 0) {
    ret *= 10;
    ret += copy % 10; //get last value;
    copy /= 10; //pop last value;
  }
  if (ret == x) {
    return true;
  } else {
    return false;
  }
}




int main() {
  std::cout << isPalindrome(55) << std::endl;
  return 0;
}


  /* 
  ---- String Conversion method: -----

  std::string palin = std::to_string(x);
  for (int i = 0; i < palin.size()/2; ++i) {
    if (palin[i] != palin[(palin.size()-1) - i]) {
      return false;
    }
  }
  return true;
  */