#include <iostream>
#include <string>
#include <cmath>

int solution (int x) {
  int ret = 0;
  
  while (abs(x) >= 1) {
    ret = ret * 10 + (x % 10);
    x /= 10;
  if(214748364<ret || -214748364 > ret)
    return 0;
  }
  return ret;
}

int main(){
  int testA = 100;
  int testB = -225;
    std::cout << solution(testA) << std::endl;
    std::cout << solution(testB) << std::endl;

  return 0;
}