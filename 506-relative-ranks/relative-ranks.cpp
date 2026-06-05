class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> res(score.size(), "");
        // value and position
        priority_queue<pair<int, int>> maxHeap;
        int n = score.size();

        for (int i = 0; i < n; i++) {
            maxHeap.push({score[i], i});
        }

        int rank = 1;
        while (!maxHeap.empty()) {
            auto [val, index] = maxHeap.top();
            maxHeap.pop();

            if (rank == 1) {
                res[index] = "Gold Medal";
            } else if (rank == 2) {
                res[index] = "Silver Medal";
            } else if (rank == 3) {
                res[index] = "Bronze Medal";
            } else {
                res[index] = to_string(rank);
            }
            rank++;
        }
        return res;
    }
};