#include "hashmap.h"
using namespace std;
class Solution_hashmap {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		unordered_set<string> mark;
		static bool cmp(const string &a, const string &b) {
			return a.size()<b.size();
		}
		bool judge(string &word, int pos, string str) {
			if (pos == word.size()) {
				if (mark.find(str) != mark.end())
					return true;
				return false;
			}
			str += word[pos];
			if (mark.find(str) != mark.end()) {
				string tmp = "";
				if (judge(word, pos + 1, ""))
					return true;
			}
			return judge(word, pos + 1, str);
		}
		vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
			sort(words.begin(), words.end(), cmp);
			vector<string>  res;
			for (auto && i : words) {
				if (i.size() == 0)
					continue;
				if (judge(i, 0, ""))
					res.push_back(i);
				mark.insert(i);
			}
			return res;
		}
	}
};