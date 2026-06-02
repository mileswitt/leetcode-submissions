class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) {
            return false;
        }

        int divider = 1;

        while (x / divider >= 10) {
            divider *= 10;
        }

        while (x > 0) {
            int right = x % 10;
            int left = x / divider;
            if (left != right) {
                return false;
            }
            // chop off left and right most digits
            x = (x % divider) / 10;
            // chop off 2 digits
            divider = divider / 100;
        }
        return true;
    }
};