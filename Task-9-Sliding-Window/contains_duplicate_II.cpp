/*

	Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array 		such that nums[i] == nums[j] and abs(i - j) <= k.

*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> prev;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= nums.size()) return false;
            if (i >= k + 1)
                prev.erase(nums[i - k - 1]);
            if (prev.find(nums[i]) != prev.end()) return true;
            prev.insert(nums[i]);
        }
        return false;
    }
};
