/*
* #### �и����С����
*
* > һ������г����룬����Ҫ���Ѻͳ�����ֵһ����ͭ��ġ�
* >
* > ���糤��Ϊ20�Ľ�����������ô�У���Ҫ����20��ͭ�塣
* >
* >һȺ�������������������ô����ʡͭ�� ?
* >
* > ���磺��������{ 10,20,30 }������һ�������ˣ�
* >
* > �����������Ϊ60������Ҫ�ֳ�10��20��30��������
* >
* > ����Ȱѳ���60�Ľ����ֳ�10��50������60��
* >
* > �ٰѳ���50�Ľ����ֳ�20��30������50��һ������110ͭ�塣
* >
* > ������Ȱѳ���60�Ľ����ֳ�30��30������60��
* >
* > �ٰѳ���30�����ֳ�10��20������30��һ������90ͭ�塣
* >
* > ����һ�����飬���طָ����С���ۡ�
*/


#include<iostream>
#include<random>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
//����ö��
//����ö��
class Solution1 {
public:
	int theMinimumCostOfCuttingGold(vector<int>& costs) {
		if (costs.size() < 1) {
			return 0;
		}
		return process(costs, 0);
	}
	int process(vector<int> costs, int pre) {
		if (costs.size() == 1) {
			return pre;
		}
		int ans = INT_MAX;
		for (int i = 0; i < costs.size(); i++) {
			for (int j = i + 1; j < costs.size(); j++) {
				int tmp = process(copyAndMergeTwo(costs, i, j), pre + costs[i] + costs[j]);
				ans = tmp > ans ? ans : tmp;
			}
		}
		return ans;
	}
	vector<int> copyAndMergeTwo(vector<int> costs, int i, int j) {
		vector<int> ret(costs.size() - 1);
		int Ri = 0;
		for (int Ai = 0; Ai < costs.size(); Ai++) {
			if (Ai != i && Ai != j) {
				ret[Ri++] = costs[Ai];
			}
		}
		ret[Ri] = costs[i] + costs[j];
		return ret;
	}
};
//̰��
class Solution2 {
public:
	int theMinimumCostOfCuttingGold(vector<int>& costs) {
		priority_queue<int, vector<int>, greater<int>> pq(costs.begin(), costs.end());
		int sum = 0;
		while (pq.size() > 1) {
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();
			sum += a + b;
			pq.push(a + b);
		}
		return sum;
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
#define MAX_LEN 7//���鳤��
#define MIN_VALUE 1//���ݷ�Χ
#define MAX_VALUE 100//���ݷ�Χ
#define MAX_TEST_TIMES 100//������
//Random Test
class Validator {

public:
	vector<int> testCaseGenerate() {
		vector<int> Test;
		random_device rd;
		default_random_engine e(rd());
		uniform_int_distribution<int> len(0, MAX_LEN);
		int length = len(e);
		uniform_int_distribution<int> valRange(MIN_VALUE, MAX_VALUE);
		for (int i = 0; i < length; i++) {
			Test.push_back(valRange(e));
		}
		return Test;
	}
	//void Validate(function<int(string)> func1, function<int(string)> func2) {
	void Validate(int (*func1)(vector<int> num), int (*func2)(vector<int> num)) {
		vector<vector<int>> TestArr;
		for (int i = 0; i < MAX_TEST_TIMES; i++) {
			vector<int> Test = testCaseGenerate();
			TestArr.emplace_back(Test);
		}
		for (int i = 0; i < MAX_TEST_TIMES; i++) {
			vector<int> origin = TestArr[i];
			int ans1 = func1(TestArr[i]);
			int ans2 = func2(TestArr[i]);
			if (ans1 != ans2) {
				cout << "Worry Answer!" << endl;
				cout << "TestArray:";
				printVector(origin);
				cout << endl;
				cout << "TestAlgorithm1_Answer:" << ans1 << endl;
				cout << "TestAlgorithm2_Answer:" << ans2 << endl;
				return;
			}
		}
		cout << "Accepted!" << endl;
	}
};

int algorithm1(vector<int> nums) {
	Solution1 S1;
	return S1.theMinimumCostOfCuttingGold(nums);
}
int algorithm2(vector<int> nums) {
	Solution2 S2;
	return S2.theMinimumCostOfCuttingGold(nums);
}
void Test() {
	Validator().Validate(algorithm1, algorithm2);
}
int main() {
	Test();
	return 0;
}