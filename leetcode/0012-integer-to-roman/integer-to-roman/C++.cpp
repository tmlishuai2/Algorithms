#include <string>
#include <vector>
using namespace std;




class Solution {
public:
	vector<string> base2roman(vector<string> base) {
		vector<string> roman;
		roman.push_back("");
		roman.push_back(base[0]);
		roman.push_back(base[0]+base[0]);
		roman.push_back(base[0] + base[0] + base[0]);
		roman.push_back(base[0] + base[1]);
		roman.push_back(base[1]);
		roman.push_back(base[1] + base[0]);
		roman.push_back(base[1] + base[0] + base[0]);
		roman.push_back(base[1] + base[0] + base[0] + base[0]);
		roman.push_back(base[0] + base[2]);
		return roman;
	}
	string intToRoman(int num) {
		string answer = "";
		//vector<string> roman_digit =
		//		{ "","I","II","III","IV","V","VI","VII","VIII","IX" };
		vector<string> roman_power0_base = { "I","V","X" };
		vector<string> roman_power1_base = { "X","L","C" };
		vector<string> roman_power2_base = { "C","D","M" };
		vector<string> roman_power0 = base2roman(roman_power0_base);
		vector<string> roman_power1 = base2roman(roman_power1_base);
		vector<string> roman_power2 = base2roman(roman_power2_base);
		
//如何批量处理这种代码呢？动态语言可以使用eval（s）,C++咋办？
		answer.insert(0,roman_power0[ num % 10]);
		answer.insert(0,roman_power1[(num = num / 10) % 10]);
		answer.insert(0,roman_power2[(num = num / 10) % 10]);
		if (num/10 == 1) answer.insert(0, "M");
		if (num/10 == 2) answer.insert(0, "MM");
		if (num/10 == 3) answer.insert(0, "MMM");
		return answer;

	}
};