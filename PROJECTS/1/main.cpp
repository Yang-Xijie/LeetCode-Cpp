// https://leetcode.cn/problems/two-sum/
// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值
// target  的那两个整数，并返回它们的数组下标。

#include <cstdio>
#include <cstdlib>
#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    for (unsigned long i = 0; i < nums.size(); i++) {
      for (unsigned long j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          std::vector<int> result;
          result.push_back(i);
          result.push_back(j);
          return result;
        }
      }
    }
    printf("[ERROR] unreachable\n");
    abort();
  }
};

int main() {
  printf("[TRACE] START\n");

  std::vector<int> nums = {3, 2, 4};
  int target = 6;

  std::vector<int> result = Solution().twoSum(nums, target);
  for (unsigned long i = 0; i < result.size(); i++) {
    printf("%d ", result[i]);
  }
  printf("\n");

  printf("[TRACE] END\n");
}
