class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;

        while (left <= right) {
            int partition1 = left + (right - left) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            // Handle edge cases by setting extreme values for the partitions
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            // Check if we have found the correct partition
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If the total length is odd, the median is the max of the left partition
                if ((m + n) % 2 == 1) {
                    return max(maxLeft1, maxLeft2);
                }
                // If the total length is even, the median is the average of the max of the left partition
                // and the min of the right partition
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            }
            // Adjust the partition by moving the binary search bounds
            else if (maxLeft1 > minRight2) {
                right = partition1 - 1;
            } else {
                left = partition1 + 1;
            }
        }

        throw invalid_argument("Input arrays are not sorted.");
    }
};