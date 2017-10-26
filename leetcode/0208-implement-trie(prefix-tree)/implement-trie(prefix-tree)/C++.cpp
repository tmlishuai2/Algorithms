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

class Trie {
private:
	TrieNode *root;
public:
	Trie() {
		root = new TrieNode();
	}

	//插入操作
	void insert(string word) {
		TrieNode * nptr = root;
		for (int i = 0; i < word.size(); i++) {
			if (nptr->child[word[i] - 'a'] == NULL)
				nptr->child[word[i] - 'a'] = new TrieNode();
			nptr = nptr->child[word[i] - 'a'];
		}
		nptr->isWord = true;
	}

	//搜索操作
	bool search(string word) {
		if (word.size() == 0) return false;
		TrieNode *nptr = root;
		for (int i = 0; i < word.size(); i++) {
			if (nptr->child[word[i] - 'a'] == NULL)
				return false;
			nptr = nptr->child[word[i] - 'a'];
		}
		return nptr->isWord;	//是否存在以当前节点结尾的单词
	}

	//判断是否存在以prefix为前缀的字符串，与搜索类似，只是不需要判断结尾节点是否为叶子结点
	bool startsWith(string prefix) {
		if (prefix.size() == 0) return false;
		TrieNode *nptr = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (nptr->child[prefix[i] - 'a'] == NULL)
				return false;
			nptr = nptr->child[prefix[i] - 'a'];
		}
		return true;
	}

};
