// 广度优先或深度优先


class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        return dfs(arr, visited, start, n);
    }

    bool dfs(vector<int>& arr, vector<bool>& visited, int index, int n) {
        if (index < 0 || index >= n || visited[index]) {
            return false;
        }
        if (arr[index] == 0) {
            return true;
        }
        visited[index] = true;
        return dfs(arr, visited, index + arr[index], n) || dfs(arr, visited, index - arr[index], n);
    }
};