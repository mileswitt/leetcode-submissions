class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> maxHeap;
        vector<int> res;

        for (int i = 0; i < stones.size(); i++) {
            maxHeap.push(stones[i]);
        }


        while (maxHeap.size() != 1) {
            auto stone1 = maxHeap.top();
            maxHeap.pop();
            auto stone2 = maxHeap.top();
            maxHeap.pop();

            maxHeap.push(stone1 - stone2);
        }
        res.push_back(maxHeap.top());
        return res[0];
        
    }
};