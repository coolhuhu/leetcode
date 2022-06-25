2022-06-17 每日一题  双指针

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int top = 0;
        int i = -1;
        while (top < n) {
            ++i;
            if (arr[i] == 0) {
                top += 2;
            }
            else {
                top++;
            }
        }
        int j = n - 1;
        // 此刻 top >= n;若arr[n-1]==0，则top+2导致top==n+1
        if (top == n+1) {
            arr[j] = 0;
            j--;
            i--;
        }
        while (j >= 0) {
            arr[j] = arr[i];
            j--;
            if (arr[i] == 0) {
                arr[j] = 0;
                j--;
            }
            i--;
        }
    }
};