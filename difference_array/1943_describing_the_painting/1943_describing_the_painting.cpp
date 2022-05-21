class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, long long> diff;

        for(auto& seg: segments) {
            diff[seg[0]] += seg[2];
            diff[seg[1]] -= seg[2];
        }

        long long sum = 0;
        vector<vector<long long>> rets;
        for(auto it = diff.begin(); next(it) != diff.end(); ++it) {
            sum += it->second;
            if(sum != 0) {
                rets.push_back({it->first, next(it)->first, sum});
            }
        }

        return rets;
    }
};
