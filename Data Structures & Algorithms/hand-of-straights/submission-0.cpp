class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        unordered_map<int, int> counts;
        for (auto &h: hand) {
            if (counts.find(h) == counts.end()) {
                counts[h] = 1;
                minHeap.push(h);
            }
            else counts[h]+=1;
        }

        int num_groups = hand.size() / groupSize;
        for (int i = 0; i<num_groups; i++) {
            int start;
            for (int j = 0; j<groupSize; j++) {
                if (j == 0) {
                    while (1) {
                        if (counts[minHeap.top()] == 0) minHeap.pop();
                        else break;
                    }
                    start = minHeap.top();
                    counts[start] -= 1;
                    if (counts[start] == 0) minHeap.pop();
                }

                else {
                    start++;
                    if (!counts[start]) return false;
                    counts[start]-=1;
                }
            }
        }
        return true;
    }
};
