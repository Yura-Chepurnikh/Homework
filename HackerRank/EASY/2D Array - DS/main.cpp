#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

class Solution {
public:
    int GetMaxHourGlassSum(vector<vector<int>> arr) {
        GetMaxHourGlassSumRec(0, 0, arr);
        return maxSum;
    }
private:
    int maxSum = INT_MIN;
    void GetMaxHourGlassSumRec(int row, int col, vector<vector<int>>& arr) {
        if (row >= arr[0].size() - 3 && col >= arr[0].size() - 3) {
            return;
        }

        int sum = 0;
        for (int i = 0; i < row + 3; ++i) {
            for (int j = 0; j < col + 3; ++j) {
                sum += arr[i][j];
            }
        }
        if (sum > maxSum)
            maxSum = sum;

        if (row < arr[0].size() - 3)
            GetMaxHourGlassSumRec(row + 1, col, arr);
        if (col < arr[0].size() - 3)
            GetMaxHourGlassSumRec(row, col + 1, arr);
    }
};

// Test
int main() {
    Solution* sol = new Solution();
    
    vector<vector<int>> arr = {
        { 1, 1, 1, 0, 0, 0, },
        { 0, 1, 0, 0, 0, 0, },
        { 1, 1, 1, 0, 0, 0, },
        { 0, 0, 0, 0, 0, 0, },
        { 0, 0, 0, 0, 0, 0, },
        { 0, 0, 0, 0, 0, 0, },
    };

    cout << sol->GetMaxHourGlassSum(arr);
    
    delete sol;
    return 0;
}