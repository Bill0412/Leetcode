class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        vector<int> diffArray(n+1, 0);

        for(auto& light: lights) {
            int pos = light[0], range = light[1];
            int a = max(0, pos - range);
            int b = min(n - 1, pos + range);

            diffArray[a]++;
            diffArray[b+1]--;
        }

        int sum = 0, ret = 0;

        for(int i = 0; i < n; ++i) {
            sum += diffArray[i];
            if(sum >= requirement[i]) ++ret;
        }

        return ret;
    }
};