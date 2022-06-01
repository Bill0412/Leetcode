class Solution {
    int target;
    int n;
    int k;

    bool dfs(vector<int>& nums, int idx, int state, int group, int cur) {
        if(group == k) return true;

        if(cur > target) return false;

        if(cur == target) {
            return dfs(nums, 0, state, group + 1, 0);
        }

        
        int last = -1;
        for(int i = idx; i < n; ++i) {
            if((state>>i)&1) continue;

            if(last == nums[i]) continue;
            last = nums[i];

            if(dfs(nums, i, state + (1 << i), group, cur + nums[i])) return true;
            
        }

        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        this->k = k;
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % k) return false;

        sort(nums.begin(), nums.end(), greater<>());

        n = nums.size();

        target = total / k;

        return dfs(nums, 0, 0, 0, 0);
    }
};