#include<iostream>
#include<random>
#include<vector>
using namespace std;

class Solution1 {
public:
	int theRightOne(int n) {
		//讨论上溢可能
		if (n == 0) {
			return 0;
		}
		return n & (~n + 1);
	}
};


class Solution2 {
public:
	int theRightOne(int n) {
		int ans = 0;
		unsigned tmp = n;
		while (tmp != 0) {
			if ((tmp & 1) == 0) {
				tmp >>= 1;
				ans <<= 1;
			}
			else {
				break;
			}
		}
		return ans;
	}
};










bool operator==(vector<int> a, vector<int> b) {
	if (a.size() != b.size()) {
		return false;
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}
bool operator!=(vector<int> a, vector<int> b) {
	return !(a == b);
}
void printVector(vector<int> nums) {
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
}

#define MIN_VALUE -1000//数据范围
#define MAX_VALUE 1000//数据范围
#define MAX_TEST_TIMES 10000//样本量
//Random Test
class Validator {

public:
	int testCaseGenerate() {
		vector<int> Test;
		random_device rd;
		default_random_engine e(rd());
		uniform_int_distribution<int> valRange(MIN_VALUE, MAX_VALUE);
		return valRange(e);
	}
	//void Validate(function<int(string)> func1, function<int(string)> func2) {
	void Validate(int (*func1)(int num), int (*func2)(int num)) {
		vector<int> TestArr;
		for (int i = 0; i < MAX_TEST_TIMES; i++) {
			int Test = testCaseGenerate();
			TestArr.emplace_back(Test);
		}
		for (int i = 0; i < MAX_TEST_TIMES; i++) {
			int origin = TestArr[i];
			int ans1 = func1(TestArr[i]);
			int ans2 = func2(TestArr[i]);
			if (ans1 != ans2) {
				cout << "Worry Answer!" << endl;
				cout << "TestArray:" << origin << endl;
				cout << "TestAlgorithm1_Answer:" << ans1 << endl;
				cout << "TestAlgorithm2_Answer:" << ans2 << endl;
				return;
			}
		}
		cout << "Accepted!" << endl;
	}
};

int algorithm1(int num) {
	Solution1 S1;
	return S1.theRightOne(num);
}
int algorithm2(int num) {
	Solution1 S2;
	return S2.theRightOne(num);
}
void Test() {
	Validator().Validate(algorithm1, algorithm2);
}
int main() {
	Test();
	return 0;
}