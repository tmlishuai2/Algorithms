#include <string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int lpoint, rpoint, nextpoint, count;
		int maxlpoint, maxrpoint, maxcount = 0;
		int length = s.size();
		for (int i = 0; i < length;) {
			//���i���ڽӽ��ַ���β����������Ӵ��㵽ĩβҲû������maxcount
			if ((2 * (length - i) - 1) <= maxcount) return s.substr(maxlpoint, maxcount);
			count = 1;
			rpoint = i + 1;
			if(rpoint < length)
				while ((s[rpoint] == s[i])) {
					rpoint += 1;
					count += 1;
				}				
			nextpoint = rpoint;
			lpoint = i - 1;
			if((lpoint >= 0) && (rpoint < length))
				while ((s[lpoint] == s[rpoint])) {
					lpoint -= 1;
					rpoint += 1;
					count += 2;
					if (lpoint < 0) break;
					if (rpoint >= length) break;
				}
			if (count > maxcount) {
				maxcount = count;
				maxlpoint = lpoint + 1;
				maxrpoint = rpoint - 1;
			}
			i = nextpoint;	//iֱ����������ͬ���Ǹ�λ��
		}
		return s.substr(maxlpoint, maxcount);
	}
};

int main() {
	Solution sol;
	string s = "aba";
	string ans;
	ans = sol.longestPalindrome(s);
	return 0;
}