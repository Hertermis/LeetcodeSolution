#include<iostream>
#include<random>
#include<vector>
using namespace std;
class Solution1 {
public:
	int sequenceSearch(vector<int> arr, int target) {
		int N = arr.size();
		if (N == 0) {
			return -1;
		}
		for (int i = 0; i < N; i++) {
			if (arr[i] == target) {
				return i;
			}
		}
		return -1;
	}
};


class Solution2 {
public:
	int binarySearch(vector<int> arr, int target) {
		int N = arr.size();
		if (N == 0) {
			return -1;
		}
		int left = 0;
		int right = N - 1;
		while (left <= right) {
			/*(left<=right)会比(left<right)多一步判断，*/
			int mid = left + ((right - left) >> 1);
			if (arr[mid] == target) {
				return mid;
			}
			else if (arr[mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return -1;
	}
};



ostream& operator<<(ostream& os, vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		os << arr[i] << " ";
	}
	return os;
}


#define MAX_LEN 30//数组长度
#define MIN_VALUE -1000//数据范围
#define MAX_VALUE 1000//数据范围
#define MAX_TEST_TIMES 1000//样本量
//Random Test
class Validator {

public:
	pair<vector<int>, int> testCaseGenerate() {
		vector<int> Test;
		random_device rd;
		default_random_engine e(rd());
		uniform_int_distribution<int> len(0, MAX_LEN);
		int length = len(e);
		uniform_int_distribution<int> valRange(MIN_VALUE, MAX_VALUE);
		for (int i = 0; i < length; i++) {
			Test.push_back(valRange(e));
		}
		sort(Test.begin(), Test.end());
		uniform_int_distribution<int> mustHaveTarget(0, 1);
		int target = 0;
		if (mustHaveTarget(e)) {
			do {
				target = len(e);
			} while (target == MAX_LEN);
			target = Test[target];
		}
		else {

			target = valRange(e);
		}
		return make_pair(Test, target);
	}
	//void Validate(function<int(string)> func1, function<int(string)> func2) {
	void Validate(int (*func1)(vector<int>, int), int (*func2)(vector<int>, int)) {
		vector<pair<vector<int>, int>> TestArr;
		for (int i = 0; i < MAX_TEST_TIMES; i++) {
			pair<vector<int>, int> Test = testCaseGenerate();
			TestArr.emplace_back(Test);
		}
		for (int i = 0; i < MAX_TEST_TIMES; i++) {
			int ans1 = func1(TestArr[i].first, TestArr[i].second);
			int ans2 = func2(TestArr[i].first, TestArr[i].second);
			if (ans1 != ans2) {
				if (ans1 == -1 || ans2 == -1) {
					cout << "Worry Answer!" << endl;
					cout << "TestArray:" << TestArr[i].first << endl;
					cout << "TestTarget:" << TestArr[i].second << endl;
					cout << "Answer1:" << ans1 << endl;
					cout << "Answer2:" << ans2 << endl;
					return;
				}
				if (TestArr[i].first[ans1] != TestArr[i].first[ans2]) {
					cout << "Worry Answer!" << endl;
					cout << "TestArray:" << TestArr[i].first << endl;
					cout << "TestTarget:" << TestArr[i].second << endl;
					cout << "Answer1:" << TestArr[i].first[ans1] << endl;
					cout << "Answer2:" << TestArr[i].first[ans2] << endl;
					return;
				}
			}

		}
		cout << "Accepted!" << endl;
	}
};

int algorithm1(vector<int> nums, int target) {
	Solution1 S1;
	return S1.sequenceSearch(nums, target);
}
int algorithm2(vector<int> nums, int target) {
	Solution2 S2;
	return S2.binarySearch(nums, target);
}
void Test() {
	Validator().Validate(algorithm1, algorithm2);
}
int main() {
	Test();
	return 0;
}