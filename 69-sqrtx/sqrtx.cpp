class Solution {
public:
    int mySqrt(int x) {

        int l = 1;
        int r = x;

        while (l <= r) {
            int m = l + ((r - l) / 2);
            long m_squared = (long)m * m;
            if (m_squared == x) {
                return m;
            } else if (m_squared < x) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return r;
        
    }
};