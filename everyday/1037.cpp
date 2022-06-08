// 2022-06-08 每日一题
// 1037. 有效的回旋镖
// 三点各不相同且不在同一条直线上 等价于 两个向量的叉乘结果不为零

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int v1[2] = {points[1][0] - points[0][0], points[1][1] - points[0][1]};
        int v2[2] = {points[2][0] - points[0][0], points[2][1] - points[0][1]};
        return v1[0] * v2[1] - v1[1] * v2[0] != 0;
    }
};