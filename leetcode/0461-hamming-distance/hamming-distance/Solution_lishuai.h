#pragma once
//自制解法
class Solution_lishuai {
public:
	static bool cmp(const string &a, const string &b) {
		return a.size() < b.size();
	}
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		vector<string> words_copy = words;
		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < words.size(); j++) {
				if (j == i) continue;
				string::size_type n = words[j].find(words[i]);
				if (n == string::npos) continue;
				else words[j].erase(n, n + words[i].size());

			}
		}
		vector<string>::iterator i;
		for (i = words.begin(); i != words.end();) {
			if (*i == "") i = words_copy.erase(i);
			else ++i;
		}
		return words_copy;
	}
};

