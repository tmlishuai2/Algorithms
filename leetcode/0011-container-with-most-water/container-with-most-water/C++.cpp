#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int left, right, answer;
		left = 0;
		right = height.size()-1;
		answer = 0;
		while (left < right) {
			if (answer < (right - left)*min(height[left], height[right]))
				answer = (right - left)*min(height[left], height[right]);
			if (height[left] < height[right]) left++;
			else right--;

		}
		return answer;
	}
};

int main() {
	vector<int> height = { 1,1 };
	int answer;
	Solution sol;
	answer = sol.maxArea(height);
	return 0;
}