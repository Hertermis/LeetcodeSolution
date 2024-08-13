/*
员工信息的定义如下

class Employee {
public int happy; // 这名员工可以带来的快乐值
vector<Employee*>subordinates;//这名员工有哪些直接下级
};

公司的每个员工都符合 Employee 类的描述。
整个公司的人员结构可以看作是一棵**标准的**、**没有环**的多叉树。
树的头节点是公司唯一的老板。除老板之外的每个员工都有**唯一**的直接上级。
叶节点是没有任何下属的基层员工(subordinates列表为空)，
除基层员工外，每个员工都有**一个或多个**直接下级。
这个公司现在要办party，你可以决定哪些员工来，哪些员工不来。

规则:

* 如果某个员工来了，那么这个员工的所有直接下级都不能来

* 派对的整体快乐值是所有到场员工快乐值的累加

* 你的目标是让派对的整体快乐值尽量大

给定一棵多叉树的头节点boss且boss!=Null，请返回派对的最大快乐值。

> 1≤n≤500000
> 0≤ℎ𝑎𝑝𝑝𝑦i≤1000
> 输入保证是一棵树
*/


/**
 * Definition for a binary tree node.
 * class Employee {
 * public:
 *     int happy;
 *     vector<Employee*>subordinates;
 * };
 */
class Solution {
public:
	struct Info {
		int comehappiness;
		int nocomehappiness;
		Info(int com, int nocom) :comehappiness(com), nocomehappiness(nocom) {};
	};
	int maxPartyHappiness(Employee* boss) {
		unique_ptr<Info> ans = process(boss);
		return max(ans->comehappiness, ans->nocomehappiness);
	}
	unique_ptr<Info> process(Employee* x) {
		if (x == nullptr) {
			return nullptr;
		}
		int com = x->happy;
		int nocom = 0;
		vector<unique_ptr<Info>> child(x->subordinates.size(), nullptr);
		for (int i = 0; i < x->subordinates.size(); i++) {
			child[i] = process(x->subordinates[i]);
			/*employee x come*/
			com += child[i]->nocomehappiness;
			/*employee x no come*/
			nocom += max(child[i]->comehappiness, child[i]->nocomehappiness);
		}
		unique_ptr<Info> ret(new Info(com, nocom));
		return ret;
	}
};