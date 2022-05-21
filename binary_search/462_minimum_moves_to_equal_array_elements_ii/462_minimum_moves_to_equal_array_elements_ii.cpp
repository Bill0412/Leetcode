class Solution {
    bool isLeftCountSmallerOrEqual(vector<int>& nums, int n) {
        int cnt = 0;
        for(int x: nums) {
            if(x < n) cnt++;
        }
        return cnt <= nums.size() - cnt;
    }
public:
    int minMoves2(vector<int>& nums) {
        int left = *min_element(nums.begin(), nums.end()), right = *max_element(nums.begin(), nums.end());

        while(left < right) {
            int mid = right - (right - left) / 2;

            if(isLeftCountSmallerOrEqual(nums, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        int ret = 0;

        for(int x: nums) {
            ret += abs(x - left);
        }

        return ret;
    }
};


// => find the median
// => find a number, such that the left side has equal number as right side