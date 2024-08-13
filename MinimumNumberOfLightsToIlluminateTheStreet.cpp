#include <iostream>
#include<unordered_set>
#include<random>
#include<functional>
using namespace std;

//暴力枚举
class Solution1 {
	int ans = INT_MAX;
public:
	int minLight(string str) {
		unordered_set<int> s;
		process(str, 0, s);
		return ans;
	}
	int process(string str, int cur, unordered_set<int>& light) {
		if (cur == str.length()) {
			//检测是否全照亮
			for (int i = 0; i < str.length(); i++) {
				if (str[i] != 'X') {
					if (light.find(i - 1) == light.end()
						&& light.find(i) == light.end()
						&& light.find(i + 1) == light.end()) {
						return INT_MAX;
					}
				}
			}
			ans = ans > light.size() ? light.size() : ans;
			return light.size();
		}
		else {
			int no = process(str, cur + 1, light);
			int yes = INT_MAX;
			if (str[cur] == '.') {
				light.insert(cur);
				process(str, cur + 1, light);
				light.erase(cur);
			}
			return min(no, yes);
		}
	}
};
//贪心
class Solution2 {
public:
	int minLight(string s) {
		int ans = 0;
		int index = 0;
		while (index < s.length()) {
			if (s[index] == 'X') {
				index++;
			}
			else {
				ans++;
				if (index + 1 == s.length()) {
					break;
				}
				else {
					if (s[index + 1] == 'X') {
						index += 2;
					}
					else {
						index += 3;
					}
				}
			}
		}
		return ans;
	}
};

#define MAX_LEN 15//数组长度
#define MAX_VALUE 1//数据范围
#define MAX_TEST_TIMES 1000//样本量
//Random Test
class Validator {

public:
	string testCaseGenerate() {
		random_device rd;
		default_random_engine e(rd());
		uniform_int_distribution<int> u(0, MAX_LEN);
		int len = u(e);
		string Test;
		uniform_int_distribution<int> uid(0, 1);
		for (int i = 0; i < MAX_LEN; i++) {
			Test += uid(e) ? "." : "X";
		}
		return Test;
	}
	//void Validate(function<int(string)> func1, function<int(string)> func2) {
	void Validate(int (*func1)(string), int (*func2)(string)) {
		vector<string> TestArr;
		for (int i = 0; i < MAX_TEST_TIMES; i++) {
			string Test = testCaseGenerate();
			TestArr.emplace_back(Test);
		}
		for (int i = 0; i < MAX_TEST_TIMES; i++) {
			int ans1 = func1(TestArr[i]);
			int ans2 = func2(TestArr[i]);
			if (ans1 != ans2) {
				cout << "Worry Answer!" << endl;
				cout << "Test:" << TestArr[i] << endl;
				cout << "Answer1:" << ans1 << endl;
				cout << "Answer2:" << ans2 << endl;
				return;
			}
		}
		cout << "Accepted!" << endl;
	}
};

int algorithm1(string s) {
	Solution1 S1;
	return S1.minLight(s);
}
int algorithm2(string s) {
	Solution2 S2;
	return S2.minLight(s);
}
void Test() {
	Validator().Validate(algorithm1, algorithm2);
}
int main() {
	Test();
	return 0;
}