#include "concatenated-words.h"

using namespace std;
int main() {
	vector<string> words = { "cat", "cats", "catsdogcats", "dog",
		"dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat" };
	Solution_trie sol_trie;
	Solution_dp sol_dp;
	vector<string> ans_dp, ans_trie;
	ans_dp = sol_dp.findAllConcatenatedWordsInADict(words);
	ans_trie = sol_trie.findAllConcatenatedWordsInADict(words);
	return 0;
}