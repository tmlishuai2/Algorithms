using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		int y = 0;
		if (x < 0) return false;
		if (x == 0) return true;
		if (x % 10 == 0) return false;
		while (y < x) {
			y = y*10 + (x % 10);
			x = x / 10;
		}
		return x == y || (y / 10) == x;
	}
};

int main() {
	bool answer;
	Solution sol;
	int x = 10;
	answer = sol.isPalindrome(x);
	return 0;
}