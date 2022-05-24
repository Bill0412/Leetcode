class Solution {
    int m, n;
    using ai3 = array<int, 3>;
    using pii = pair<int, int>;
    vector<int> dirs;
public:
    int cutOffTree(vector<vector<int>>& forest) {
        m = forest.size();
        n = forest[0].size();
        vector<ai3> heights;
        heights.reserve(m * n);
        dirs = {-1, 0, 1, 0, -1};
        
        int minRow = -1;
        int minCol = -1;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(forest[i][j] > 1) heights.push_back({forest[i][j], i, j}); 
            }
        }
        sort(heights.begin(), heights.end());

        if(heights[0][0] == 0) return -1;
        if(!(heights[0][1] == 0 && heights[0][2] == 0)) heights.insert(heights.begin(), {-1, 0, 0});

        // find out the shortest distance between each of these consecutive points
        int ret = 0;
        
        for(int i = 0; i < heights.size() - 1; ++i) {
            auto [h1, x1, y1] = heights[i];
            auto [h2, x2, y2] = heights[i+1];
            queue<pii> q;
            vector<vector<int>> visited(m, vector<int>(n, 0));
            q.push({x1, y1});

            int count = -1;
            bool isFound = false;

            while(!q.empty() && !isFound) {
                int size = q.size();
                count++;
                
                while(size--) {
                    auto [x, y] = q.front();
                    q.pop();

                    if(visited[x][y]) continue;
                    visited[x][y] = 1;

                    if(x == x2 && y == y2) {
                        isFound = true;
                        break;
                    }

                    for(int j = 0; j < 4; ++j) {
                        int nx = x + dirs[j];
                        int ny = y + dirs[j+1];
                        if(nx < 0 || ny < 0 || nx >= m || ny >= n || forest[nx][ny] == 0 || visited[nx][ny]) continue;
                        q.push({nx, ny});
                    }
                }
            }
            if(!isFound) return -1;
            ret += count;
        }

        return ret;
    }
};


// 2 3 4
// 0 0 5
// 8 7 6


// 4 2 3
// 0 0 1
// 7 6 5


// 1 should be ignored!
// 4->2: 1
// 2->3: 1
// 3->4: 2
// 4->5: 4
// 5->6: 1
// 6->7: 1