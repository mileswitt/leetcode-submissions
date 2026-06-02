class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> symb = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && symb[s[i]] < symb[s[i + 1]]) {
                res -= symb[s[i]];
            } else {
                res += symb[s[i]];
            }
        }
        return res;
    }
};