//https://leetcode.cn/problems/compare-version-numbers/
class Solution {
public:
	int compareVersion(string version1, string version2) {
		int pos1 = 0;
		int pos2 = 0;
		while (pos1 < version1.length() || pos2 < version2.length()) {
			while (pos1 < version1.length() && version1[pos1] == '.') {
				pos1++;
			}
			while (pos2 < version2.length() && version2[pos2] == '.') {
				pos2++;
			}
			string s1 = "", s2 = "";
			while (pos1 < version1.length() && version1[pos1] != '.') {
				s1 += version1[pos1];
				pos1++;
			}
			while (pos2 < version2.length() && version2[pos2] != '.') {
				s2 += version2[pos2];
				pos2++;
			}
			int ints1 = s1 == "" ? 0 : stoi(s1);
			int ints2 = s2 == "" ? 0 : stoi(s2);
			if (ints1 > ints2) {
				return 1;
			}
			else if (ints1 < ints2) {
				return -1;
			}
		}
		return 0;
	}
};