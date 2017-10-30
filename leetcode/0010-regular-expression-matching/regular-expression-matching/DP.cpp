#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isMatch( string s, string p) {
		int m = s.size();
		int n = p.size();
		bool** match = new bool*[m + 1];
		for (int i = 0; i < m + 1; i++) match[i] = new bool[n + 1];

		match[0][0] = true;
		for (int i = 1; i < m + 1; i++) match[i][0] = false;
		for (int j = 1; j < n + 1; j++) match[0][j] = j > 1 && p[j - 1] == '*'&&match[0][j - 2];

		for(int i=0;i<m;i++) {
			for (int j = 0; j < n; j++) {
				if (p[j] == '.') match[i + 1][j + 1] = match[i][j];
				else if (p[j] != '*') match[i + 1][j + 1] = s[i] == p[j] && match[i][j];
				else {
					char x = p[j - 1];
					match[i + 1][j + 1] = match[i + 1][j - 1] && j > 0 ||
						(s[i] == x || x == '.') && match[i][j - 1] && j > 0 ||
						(s[i] == x || x == '.') && match[i][j + 1];
				}
			}
		}
		return match[m][n];
	}
};

int main() {
	string s, p;
	p = ".acde*f";
	s = "vacdef";
	Solution sol;
	bool answer;
	answer = sol.isMatch(s, p);
	return 0;
}