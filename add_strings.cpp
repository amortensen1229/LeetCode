#include <iostream>
#include <string>
#include <cmath>
#include <list>
std::string addStrings(const std::string& num1, const std::string& num2) {
  //hold sizes:
  int i = num1.size()-1;
  int j = num2.size()-1;
  int carry = 0; //using carry variable
  std::string ret;
  //while not at begining of numbers and carry not equal zero
  while (i >= 0 || j >= 0 || carry) { 

    int sum = 0;
    sum += carry;

    if (i >= 0) {
      sum += (num1[i] - 48); 
    }

    if (j >= 0) {
      sum += (num2[j] - 48);
    }
    carry = sum / 10;
    sum = sum % 10;
    ret.push_back(sum + 48);
    --i;
    --j;
  }
  std::reverse(ret.begin(), ret.end());
  return ret;
}





int main() {
  std::string a = "55";
  std::string b = "45";
  std::string ret = addStrings(a,b);
  std::cout << "Output: " << ret << std::endl;
  return 0;
}