// https://leetcode.cn/problems/two-sum/

#include <cstdio>
#include <vector>

class Solution {
 public:
  void twoSum(std::vector<int>& nums, int target) {
    for (int i = 0; i <= nums.size(); i++) {
      printf("%d ", i);
    }
    printf("\n");
  }
};

int main() {
  printf("hello\n");
  printf("hello\n");
  std::vector<int> a;
  for (int i = 0; i < 5; i++) {
    a.push_back(i);
  }

  Solution().twoSum(a, 5);
}
