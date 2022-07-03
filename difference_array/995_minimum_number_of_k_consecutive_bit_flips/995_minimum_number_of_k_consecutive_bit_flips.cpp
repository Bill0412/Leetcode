class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> diff(n+1, 0);

        int sum = 0;
        int ret = 0;
        for(int i = 0; i < n; ++i) {
            sum += diff[i];

            if((sum + nums[i]) % 2 == 1) continue;

            if(i > n - k) {
                return -1;
            }

            diff[i+k]--;
            sum++;
            ret++;
        }

        return ret;
    }
};