
#include "Leetcode dep.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // value -> index

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            if (seen.find(complement) != seen.end()) {
                return { seen[complement], i };
            }

            seen[nums[i]] = i;
        }

        return {}; // fallback (though problem guarantees one)
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;

    vector<int> result = solution.twoSum(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
