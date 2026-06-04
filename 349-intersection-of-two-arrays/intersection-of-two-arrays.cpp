class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        int left = 0;
        int right = 0;
        set<int> uniq;
        vector<int> res;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        while (left < nums1.size() && right < nums2.size() ) {
            if (nums1[left] < nums2[right]) {
                left++;
            }else if (nums1[left] > nums2[right]) {
                right++;
            } else if (nums1[left] == nums2[right]) {
                uniq.insert(nums1[left]);
                right++;
                left++; 
            }
        }

        for (const auto& num : uniq) {
            res.push_back(num);
        }
        return res;
        
    }
};