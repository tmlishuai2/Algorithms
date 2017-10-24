#include <vector>
using std::vector;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		class max {
		public:
			int operator() (int x, int y) {
				if (x > y) return x;
				else return y;
			}
		} max;
		int m, n;
		vector<int> A,B;

		if (nums1.size() < nums2.size()) {
			m = nums1.size();
			n = nums2.size();
			A = nums1;
			B = nums2;
		}
		else {
			m = nums2.size();
			n = nums1.size();
			A = nums2;
			B = nums1;
		}
		int lo = 0, hi = m;
		int mi, j;
		double left_max, right_min;
		while (lo <= hi) {
			mi = ((lo + hi) >> 1);
			j = (m + n + 1) / 2 - mi;
			if ((mi > 0) && (B[j] < A[mi - 1])) hi = mi - 1;
			else if ((mi < m) && (A[mi] < B[j - 1])) lo = mi + 1;
			else {
				if (mi == 0) left_max = B[j - 1];
				else if (j == 0) left_max = A[mi - 1];
				else left_max = max(A[mi - 1], B[j - 1]);


				if ((m + n) % 2 == 1) return left_max;

				if (mi == m) right_min = B[j];
				else if (j == n) right_min = A[mi];
				else right_min = A[mi] + B[j] - max(A[mi], B[j]);
				return (left_max + right_min) / 2.0;
			}
		}
	}
};
int main(){
	Solution sol;
	vector<int> A = {1,2};
	vector<int> B = {3,4};
	double answer = sol.findMedianSortedArrays(A, B);
	return 0;
}

