#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> answer;
		sort(nums.begin(), nums.end());
		if (nums.size() < 3) return {  };
		for (int i = 0; i < nums.size() - 2;) {
			int j = i + 1;
			int k = nums.size() - 1;
			while (j < k) {
				if (nums[i] + nums[j] + nums[k] < 0) {
					while (nums[j + 1] == nums[j]) j = j + 1;
					j = j + 1;
				}
				else if (nums[i] + nums[j] + nums[k] > 0) {
					while (nums[k - 1] == nums[k]) k = k - 1;
					k = k - 1;
				}
				else {
					answer.push_back({ nums[i],nums[j],nums[k] });
					while (nums[j + 1] == nums[j]) j = j + 1;
					j = j + 1;
					while (nums[k - 1] == nums[k]) k = k - 1;
					k = k - 1;
				}
			}
			while (nums[i + 1] == nums[i]) i = i + 1;
			i = i + 1;
		}
		return answer;
	}

};

int main() {
	Solution sol;
	vector<vector<int>> answer;
	vector<int> nums = {  };
	answer = sol.threeSum(nums);
	return 0;
}