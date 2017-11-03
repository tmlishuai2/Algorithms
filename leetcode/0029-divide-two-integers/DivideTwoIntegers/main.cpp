#include <iostream>
#include <climits>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1)) {
            return INT_MAX;
        }
        long long answer = 0;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        // note the difference between abs() and labs()
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        while (dvd >= dvs) {
            long dvs_temp = dvs, m = 1;
            while (dvd >= (dvs_temp << 1)) {
                dvs_temp <<= 1;
                m <<= 1;
            }
            answer += m;
            dvd -= dvs_temp;
        }
        return sign * answer;
    }
};

int main() {
//    std::cout << "Hello, World!" << std::endl;
//    std::cout << INT_MAX << std::endl;
//    std::cout << INT_MIN << std::endl;
    int dvd = 100, dvs = 49;
    Solution sol;
    std::cout << sol.divide(dvd, dvs) << std::endl;
    return 0;
}