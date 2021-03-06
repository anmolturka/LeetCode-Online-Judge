// 376. Wiggle Subsequence
// https://leetcode.com/problems/wiggle-subsequence/
// https://leetcode.com/articles/wiggle-subsequence/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/51893/two-solutions-one-is-dp-the-other-is-greedy-8-lines
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.size() <= 1) return (int)nums.size();
		int Up = 1, Down = 1;
		for (size_t i = 1; i < nums.size(); i++) {
			if (nums[i - 1] < nums[i]) Up = Down + 1;
			if (nums[i - 1] > nums[i]) Down = Up + 1;
		}
		return max(Down, Up);
	}
};
// END: https://discuss.leetcode.com/topic/51893/two-solutions-one-is-dp-the-other-is-greedy-8-lines
// class Solution {
// public:
// 	int wiggleMaxLength(vector<int>& nums) {
// 		if (nums.size() <= 1) return (int)nums.size();
// 		vector<int> Up(nums.size(), 1);
// 		vector<int> Down(nums.size(), 1);
// 		int result = 0;
// 		for (size_t i = 1; i < nums.size(); i++) {
// 			for (size_t j = 0; j < i; ++j) {
// 				if (nums[j] < nums[i]) Down[i] = max(Down[i], 1 + Up[j]);
// 				if (nums[j] > nums[i]) Up[i] = max(Up[i], 1 + Down[j]);
// 			}
// 			result = max(result, Down[i]);
// 			result = max(result, Up[i]);
// 		}
// 		return result;
// 	}
// };
int main(void) {
	Solution solution;
	vector<int> nums = {1,7,4,9,2,5};
	cout << solution.wiggleMaxLength(nums) << "\tPassed\n";
	nums = {1,17,5,10,13,15,10,5,16,8};
	cout << solution.wiggleMaxLength(nums) << "\tPassed\n";
	nums = {1,2,3,4,5,6,7,8,9};
	cout << solution.wiggleMaxLength(nums) << "\tPassed\n";
	nums = {84};
	cout << solution.wiggleMaxLength(nums) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}