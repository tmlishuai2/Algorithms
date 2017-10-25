class Solution {
public:
	int hammingDistance(int x, int y) {
		//int count = 0;
		//while ((x > 1) & (y > 1)) {
		//	count += (x % 2 != y % 2);
		//	x = x / 2;
		//	y = y / 2;
		//}
		//count += (x != y);
		//return count;
		int n = x^y;
		int c = 0;
		for (c = 0; n; ++c) n &= (n - 1);
		return c;
	}
};

