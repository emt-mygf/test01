// 二进制，状态机，00->11->10->00
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for (auto x: nums){
            int u = (a ^ x) | (a & b);
            int v = (b & ~x) | (x & ~a);
            a = u;
            b = v;
        }
        return b;
    }
};