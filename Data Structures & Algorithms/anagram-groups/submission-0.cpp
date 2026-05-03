class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ana_maps;

        for (const auto& str: strs) {
            vector<int> count(26, 0);
            for (char c: str) count[c - 'a']++;

            string count_key = "";
            for (auto& c: count) count_key+=to_string(c) + ',';
            ana_maps[count_key].push_back(str);         
        }

        vector<vector<string>> res;
        for (const auto& p: ana_maps) res.push_back(p.second);

        return res;
    }
};
