class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> pos_time;
        for (int i=0; i<position.size(); i++) 
            pos_time.push_back({position[i], (float)(target - position[i])/ speed[i]});
        
        sort(pos_time.begin(), pos_time.end());
        // for (int i=0; i<pos_time.size(); i++){
        //     cout<<"first: "<<pos_time[i].first<<" second: "<<pos_time[i].second<<endl;
        // }
        int fleets = 1;
        float curr_max_time = pos_time.back().second;
        for (int i=pos_time.size()-2; i>=0; i--) {
            if (pos_time[i].second > curr_max_time) {
                fleets++;
                curr_max_time = pos_time[i].second;
            }
        }

        return fleets;
    }
};
