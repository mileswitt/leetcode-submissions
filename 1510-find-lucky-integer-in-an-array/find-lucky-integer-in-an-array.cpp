class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> hm;

        for (auto& n : arr) {
            hm[n]++;
        }

        int res = -1;

        for (auto& [num, count] : hm) {
            if (num == count) {
                res = max(res, num);
            }
        }
        return res;
    }
};