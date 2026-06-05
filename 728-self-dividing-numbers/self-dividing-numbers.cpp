class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {

        vector<int> res;

        for (int n = left; n <= right; n++) {
            if (isDivisible(n)) {
                res.push_back(n);
            }
        }
        return res;
    }

    bool isDivisible(int n) {
        for (char c : to_string(n)) {
            // check if 
            if (c == '0' || n % (c - '0') != 0) {
                return false;
            }
        }
        return true;
    }
};