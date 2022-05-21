class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        map<int, int> left2index;
        for(int i = 0; i < n; ++i) {
            left2index[intervals[i][0]] = i;
        }

        vector<int> rets;
        rets.reserve(n);

        for(auto& v: intervals) {
            auto it = left2index.lower_bound(v[1]);

            if(it == left2index.end()) {
                rets.push_back(-1);
            } else {
                rets.push_back(it->second);
            }
        }

        return rets;
    }
};