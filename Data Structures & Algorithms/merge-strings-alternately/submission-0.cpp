class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int s1 = word1.size(), s2 = word2.size();
        int i = 0, j = 0;
        string ans = "";
        while (i<s1 && j<s2) {
            ans += word1[i];
            ans += word2[j];
            i++;
            j++;
        }

        if (i == s1) ans += word2.substr(j, s2+1);
        else ans += word1.substr(i, s1+1);
        return ans;
    }
};