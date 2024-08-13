//https://leetcode.cn/problems/binary-tree-vertical-order-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
struct Info {
    int val;
    int deep;
    Info(int v, int dep) : val(v), deep(dep) {}
};
class comp {
public:
    bool operator()(const Info& a, const Info& b) {
        return a.deep < b.deep;
    }
};
class Solution {
    map<int, vector<Info>> all;
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        process(root, 0, 0);
        for (auto i = all.begin(); i != all.end(); i++) {
            vector<int> tmp;
            sort(i->second.begin(), i->second.end(), comp());
            for (auto j : i->second) {
                tmp.emplace_back(j.val);
            }
            ans.emplace_back(tmp);
            tmp.clear();
        }
        return ans;
    }
    void process(TreeNode* root, int step, int deep) {
        if (root) {
            if (all.find(step) == all.end()) {
                all.insert(make_pair(step, vector<Info>()));
            }
            all[step].emplace_back(Info(root->val, deep));
            process(root->left, step - 1, deep + 1);
            process(root->right, step + 1, deep + 1);
        }
    }
};
