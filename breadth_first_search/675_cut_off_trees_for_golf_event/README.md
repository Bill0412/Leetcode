# 675. Cut Off Trees for Golf Event

In the C++ Version, during the BFS, we need to record the visited cells to avoid TLE. If we use `unordered_set` here, TLE will happen. Using `vector` can avoid this problem.


## References
1. https://www.youtube.com/watch?v=j8CychBmsvA