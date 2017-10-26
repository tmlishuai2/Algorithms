#include <string>
using namespace std;

class TrieNode {
public:
	TrieNode *child[26];
	bool isWord;	//isWord��ʾ�Ƿ�����Դ˽ڵ��β�ĵ���
	TrieNode() :isWord(false) {
		for (auto &a : child) a = nullptr;	//���ڷ�Χ��forѭ��
	}
};

class Trie {
private:
	TrieNode *root;
public:
	Trie() {
		root = new TrieNode();
	}

	//�������
	void insert(string word) {
		TrieNode * nptr = root;
		for (int i = 0; i < word.size(); i++) {
			if (nptr->child[word[i] - 'a'] == NULL)
				nptr->child[word[i] - 'a'] = new TrieNode();
			nptr = nptr->child[word[i] - 'a'];
		}
		nptr->isWord = true;
	}

	//��������
	bool search(string word) {
		if (word.size() == 0) return false;
		TrieNode *nptr = root;
		for (int i = 0; i < word.size(); i++) {
			if (nptr->child[word[i] - 'a'] == NULL)
				return false;
			nptr = nptr->child[word[i] - 'a'];
		}
		return nptr->isWord;	//�Ƿ�����Ե�ǰ�ڵ��β�ĵ���
	}

	//�ж��Ƿ������prefixΪǰ׺���ַ��������������ƣ�ֻ�ǲ���Ҫ�жϽ�β�ڵ��Ƿ�ΪҶ�ӽ��
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
