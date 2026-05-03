#include <unordered_map>
using namespace std;
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> dupli;
        for (int element: nums) {
            if (dupli[element] == 1) return true;
            else dupli[element] = 1;
        }
        return false;
    }
};