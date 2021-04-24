//方案一，保存数据的递归，回避重复调用复杂度高的问题
class Solution {
public:
    map<int,int> saved_dict;
    int combinationSum4(vector<int>& nums, int target) {
        map<int,int>::iterator it = saved_dict.find(target);
        if(it != saved_dict.end()) return it->second;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(target>nums[i]) ans+=combinationSum4(nums, target-nums[i]);
            else if(target==nums[i]) ans+=1;
        }
        saved_dict[target] = ans;
        return ans;

    }
};

//方案二，dp会出现中间某些数过大超出范围，直接写个判决回避掉（因为结果不会超，所以这些铁没用）
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp;
        for(int i=0;i<target;i++){
            dp.push_back(0);
            for(int j=0;j<nums.size();j++){
                if(i>=nums[j]) {
                    if(dp[i] > INT_MAX/2) break;
                    dp[i]+=dp[i-nums[j]];
                }
                else if(i==nums[j]-1) {
                    if(dp[i] > INT_MAX/2) break;
                    dp[i]+=1;
                }
            }
        }

        return dp.back();

    }
};