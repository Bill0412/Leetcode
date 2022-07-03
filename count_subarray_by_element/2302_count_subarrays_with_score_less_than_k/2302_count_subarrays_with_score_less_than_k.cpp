class Solution {

public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();

        nums.insert(nums.begin(), 0);
        vector<long long> presum(n+1, 0);

        long long ret = 0;

        for(int i = 1; i <= n; ++i) {
            presum[i] = presum[i-1] + nums[i];
        }

        for(int i = 1; i <= n; ++i) {
            if(nums[i] >= k) continue;
            long long left = 1, right = i;

            while(left < right) {
                long long mid = left + (right - left) / 2;

                if((presum[i] - presum[mid-1]) * (i - mid + 1) < k) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }

            ret += (i - left + 1);
        }

        return ret;
    }
};