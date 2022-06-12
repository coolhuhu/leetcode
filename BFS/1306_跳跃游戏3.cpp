// 广度优先或深度优先


class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> que;
        que.push(start);
        vector<bool> visited(n, false);
        visited[start] = true;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                int node = que.front();
                if (arr[node] == 0) {
                    return true;
                }
                que.pop();
                if (arr[node] + node < n && !visited[arr[node] + node]) {
                    que.push(arr[node] + node);
                    visited[arr[node] + node] = true;
                }
                if (node - arr[node] >= 0 && !visited[node - arr[node]]) {
                    que.push(node - arr[node]);
                    visited[node - arr[node]] = true;
                }
            }
        }
        return false;
    }
};