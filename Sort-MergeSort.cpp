#include<iostream>
#include<random>
#include<vector>
using namespace std;
void printVector(vector<int> nums);
//Recursion
class Solution1 {
public:
	void mergeSort(vector<int>& nums) {
		if (nums.size() < 2) {
			return;
		}
		process(nums, 0, nums.size() - 1);
	}
	void process(vector<int>& nums, int left, int right) {
		if (left >= right) {
			return;
		}
		int mid = left + ((right - left) >> 1);
		process(nums, left, mid);
		process(nums, mid + 1, right);
		merge(nums, left, mid, right);
	}
	void merge(vector<int>& nums, int left, int mid, int right) {
		if (left == right) {
			return;
		}
		vector<int> tmp(right - left + 1, 0);
		int p1 = left;
		int p2 = mid + 1;
		int cur = 0;
		while (p1 <= mid && p2 <= right) {
			if (nums[p1] < nums[p2]) {
				tmp[cur++] = nums[p1++];
			}
			else {
				tmp[cur++] = nums[p2++];
			}
		}
		while (p1 <= mid) {
			tmp[cur++] = nums[p1++];
		}
		while (p2 <= right) {
			tmp[cur++] = nums[p2++];
		}
		for (int i = 0; i < tmp.size(); i++) {
			nums[left + i] = tmp[i];
		}
	}
};
//Iteration
class Solution2 {
public:
	void mergeSort(vector<int>& nums) {
		int n = nums.size(), left = 0, mid = 0, right = 0;
		if (n < 2) {
			return;
		}
		int mergeSize = 1;
		while (mergeSize < n) {
			left = 0;
			while (left < n) {
				mid = left + mergeSize - 1;
				if (mid >= n) {
					break;
				}
				right = mid + mergeSize > n - 1 ? n - 1 : mid + mergeSize;
				merge(nums, left, mid, right);
				left = right + 1;
			}
			if (mergeSize > n / 2) {
				break;
			};
			mergeSize <<= 1;
		}
	}
	void merge(vector<int>& nums, int left, int mid, int right) {
		if (left == right) {
			return;
		}
		vector<int> tmp(right - left + 1, 0);
		int p1 = left;
		int p2 = mid + 1;
		int index = 0;
		while (p1 <= mid && p2 <= right) {
			tmp[index++] = nums[p1] > nums[p2] ? nums[p2++] : nums[p1++];
		}
		while (p1 <= mid) {
			tmp[index++] = nums[p1++];
		}
		while (p2 <= right) {
			tmp[index++] = nums[p2++];
		}
		for (int i = 0; i < tmp.size(); i++, left++) {
			nums[left] = tmp[i];
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
	S1.mergeSort(nums);
}
void algorithm2(vector<int> nums) {
	Solution2 S2;
	S2.mergeSort(nums);
}
void Test() {
	Validator().Validate(algorithm1, algorithm2);
}
int main() {
	Test();
	return 0;
}