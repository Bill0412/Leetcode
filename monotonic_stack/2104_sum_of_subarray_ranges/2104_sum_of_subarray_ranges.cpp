class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        vector<long long> stk;
        int n = nums.size();
        vector<long long> leftMin(n), rightMin(n);
        vector<long long> leftMax(n), rightMax(n);
        long long sumMin = 0, sumMax = 0;



        for(int i = 0; i < n; ++i) {
            while(!stk.empty() && nums[stk.back()] > nums[i]) stk.pop_back();
            if(stk.empty()) leftMin[i] = -1;
            else leftMin[i] = stk.back();
            stk.push_back(i);
        }

        stk.clear();

        for(int i = n - 1; i >= 0; --i) {
            while(!stk.empty() && nums[stk.back()] >= nums[i]) stk.pop_back();
            if(stk.empty()) rightMin[i] = n;
            else rightMin[i] = stk.back();
            stk.push_back(i);
        }
        
        stk.clear();

        for(int i = 0; i < n; ++i) {
            while(!stk.empty() && nums[stk.back()] < nums[i]) stk.pop_back();
            if(stk.empty()) leftMax[i] = -1;
            else leftMax[i] = stk.back();
            stk.push_back(i);
        }

        stk.clear();

        for(int i = n - 1; i >= 0; --i) {
            while(!stk.empty() && nums[stk.back()] <= nums[i]) stk.pop_back();
            if(stk.empty()) rightMax[i] = n;
            else rightMax[i] = stk.back();
            stk.push_back(i);
        }

        long long ret = 0;
        for(int i = 0; i < n; ++i) {
            ret += nums[i] * ((rightMax[i] - i) * (i - leftMax[i] ) - (rightMin[i] - i) * (i - leftMin[i]));
        }

        return ret;
    }
};

// sum of max - sum of min
//            i
// X 0 [7 6 (1) 3] 0 X 

// for a number x at index i, how many numbers can it cover as maximum or minimum value?