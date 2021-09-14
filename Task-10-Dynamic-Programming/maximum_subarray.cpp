/*

	Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest 		sum and return its sum.

	A subarray is a contiguous part of an array.

*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxx = -1e6, curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr = max(curr + nums[i], nums[i]);
            maxx = max(maxx, curr);
        }
        return maxx;
    }
};
