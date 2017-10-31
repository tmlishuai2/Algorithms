#include <limits>
#include <string>
using namespace std;
int myAtoi(char* str) {
	int i = 0;
	int number = 0;
	int sign = 1;
	while (str[i] == ' ') i++;
	if (str[i] == '-' || str[i] == '+') sign = 1 - 2 * (str[i++] == '-');

	while (i<strlen(str)&&str[i] >= '0'&&str[i] <= '9') {
		if (sign == 1 && number > INT_MAX / 10 || sign == 1 && number == INT_MAX / 10 && str[i] > '7')
			return INT_MAX;
		if (sign == -1 && number > INT_MAX / 10 || sign == -1 && number == INT_MAX / 10 && str[i] > '8')
			return INT_MIN;
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return number*sign;
}

int main() {
	char* str= "      -11919730356x";
	int answer;
	answer = myAtoi(str);
	return 0;
}