#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x % 10 == 0 && x != 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }
        if (x < 100 && x % 11 == 0) {
            return true;
        }
        if (x < 1000 && x % 100 == x / 100) {
            return true;
        }


        int reverse = 0;
        while (reverse < x) {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return reverse == x or reverse / 10 == x;
    }
};

int main() {
//    std::cout << "Hello, World!" << std::endl;
    Solution sol;
    int x = 1234321;
    std::cout << sol.isPalindrome(x);
    return 0;
}