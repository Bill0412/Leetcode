class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> diff;

        for(auto& flower: flowers) {
            diff[flower[0]]++;
            diff[flower[1]+1]--;
        }

        map<int, int> counts;
        int sum = 0;
        for(auto it = diff.begin(); it != diff.end(); ++it) {
            sum += it->second;
            counts[it->first] = sum;
        }

        vector<int> rets;
        for(int person: persons) {
            auto it = counts.upper_bound(person);
            if(it == counts.begin()) rets.push_back(0);
            else rets.push_back(prev(it)->second);
        }

        return rets;
    }
};


// [1, 2]: 1
// [3, 3]: 2
// [4, 10]: 1