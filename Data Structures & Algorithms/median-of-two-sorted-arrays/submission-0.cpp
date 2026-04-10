class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();

        // merge two sorted arrays
        while (i < n && j < m) {
            if (nums1[i] < nums2[j])
                nums3.push_back(nums1[i++]);
            else
                nums3.push_back(nums2[j++]);
        }

        // push remaining elements
        while (i < n) nums3.push_back(nums1[i++]);
        while (j < m) nums3.push_back(nums2[j++]);

        int total = n + m;

        // If odd, return middle element
        if (total % 2 == 1)
            return nums3[total / 2];

        // If even, return average of two middle elements
        return (nums3[total / 2 - 1] + nums3[total / 2]) / 2.0;
    }
};
