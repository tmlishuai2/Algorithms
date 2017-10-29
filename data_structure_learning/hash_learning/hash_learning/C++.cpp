#include<iostream>
#include<unordered_map>
using namespace std;

class Quadruplets :public vector<int> {
public:
	Quadruplets(vector<int> v) {
		this->push_back(v[0]);
		this->push_back(v[1]);
		this->push_back(v[2]);
		this->push_back(v[3]);
	}
	Quadruplets(int a, int b, int c, int d) {
		this->push_back(a);
		this->push_back(b);
		this->push_back(c);
		this->push_back(d);
	}

};

struct HashFunc
{
	std::size_t operator()(const Quadruplets &key) const
	{
		using std::size_t;
		using std::hash;

		return ((((hash<int>()(key[0])
			^ (hash<int>()(key[1]) << 1)) >> 1)
			^ (hash<int>()(key[2]) << 1)) >> 1)
			^ (hash<int>()(key[3]) << 1);
	}
};

struct EqualKey
{
	bool operator () (const Quadruplets &lhs, const Quadruplets &rhs) const
	{
		return lhs[0] == rhs[0]
			&& lhs[1] == rhs[1]
			&& lhs[2] == rhs[2]
			&& lhs[3] == rhs[3];
	}
};

int main()
{
	unordered_map<Quadruplets, string, HashFunc, EqualKey> hashmap =
	{
		{ { 01, 02, 03, 04 }, "one" },
		{ { 11, 12, 13, 14 }, "two" },
		{ { 21, 22, 23, 24 }, "three" },
	};

	Quadruplets key(11, 12, 13, 14);

	auto it = hashmap.find(key);



	return 0;
}