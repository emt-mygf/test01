#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxn = -101, ans = -101;  
        for(auto n : nums) {
            maxn = max(maxn + n, n);
            ans = max(maxn, ans);
        }
        return ans;
    }
};

int main() {
    vector<int> input{-2,1,-3,4,-1,2,1,-5,4};
    int maximun = Solution().maxSubArray(input);
    cout<<maximun<<endl;
    return 0;
}