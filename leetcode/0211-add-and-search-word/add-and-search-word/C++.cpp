#include <string>
using namespace std;

class TrieNode {
public:
	TrieNode *child[26];
	bool isWord;	//isWord表示是否存在以此节点结尾的单词
	TrieNode() :isWord(false) {
		for (auto &a : child) a = nullptr;	//基于范围的for循环
	}
};

class WordDictionary {
private:
	TrieNode *root;
public:
	//initialize
	WordDictionary() {
		root = new TrieNode();
	}

	//add word, same as insert of trie
	void addWord(string word) {
		TrieNode * nptr = root;
		for (int i = 0; i < word.size(); i++) {
			if (nptr->child[word[i] - 'a'] == NULL)
				nptr->child[word[i] - 'a'] = new TrieNode();
			nptr = nptr->child[word[i] - 'a'];
		}
		nptr->isWord = true;
	}

	//dfs with recursion
	bool dfs(string word, TrieNode* root) {
		if (root == NULL) return false;
		if (word.size() == 0) return root->isWord;

		TrieNode* nptr = root;
		if (word[0] != '.') {
			int k = word[0] - 'a';
			if (nptr->child[k] == NULL) return false;
			return dfs(word.substr(1), nptr->child[k]);
		}
		else	//if '.'
		{
			bool tmp = false;
			for (int j = 0; j < 26; j++)
				if (dfs(word.substr(1), nptr->child[j]) == true)
					return true;
			return false;
		}
	}

	//fuzzy search
	bool search(string word) {
		return dfs(word, root);
	}
};