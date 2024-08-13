/*Easy Sort Algorithm
* bubbleSort
* insertSort
* selectSort
*/
#include<iostream>
#include<random>
#include<vector>
using namespace std;
void printVector(vector<int> nums);
class Solution1 {
public:
	void Sort(vector<int>& nums) {
		if (nums.size() < 2) {
			return;
		}
		sort(nums.begin(), nums.end());
	}
};
class Solution2 {
public:
	void bubbleSort(vector<int>& nums) {
		if (nums.size() < 2) {
			return;
		}
		int N = nums.size() - 1;
		for (int e = N; e > 0; e--) {
			for (int j = 0; j < e; j++) {
				if (nums.at(j) > nums.at(j + 1)) {
					swap(nums.at(j), nums.at(j + 1));
				}
			}
		}
	}
	void insertSort(vector<int>& nums) {
		if (nums.size() < 2) {
			return;
		}
		int N = nums.size();
		int pos;
		for (int i = 0; i < N; i++) {
			pos = i;
			while (pos > 0 && nums.at(pos) < nums.at(pos - 1)) {
				swap(nums.at(pos), nums.at(pos - 1));
				pos--;
			}
		}
	}
	void selectSort(vector<int>& nums) {
		if (nums.size() < 2) {
			return;
		}
		int N = nums.size() - 1;
		int min = 0;
		for (int i = 0; i < N; i++) {
			min = i;
			for (int j = i + 1; j <= N; j++) {
				if (nums.at(min) > nums.at(j)) {
					min = j;
				}
			}
			if (i != min) {
				swap(nums.at(i), nums.at(min));
			}
		}
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
#define MAX_LEN 30//数组长度
#define MIN_VALUE -1000//数据范围
#define MAX_VALUE 1000//数据范围
#define MAX_TEST_TIMES 1000//样本量
//Random Test
class Validator {
public:
	pair<vector<int>, vector<int>> testCaseGenerate() {
		vector<int> Test;
		random_device rd;
		default_random_engine e(rd());
		uniform_int_distribution<int> len(0, MAX_LEN);
		int length = len(e);
		uniform_int_distribution<int> valRange(MIN_VALUE, MAX_VALUE);
		for (int i = 0; i < length; i++) {
			Test.push_back(valRange(e));
		}
		return make_pair(Test, vector<int>(Test.begin(), Test.end()));
	}
	//void Validate(function<int(string)> func1, function<int(string)> func2) {
	void Validate(void (*func1)(vector<int>), void (*func2)(vector<int>)) {
		vector<pair<vector<int>, vector<int>>> TestArr;
		for (int i = 0; i < MAX_TEST_TIMES; i++) {
			pair<vector<int>, vector<int>> Test = testCaseGenerate();
			TestArr.emplace_back(Test);
		}

		for (int i = 0; i < MAX_TEST_TIMES; i++) {
			vector<int> origin(TestArr[i].first.begin(), TestArr[i].first.end());
			func1(TestArr[i].first);
			func2(TestArr[i].second);
			if (TestArr[i].first != TestArr[i].second) {
				cout << "Worry Answer!" << endl;
				cout << "TestArray:";
				printVector(origin);
				cout << endl;
				cout << "TestAlgorithm1_Answer:";
				printVector(TestArr[i].first);
				cout << endl;
				cout << "TestAlgorithm2_Answer:";
				printVector(TestArr[i].second);
				cout << endl;
				return;
			}
		}
		cout << "Accepted!" << endl;
	}
};

void algorithm1(vector<int> nums) {
	Solution1 S1;
	S1.Sort(nums);
}
void algorithm2(vector<int> nums) {
	Solution2 S2;
	S2.selectSort(nums);
}
void Test() {
	Validator().Validate(algorithm1, algorithm2);
}
int main() {
	Test();
	return 0;
}