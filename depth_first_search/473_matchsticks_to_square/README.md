# 473. Matchsticks to Square

This problem can be both solved using state compression and dfs, because 4 equal parts is required, where 4 is a special number, which is (1<<2). And it means that we can firstly divided it into 2 parts, then further divide each of them to 2 part, and check if such a solution exists.