#include<iostream>
#include<random>
#include<vector>
using namespace std;
void printVector(vector<int> nums);
class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};
//暴力解
class Solution1 {
public:
	ListNode* partition(ListNode* head, int x) {
		if (!head) return nullptr;
		vector<int> container;
		ListNode* cur = head;
		while (cur) {
			container.push_back(cur->val);
			cur = cur->next;
		}
		cur = head;
		sort(container.begin(), container.end());
		for (int i = 0; i < container.size(); i++) {
			if (cur) {
				cur->val = container[i];
				cur = cur->next;
			}
		}
		return head;
	}
};




//最优解
class Solution2 {
public:
	ListNode* partition(ListNode* head, int x) {
		if (!head) return nullptr;
		ListNode* lesBegin = nullptr, * lesEnd = nullptr;
		ListNode* equBegin = nullptr, * equEnd = nullptr;
		ListNode* morBegin = nullptr, * morEnd = nullptr;
		ListNode* cur = head;
		//partition
		while (cur) {
			if (cur->val < x) {
				if (!lesBegin) {
					lesBegin = cur;
					lesEnd = cur;
				}
				else {
					lesEnd->next = cur;
					lesEnd = lesEnd->next;
				}
			}
			else if (cur->val == x) {
				if (!equBegin) {
					equBegin = cur;
					equEnd = cur;
				}
				else {
					equEnd->next = cur;
					equEnd = equEnd->next;
				}
			}
			else {
				if (!morBegin) {
					morBegin = cur;
					morEnd = cur;
				}
				else {
					morEnd->next = cur;
					morEnd = morEnd->next;
				}
			}
			cur = cur->next;
		}
		//merge
		if (lesEnd) lesEnd->next = equBegin != nullptr ? equBegin : morBegin;
		if (equEnd) equEnd->next = morBegin;
		if (morEnd) morEnd->next = nullptr;
		return lesBegin != nullptr ? lesBegin : equBegin != nullptr ? equBegin : morBegin;
	}
};






void deleteHead(ListNode* head) {
	ListNode* cur = head;
	while (cur) {
		ListNode* temp = cur;
		cur = cur->next;
		delete temp;
	}
	head = nullptr;
}
ListNode* copeList(ListNode* head) {
	if (!head) return nullptr;
	ListNode* cur = head;
	ListNode* newHead = nullptr;
	ListNode* newCur = newHead;
	while (cur) {
		if (!newHead) {
			newHead = new ListNode(cur->val);
			newCur = newHead;
		}
		else {
			newCur->next = new ListNode(cur->val);
			newCur = newCur->next;
		}
		cur = cur->next;
	}
	return newHead;
}
void printVector(vector<int> nums) {
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
}
vector<int> ToVector(ListNode* head) {
	vector<int> ans;
	ListNode* cur = head;
	while (cur) {
		ans.push_back(cur->val);
		cur = cur->next;
	}
	return ans;
}
#include<tuple>
#define MAX_LEN 20//数组长度
#define MIN_VALUE -25//数据范围
#define MAX_VALUE 25//数据范围
#define MAX_TEST_TIMES 500//样本量
//Random Test
class Validator {

public:
	pair<tuple<ListNode*, ListNode*, int>, vector<int>> testCaseGenerate() {
		random_device rd;
		default_random_engine e(rd());
		uniform_int_distribution<int> len(0, MAX_LEN);
		int length = len(e);
		if (length == 0) return make_pair(make_tuple(nullptr, nullptr, 0), vector<int>());
		ListNode* head = nullptr;
		vector<int> Tmp(length, 0);
		uniform_int_distribution<int> valRange(MIN_VALUE, MAX_VALUE);
		for (int i = 0; i < length; i++) {
			Tmp[i] = valRange(e);
		}
		head = new ListNode(Tmp[0]);
		ListNode* cur = head;
		for (int i = 1; i < length; i++) {
			cur->next = new ListNode(Tmp[i]);
			cur = cur->next;
		}
		ListNode* cophead = copeList(head);
		uniform_int_distribution<int> mustHaveTarget(0, 1);
		int target = 0;
		if (mustHaveTarget(e)) {
			do {
				target = len(e);
			} while (target >= length);
			target = Tmp[target];
		}
		else {
			target = valRange(e);
		}
		return make_pair(make_tuple(head, cophead, target), Tmp);
	}
	//void Validate(function<int(string)> func1, function<int(string)> func2) {
	void Validate(ListNode* (*func1)(ListNode*, int), ListNode* (*func2)(ListNode*, int)) {
		bool pass = true;
		vector<vector<int>> origin;
		vector<tuple<ListNode*, ListNode*, int>> TestArr;
		for (int i = 0; i < MAX_TEST_TIMES; i++) {
			auto Test = testCaseGenerate();
			TestArr.emplace_back(Test.first);
			origin.push_back(Test.second);
		}
		for (int i = 0; i < MAX_TEST_TIMES; i++) {
			ListNode* Ans1 = func1(get<0>(TestArr[i]), get<2>(TestArr[i]));
			vector<int> ans1 = ToVector(Ans1);
			ListNode* Ans2 = func2(get<1>(TestArr[i]), get<2>(TestArr[i]));
			vector<int> ans2 = ToVector(Ans2);
			if (ans1.size() == origin[i].size() && ans2.size() == origin[i].size()) {
				int ans1left = 0, ans2left = 0, j = 0;
				for (j = 0; j < ans1.size(); j++) {
					if (ans1[j] < get<2>(TestArr[i])) {
						ans1left++;
					}
					if (ans2[j] < get<2>(TestArr[i])) {
						ans2left++;
					}
					if (ans1left != ans2left) {
						cout << "Worry Answer!" << endl;
						cout << "TestList:";
						for (int j = 0; j < origin[i].size(); j++) {
							cout << origin[i][j] << " ";
						}
						cout << endl;
						cout << "TestTarget:" << get<2>(TestArr[i]) << endl;
						cout << "Answer1:";
						printVector(ans1);
						cout << endl;
						cout << "Answer2:";
						printVector(ans2);
						cout << endl;
						pass = false;
						break;
					}
				}
			}
			else {
				cout << "Worry Answer!" << endl;
				cout << "TestList:";
				for (int j = 0; j < origin[i].size(); j++) {
					cout << origin[i][j] << " ";
				}
				cout << endl;
				cout << "TestTarget:" << get<2>(TestArr[i]) << endl;
				cout << "Answer1:";
				printVector(ans1);
				cout << endl;
				cout << "Answer2:";
				printVector(ans2);
				cout << endl;
				pass = false;
				break;
			}
			deleteHead(Ans1);
			deleteHead(Ans2);
		}
		if (pass) cout << "Accept!" << endl;
	}
};
ListNode* algorithm1(ListNode* head, int x) {
	Solution1 S1;
	return S1.partition(head, x);
}
ListNode* algorithm2(ListNode* head, int x) {
	Solution2 S2;
	return S2.partition(head, x);
}
void Test() {
	Validator().Validate(algorithm1, algorithm2);
}
int main() {
	Test();
	return 0;
}