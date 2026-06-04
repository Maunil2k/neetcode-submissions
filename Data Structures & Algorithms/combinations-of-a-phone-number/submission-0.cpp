class Solution {
private:
    map<char, vector<char>> myMap;
    void populateMap() {
        myMap.insert({'2', {'a', 'b', 'c'}});
        myMap.insert({'3', {'d', 'e', 'f'}});
        myMap.insert({'4', {'g', 'h', 'i'}});
        myMap.insert({'5', {'j', 'k', 'l'}});
        myMap.insert({'6', {'m', 'n', 'o'}});
        myMap.insert({'7', {'p', 'q', 'r', 's'}});
        myMap.insert({'8', {'t', 'u', 'v'}});
        myMap.insert({'9', {'w', 'x', 'y', 'z'}});
    }
    vector<string> res;
    void dfs(int idx, string &digits, string &curr) {
        // idx represents the current index of the string
        if (idx >= digits.size()) {
            if (curr.size() == digits.size()) res.push_back(curr);
            return;
        }


        for (int i = idx; i<digits.size(); i++) {
            for (auto chars: myMap[digits[i]]) {
                curr.push_back(chars);
                dfs(i+1, digits, curr);
                curr.pop_back();
            }
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        string curr;
        populateMap();
        dfs(0, digits, curr);
        if (res.size() == 1) return {}; 
        return res;
    }
};
