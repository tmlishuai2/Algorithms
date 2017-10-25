#include <string>
using namespace std;
class Solution {
public:
	string convert(string s, int numRows) {
		string answer;
		int length = s.size();
		if (numRows == 1) return s;
		for (int i = 0; i < numRows; i++) {
			int k = i;
			if((i == 0) | (i==numRows-1)){

				while (k < length) {
					answer.append(1, s[k]);
					k = k + 2 * (numRows - 1);

				}
			}
			else {
				while (k < length) {
					answer.append(1, s[k]);
					k = k + 2 * (numRows - 1 - i);
					if (k >= length) break;
					answer.append(1, s[k]);
					k = k + 2 * i;
				}
			}
		}
		return answer;
	}
};

int main() {
	Solution sol;
	string s = "A";
	int numRows = 1;
	string ans;
	ans = sol.convert(s, numRows);
	

	return 0;
}