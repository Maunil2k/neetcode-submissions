class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool f=false, s=false, t=false;
        vector<vector<int>> remains;
        for (auto &trip: triplets) {
            if (trip[0] <= target[0] && trip[1]<= target[1] && trip[2]<= target[2]) remains.push_back(trip);
        }
        for (auto &trip: remains) {
            if (trip[0] == target[0]) f = true;
            if (trip[1] == target[1]) s = true;
            if (trip[2] == target[2]) t = true;
        }
        return f && s && t;
    }
};