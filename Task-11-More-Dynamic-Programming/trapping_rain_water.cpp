/*

 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 */

class Solution {
public:
    int trap(vector<int>& height) {
        int mx = 0, rain = 0, n = height.size();
        vector<int> pre(n), suff(n);
        for (int i = 0; i < n; i++) {
            if (height[i] > mx) mx = height[i];
            pre[i] = mx;
        }
        mx = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (height[i] > mx) mx = height[i];
            suff[i] = mx;
        }
        for (int i = 0; i < n; i++) rain += min(pre[i], suff[i]) - height[i];
        return rain;
    }
};