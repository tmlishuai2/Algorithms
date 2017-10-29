#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <list>
using namespace std;

//纯遍历操作O(n^3)
class Solution_goover {
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

//利用自制哈希表来做可能是O（n^2），但与hash函数关系很大

class Quadruplets :public vector<int> {
public:
	Quadruplets(vector<int> v) {
		this->push_back(v[0]);
		this->push_back(v[1]);
		this->push_back(v[2]);
		this->push_back(v[3]);
	}
	Quadruplets(int a, int b, int c, int d) {
		this->push_back(a);
		this->push_back(b);
		this->push_back(c);
		this->push_back(d);
	}
};
struct HashFunc
{
	std::size_t operator()(const Quadruplets &key) const
	{
		using std::size_t;
		using std::hash;

		return ((((hash<int>()(key[0])
			^ (hash<int>()(key[1]) << 1)) >> 1)
			^ (hash<int>()(key[2]) << 1)) >> 1)
			^ (hash<int>()(key[3]) << 1);
	}
};

struct EqualKey
{
	bool operator () (const Quadruplets &lhs, const Quadruplets &rhs) const
	{
		return lhs[0] == rhs[0]
			&& lhs[1] == rhs[1]
			&& lhs[2] == rhs[2]
			&& lhs[3] == rhs[3];
	}
};

class Solution_hash {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		unordered_map<int, vector<vector<int>>> twoSumMap;
//		set<Quadruplets> res;
		unordered_set<Quadruplets, HashFunc, EqualKey> res;

		for (int i = 0; i < nums.size(); i++) {
			if (i > 1 && nums[i] == nums[i - 2]) continue;

			for (int j = i + 1; j < nums.size(); j++) {
				if (j > i + 2 && nums[j] == nums[j - 2]) continue;
				//如果存在和
				if (twoSumMap.count(target - nums[i] - nums[j])) {
					//把所有二元和为此数的下标对都拎出来
					vector<vector<int>> list = twoSumMap.at(target - nums[i] - nums[j]);
					//把有重叠的下标对去掉
					for (auto pair : list) {
						int m1 = min(pair[0], i);
						int m2 = min(pair[1], j);
						int m3 = max(pair[0], i);
						int m4 = max(pair[1], j);
						if (m1 == m3 || m1 == m4 || m2 == m3 || m2 == m4) continue;
						//Quadruplets quad({ nums[m1], nums[min(m2, m3)], nums[max(m2, m3)], nums[m4] });
						res.insert({ nums[m1], nums[min(m2, m3)], nums[max(m2, m3)], nums[m4] });
					}
				}
				
				if (twoSumMap.find(nums[i] + nums[j]) != twoSumMap.end()) {
					vector<vector<int>> ls = twoSumMap.at(nums[i] + nums[j]);
					ls.push_back({ i,j });
					twoSumMap[nums[i] + nums[j]] = ls;
				}
				else {
					vector<vector<int>> ls;
					ls.push_back({ i,j });
					twoSumMap[nums[i] + nums[j]] = ls;
				}			
			}
		}
		vector<vector<int>> answer(res.begin(),res.end());
		return answer;
	}
};

//迭代版本
//class Solution_iter {
//public:
//
//};



int main() {
	vector<vector<int>> answer;
	vector<int> nums = { 1,0,-1,0,-2,2 };
	int target = 0;
	Solution_hash sol;
	answer = sol.fourSum(nums, target);
	unordered_set<string> set_test;
	vector<string> vector_test;
	set_test.insert({ 1,2,3});
	copy(set_test.begin(), set_test.end(), back_inserter(vector_test));
	string s = vector_test[0];
	return 0;
}