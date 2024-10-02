#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> RotLeft(vector<int> arr, int d) {
        if (d == 0)
            return arr;
            
        vector<int> duplicate(arr.begin(), arr.end());

        for (int i = arr.size() - 1; i >= 0; --i) {
            while (i - d < 0) {
                i = arr.size();
                d = d - i;
            }
            arr[i-d] = duplicate[i];
        }
        return arr;
    }
};

int main() {
    Solution* sol = new Solution();

    vector<int> arr = { 1, 2, 3, 4, 5 };

    vector<int> vec = sol->RotLeft(arr, 4);

    for (auto x : vec) 
        cout << x << " ";

    delete sol;

    return 0;
}

