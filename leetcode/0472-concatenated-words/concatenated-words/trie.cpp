#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
//���±��string��,�����¼����string��ԭ���ֵ��е�˳��
class string_sub : public string {
public:
	int sub;
	string_sub(string& str, int a) :string(str) {
		sub = a;
	}
};




//trie�ⷨ
class TrieNode {
public:
	TrieNode *child[26];
	bool isWord;
	TrieNode() : isWord(false) {
		for (auto &a : child) a = NULL;
	}
};
class Trie {
private:
	TrieNode *root;
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode * nptr = root;
		for (int i = 0; i < word.size(); i++) {
			if (nptr->child[word[i] - 'a'] == NULL)
				nptr->child[word[i] - 'a'] = new TrieNode();
			nptr = nptr->child[word[i] - 'a'];
		}
		nptr->isWord = true;
	}

	/** Returns if the word is in the trie. */
	//����������ص��������ܹ��з�һ���ַ�����λ��
	vector<int> search(string word) {
		vector<int> res;
		TrieNode *nptr = root;
		for (int i = 0; i<word.size(); i++) {
			if (nptr->isWord)
				res.push_back(i);
			if (nptr->child[word[i] - 'a'] == NULL)
				return res;
			nptr = nptr->child[word[i] - 'a'];
		}
		return res;
	}

};

class Solution_trie {
public:
	Trie trie;
	unordered_map<string, int> mark;

	static bool cmp(const string_sub &a, const string_sub &b) {
		return a.size() < b.size();
	}
	static bool recover(const string_sub& a, const string_sub& b){
		return a.sub < b.sub;
	}
	//k�����Ҫ������¼�Ƿ���������
	bool judge(string& str, int k) {
		vector<int> res = trie.search(str);
		//��ĩ�˽����������ܹ��Ż�һЩЧ��
		reverse(res.begin(), res.end());
		//���������������ֻ��Ҫ��str����������Ƿ���mark�оͺá�
		if (k == 1) {
			if (mark.find(str) != mark.end())
				return true;
		}
		for (int i = 0; i<res.size(); i++) {
			string tmp = str.substr(res[i]);
			if (judge(tmp, 1)) {
				mark[tmp] = 1;
				return true;
			}
		}
		return false;
	}
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		vector<string_sub> words_sub;
		
		for (int i = 0; i < words.size(); i++) {
			string_sub word_sub(words[i], i);
			words_sub.push_back(word_sub);
		}
		

		sort(words_sub.begin(), words_sub.end(), cmp);
		vector<string_sub>  res_sub;
		for (auto && i : words_sub) {
			if (i.size() == 0)
				continue;
			if (judge(i, 0))
				res_sub.push_back(i);
			trie.insert(i);
			mark[i] = 1;
		}
		sort(res_sub.begin(), res_sub.end(), recover);
		vector<string> res;
		for (auto && i : res_sub) {
			string j = i;
			res.push_back(j);
		}

		return res;
	}
};



