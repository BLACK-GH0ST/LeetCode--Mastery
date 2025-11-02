#include "Leetcode dep.h"

using namespace std;

class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Make sure nums1 is the smaller array to keep binary search on smaller side
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = (int)nums1.size(); // length of nums1
        int n = (int)nums2.size(); // length of nums2

        int left = 0;       // binary search lower bound for partition in nums1
        int right = m;      // binary search upper bound for partition in nums1

        // binary search until we find the correct partition
        while (left <= right) {
            int partition1 = (left + right) / 2;                       // partition index in nums1
            int partition2 = (m + n + 1) / 2 - partition1;            // partition index in nums2 to balance halves

            // If partition at 0, there is no left element; use INT_MIN as sentinel
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            // If partition at end of nums1, there is no right element; use INT_MAX as sentinel
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

            // Same sentinel logic for nums2
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            // Check if we found valid partitions: every left <= every right
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If total length is even, median is avg of max of lefts and min of rights
                if ((m + n) % 2 == 0) {
                    int leftMax = max(maxLeft1, maxLeft2);
                    int rightMin = min(minRight1, minRight2);
                    return (leftMax + rightMin) / 2.0; // return double
                }
                else {
                 // If odd, median is max of left halves
                    return double(max(maxLeft1, maxLeft2));
                }
            }
            // If nums1's left part too big, move partition1 left
            else if (maxLeft1 > minRight2) {
                right = partition1 - 1;
            }
            // Otherwise move partition1 right
            else {
                left = partition1 + 1;
            }
        }

        // Should never reach here if input is valid (sorted arrays)
        return 0.0;
    }
};

// Example main to test locally (LeetCode does not use main; it calls Solution directly)
int main() {
    // test case 1
    vector<int> nums1 = { 1, 3 };
    vector<int> nums2 = { 2 };
    double ans1 = Solution().findMedianSortedArrays(nums1, nums2);
    cout << "Median of {1,3} and {2} = " << ans1 << "\n"; // expected 2

    // test case 2 (even total length)
    vector<int> a = { 1, 2 };
    vector<int> b = { 3, 4 };
    double ans2 = Solution().findMedianSortedArrays(a, b);
    cout << "Median of {1,2} and {3,4} = " << ans2 << "\n"; // expected 2.5

    return 0;
}
