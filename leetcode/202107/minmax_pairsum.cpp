#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto it1 = nums.begin();
        auto it2 = nums.end();
        --it2;

        int ans = 0;
        while(it1 < it2) {
            ans = max(ans, *it1+*it2);
            ++it1;
            --it2;
        }

        return ans;
    }
};

int main() {
    vector<int> input{3,5,2,3};
    auto ans = Solution().minPairSum(input);
    cout<<ans<<endl;
}