class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map <int, int> diffs;
        for (int i=0; i<numbers.size(); i++) {
            if (diffs.find(numbers[i]) != diffs.end()) {
                if (numbers[diffs[numbers[i]]] != numbers[i]) return {diffs[numbers[i]]+1, i+1};
            }
            diffs.insert({target - numbers[i], i});
        }
    }
};
