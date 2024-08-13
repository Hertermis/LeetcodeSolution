//https://leetcode.cn/problems/group-anagrams/description/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> ansM;
        for (string str : strs) {
            int cnts[26] = { 0 };
            for (char c : str) {
                cnts[c - 'a']++;
            }
            string key = "";
            for (int i = 0; i < 26; ++i) {
                if (cnts[i] != 0) {
                    key.push_back(i + 'a');
                    key.push_back(cnts[i]);
                }
            }
            ansM[key].push_back(str);
        }
        if (!ansM.empty()) {
            for (auto p : ansM) {
                ans.emplace_back(p.second);
            }
        }
        return ans;
    }
};