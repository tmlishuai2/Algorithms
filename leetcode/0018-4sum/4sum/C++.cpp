#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> answer;
		int n = nums.size();
		if (n < 4)return answer;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
			if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue;
			for (int j = i + 1; j < n - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
				if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) continue;
				int left = j + 1, right = n - 1;
				while (left < right) {
					int sum = nums[i] + nums[j] + nums[left] + nums[right];
					if (sum < target) left++;
					else if (sum > target) right--;
					else {
						answer.push_back({ nums[i],nums[j],nums[left],nums[right] });
						do { left++; } while (nums[left] == nums[left - 1] && left < right);
						do { right--; } while (nums[right] == nums[right + 1] && left < right);
					}
				}
			}
		}
		return answer;
		
	}
};

int main() {
	vector<vector<int>> answer;
	vector<int> nums = { 1,0,-1,0,-2,2 };
	int target = 0;
	Solution sol;
	answer = sol.fourSum(nums, target);
	return 0;
}