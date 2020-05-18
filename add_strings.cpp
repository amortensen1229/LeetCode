#include <iostream>
#include <string>
#include <cmath>
#include <list>
/*
"551"
"349"
*/
std::string addStrings(const std::string& num1, const std::string& num2) {
  int i = num1.size()-1;
  int j = num2.size()-1;
  int carry = 0;
  std::string ret;
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
/*
"9333852702227987"
"85731737104263"
*/




/*
  //must use list addition:
  std::list<int> n1;
  std::list<int> n2;

  for (int i = 0; i < num1.size(); ++i) {
    n1.push_back(num1[i]-48);
  }
  for (int i = 0; i < num2.size(); ++i) {
    n2.push_back(num2[i]-48);
  }
  std::list<int>::iterator itr1 = n2.end();
  std::list<int>::iterator itr2 = n1.end();
  itr1--;
  itr2--;
  std::string ret;
  char aChar;
  while (itr2 != n2.begin() && itr1 != n1.begin()) {
    if (*itr2 + *itr1 >= 10) {
      int temp = (*itr2 + *itr1) % 10; 
      ret += temp;
      if (itr2++ != n2.begin() && itr1++ != n1.begin()){ //both have a next
        itr2--;
        *itr2++;
        itr2++;

      } else if (itr1++ != n2.begin()) { //only n1 has next
        itr1--;
        *itr1++;
        itr1++;
      } else if (itr2++ != n1.begin()) {
        itr2--;
        *itr2++;
        itr2++;
      } else {
        n2.push_back(1);
      }
    } else {
      int temp = (*itr2 + *itr1);
      ret += temp;
    }
    itr1--;
    itr2--;
  }
  return ret;
}

*/
  /*




  char temp;
  unsigned long long int first = 0;
  unsigned long long int second = 0;

  for (int i = 0; i < num1.size(); ++i) {
    temp = num1[i];
    first += (temp - 48) * (unsigned long long int)(pow(10, (num1.size() - 1) - i));

  } 
  for (int i = 0; i < num2.size(); ++i) {
    temp = num2[i];
    second += (temp - 48) * (unsigned long long int)(pow(10, ((num2.size() - 1) - i)));
  }
  unsigned long long int result = first + second; 
  std::cout << "First: " << first << std::endl;
  std::cout << "Second: " << second << std::endl;
  
  //Now convert to string:
  int size = 0;
  unsigned long long int result2 = result;
  char aChar;
  if (result == 0) {
    size++;
  } else {
    while (result >= 1) {
      size++;
      result /= 10;
    }
  }
  std::string ret(size,' ');
  for (int i = 0; i < size; ++i) {
    aChar = '0' + (result2 % 10);
    ret[size-1-i] = aChar;
    result2 /= 10;
  }
  return ret;
}
*/