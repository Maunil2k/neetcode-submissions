class Solution {
public:
    bool dfs(unordered_map<string, vector<string>> &adjl, string src, vector<string> &res, int num_tickets){
        if (res.size() == num_tickets+1) return true;
        if (adjl.find(src) == adjl.end()) return false;
        vector<string> tmp = adjl[src];
        for (int i = 0; i<tmp.size(); i++) {
            adjl[src].erase(adjl[src].begin()+i);
            res.push_back(tmp[i]);
            if (dfs(adjl, tmp[i], res, num_tickets)) return true;
            adjl[src].insert(adjl[src].begin()+i, tmp[i]);
            res.pop_back();
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        unordered_map<string, vector<string>> adjl; 
        for (auto& ticket : tickets) adjl[ticket[0]];
        for (auto &e: tickets) adjl[e[0]].push_back(e[1]);
        vector<string> res = {"JFK"};
        dfs(adjl, "JFK", res, tickets.size());
        return res;
    }
};
