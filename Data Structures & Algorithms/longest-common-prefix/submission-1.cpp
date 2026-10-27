class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for (int i = 0; i<strs[0].length(); i++) {
            for (int j = 0; j< strs.size(); j++) {
                if (i == strs[j].length() || strs[j][i] != strs[0][i]) {
                    return strs[j].substr(0, i);
                }
            }
        }
    }
};