#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

//本题自然是考虑哈希，需要的是知道哈希的索引应该怎么得出，将字符串排序作为索引很自然，因为我们正好是需要将排序后相同的字符串放一块

class Solution0 {
public:
    //字符串排序后当成key,用哈希
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //统计
        unordered_map<string, vector<string>> memory;
        for(auto str : strs) {
            auto key = str;
            sort(key.begin(), key.end());
            memory[key].emplace_back(str);
        }

        //哈希字典转vector
        vector<vector<string>> ans;
        auto it = memory.begin();
        while(it != memory.end()) {
            ans.emplace_back(it->second);
            ++it;
        }

        return ans;
    }
};

class Solution1 {
public:
    //经典缩减用时方法，一步到位
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> memory;
        memory.reserve(strs.size());
        
        for(auto str : strs) {
            auto key = str;
            sort(key.begin(), key.end());
            if(memory.count(key)) {
                //memory里存的是对应在ans里的索引
                ans[memory[key]].emplace_back(str);
            }
            else {
                //这里比较关键，让memory里存的是对应在ans里的索引，新的key自然放在ans的结尾，所以id=ans.size()
                int id = ans.size();
                memory[key] = id;
                //ans[id].emplace_back(str);
                //上面的写法是错的，vector的[]没有自动申请的功能
                ans.emplace_back(vector<string>{str});
            }
        }

        return ans;
    }
};

int main() {
    vector<string> input{"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> output0 = Solution1().groupAnagrams(input);
    vector<vector<string>> output1 = Solution1().groupAnagrams(input);
    return 0;
}