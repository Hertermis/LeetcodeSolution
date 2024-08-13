#include<iostream>
#include<random>
#include<vector>
#include<stack>
using namespace std;
void printVector(vector<int>);
//Recursion
class Solution1 {
public:
	void quickSort(vector<int>& nums) {
		if (nums.size() < 2) return;
		process(nums, 0, nums.size() - 1);
	}
	void process(vector<int>& nums, int left, int right) {
		if (left >= right) {
			return;
		}
		pair<int, int> ret = partition(nums, left, right);
		process(nums, left, ret.first - 1);
		process(nums, ret.second + 1, right);
	}
	pair<int, int> partition(vector<int>& nums, int left, int right) {
		if (left >= right) {
			return { left,right };
		}
		int less = left - 1, index = left, more = right;
		while (index < more) {
			if (nums[right] == nums[index]) {
				index++;
			}
			else if (nums[right] < nums[index]) {
				swap(nums[--more], nums[index]);
			}
			else {
				swap(nums[++less], nums[index++]);
			}
		}
		swap(nums[right], nums[more]);
		return { less + 1, more };
	}
};
//Iteration
class Solution2 {
public:
	void quickSort(vector<int>& nums) {
		if (nums.size() < 2) return;
		stack<pair<int, int>> s;
		s.push({ 0,nums.size() - 1 });
		while (!s.empty()) {
			pair<int, int> cur = s.top();
			s.pop();
			pair<int, int> ret = partition(nums, cur.first, cur.second);
			if (ret.first > cur.first) {
				s.push({ cur.first,ret.first - 1 });
			}
			if (ret.second < cur.second) {
				s.push({ ret.second + 1,cur.second });
			}
		}
	}
	pair<int, int> partition(vector<int>& nums, int left, int right) {
		if (left >= right) {
			return { left,right };
		}
		int less = left - 1, index = left, more = right;
		while (index < more) {
			if (nums[right] == nums[index]) {
				index++;
			}
			else if (nums[right] < nums[index]) {
				swap(nums[--more], nums[index]);
			}
			else {
				swap(nums[++less], nums[index++]);
			}
		}
		swap(nums[right], nums[more]);
		return { less + 1, more };
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
	S1.quickSort(nums);
}
void algorithm2(vector<int> nums) {
	Solution2 S2;
	S2.quickSort(nums);
}
void Test() {
	Validator().Validate(algorithm1, algorithm2);
}
int main() {
	Test();
	return 0;
}