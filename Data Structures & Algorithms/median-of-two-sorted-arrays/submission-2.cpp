class Solution {
public:
    // Merges two sorted arrays into one sorted array
    vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        long long indxNum1 = 0, indxNum2 = 0;
        vector<int> res;
        
        // Merge the two arrays
        while (indxNum1 < m && indxNum2 < n) {
            if (nums1[indxNum1] < nums2[indxNum2]) {
                res.push_back(nums1[indxNum1++]);
            } else {
                res.push_back(nums2[indxNum2++]);
            }
        }

        // Add remaining elements from nums1
        while (indxNum1 < m) {
            res.push_back(nums1[indxNum1++]);
        }

        // Add remaining elements from nums2
        while (indxNum2 < n) {
            res.push_back(nums2[indxNum2++]);
        }

    
        return res;
    }

    // Finds the median of two sorted arrays
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sorted = merge(nums1, nums1.size(), nums2, nums2.size());
        int size = sorted.size();
        
        if (size % 2 == 0) {
            // For even length, return the average of the two middle elements
            return (sorted[size / 2 - 1] + sorted[size / 2]) / 2.0;
        } else {
            // For odd length, return the middle element
            return sorted[size / 2];
        }
    }
};