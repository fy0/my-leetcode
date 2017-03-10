
#include <algorithm>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        
        if (nums.size() < 3) return 0;
        int minsum = INT_MAX;
        int minkey = INT_MAX;
        // 当target>0，且 sum < target 向右移动a有利于靠近目标
        // 若 target < 0，那么 sum < target 向右移动有利于靠近目标，sum > target 向左移动有利于靠近目标

        for (int i = 0; i < nums.size() - 2; ++i) {
            int a = i + 1;
            int b = nums.size() - 1;
            while (a < b) {
                int sum = nums[i] + nums[a] + nums[b];
                int key = abs(sum - target);
                if (key < minkey) {
                    minkey = key;
                    minsum = sum;
                    if (sum < target) a++;
                    else b--;
                } else if (sum < target) a++;
                else b--;
            }
        }

        return minsum;
    }
};
