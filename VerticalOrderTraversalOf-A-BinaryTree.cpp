//https://leetcode.cn/problems/vertical-order-traversal-of-a-binary-tree/
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

class Solution {
    map<int, map<int, vector<int>>> all;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        process(root, 0, 0);
        for (auto i = all.begin(); i != all.end(); i++) {
            vector<int> tmp;
            for (auto j = i->second.begin(); j != i->second.end(); j++) {
                sort(j->second.begin(), j->second.end());
                for (auto val : j->second) {
                    tmp.emplace_back(val);
                }
            }
            ans.emplace_back(tmp);
            tmp.clear();
        }
        return ans;
    }
    void process(TreeNode* root, int step, int deep) {
        if (root) {
            if (all.find(step) == all.end()) {
                all.insert(make_pair(step, map<int, vector<int>>()));
            }
            if (all[step].find(deep) == all[step].end()) {
                all[step].insert(make_pair(deep, vector<int>()));
            }
            all[step][deep].emplace_back(root->val);
            process(root->left, step - 1, deep + 1);
            process(root->right, step + 1, deep + 1);
        }
    }
};

//”≈ªØ
struct Info {
    int val;
    int deep;
    Info(int val, int deep) : val(val), deep(deep){}
};
class comp {
public:
    bool operator()(const Info& a, const Info& b) {
        if (a.deep != b.deep) {
            return a.deep < b.deep;
        }
        return a.val < b.val;
    }
};
class Solution {
    map<int, vector<Info>> all;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
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
