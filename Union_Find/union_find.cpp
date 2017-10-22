#include <iostream>
using namespace std;

const int N = 100;

int father[N];

//initialize the father
void init(int n) {
	for (int i = 0; i < n; i++)
		father[i] = i;
}

int getMark(int v) {
	if (father[v] == v)
		return v;
	else
		return getMark(father[v]);
}

void merge(int x, int y) {
	x = getMark(x);
	y = getMark(y);
	father[x] = y;
}

bool judge(int x, int y) {
	return getMark(x) == getMark(y);
}

int main() {
	int n;
	cin >> n;
	init(n);
	int x, y;
	while (1) {
		cin >> x >> y;
		if (x == 0) break;
		else merge(x, y);
	}
	while (1) {
		cin >> x >> y;
		cout << judge(x, y) << endl;
	}
	return 0;
}