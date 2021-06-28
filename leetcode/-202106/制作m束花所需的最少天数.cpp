//二分法：直接求解难，头尾容易找，判断容易实现

class Solution {
public:
    bool judge(vector<int>& bloomDay, int m, int k, int n){
        int l = bloomDay.size();
        int f = 0;
        int count = 0;
        for(int i = 0; i < l; ++i){
            if(bloomDay[i] <= n){
                ++count;
                if(count == k){
                    count = 0;
                    ++f;
                    if(f == m) return true;
                }
            }
            else count = 0;
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int l =bloomDay.size();
        if(l < m*k) return -1;

        int left = 0;
        int right = 0;
        for(int i = 0; i < l; ++i){
            if (right < bloomDay[i]) right = bloomDay[i];
        }

        int mid = (left+right)/2;
        while(left<right-1){
            if(judge(bloomDay,m,k,mid)){
                right = mid;
                mid = (left+right)/2;
            }
            else{
                left = mid;
                mid = (left+right)/2;
            }
        }
        return right;

    }
};