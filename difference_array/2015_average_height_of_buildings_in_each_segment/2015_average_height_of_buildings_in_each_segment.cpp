class Solution {
    using ll = long long;
public:
    vector<vector<int>> averageHeightOfBuildings(vector<vector<int>>& buildings) {
        map<ll, pair<ll, ll>> diff;

        for(auto& b: buildings) {
            diff[b[0]].first += b[2];
            diff[b[1]].first -= b[2];
            diff[b[0]].second++;
            diff[b[1]].second--;
        }

        ll sum = 0, count = 0;
        vector<vector<int>> rets;
        for(auto it = diff.begin(); next(it) != diff.end(); ++it) {
            sum += it->second.first;
            count += it->second.second;
            if(count == 0) continue;
            int left = (int)it->first;
            int right = (int)next(it)->first;
            int val = sum / count;
            if(!rets.empty() && rets.back()[2] == val && rets.back()[1] == left) rets.back()[1] = right;
            else rets.push_back({left, right, val});
        }

        return rets;
    }
};