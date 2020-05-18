#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
  //assuming sorted:
  std::vector<int> ret;
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = 0; j < nums.size(); ++j) {
      if (nums[i] + nums[j] == target && i !=j) {
        ret.push_back(i);
        ret.push_back(j);
        return ret;
      } else if (nums[i] + nums[j] > target) {
        break;
      }
    }
  }
}

int main() {
  return 0;
}