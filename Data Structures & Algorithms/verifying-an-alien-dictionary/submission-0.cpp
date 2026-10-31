class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> lex(26, 0);
        for (int i = 0; i<26; i++) lex[order[i] - 'a'] = i;

        for (int i = 0; i<words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i+1];
            int n = min(w1.size(), w2.size());
            bool flag = false;
            for (int j = 0; j<n; j++) {
                if (lex[w1[j] - 'a'] > lex[w2[j] - 'a']) return false;
                else if (lex[w1[j] - 'a'] < lex[w2[j] - 'a']) {
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                if (w1.size() > w2.size()) return false;
            }            
        }

        return true;
    }
};