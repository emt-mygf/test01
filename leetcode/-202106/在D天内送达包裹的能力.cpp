//带记忆的递归，超时
class Solution {
public:   
    map<pair<int,int>,int> memory;
    int shipWithinDays(vector<int>& weights, int D) {
        //输入的weights尾巴保持不变，变的是头部，因此长度就可以标记序列是哪一个了
        pair<int,int> ind = {weights.size(),D};
        if(memory.find(ind) != memory.end()) return memory[ind];
        int sum = 0;
        int ans = INT_MAX; 
        int Ds = --D;
        if(Ds == 0){
            for(int i=0;i < weights.size();++i){
                sum += weights[i];
            }
            return sum;
        }
        for(int i=0;i < weights.size();++i){
            sum += weights[i];
            if(sum > ans) break;
            vector<int> myweights;
            for(int j=i+1;j < weights.size();++j){
                myweights.push_back(weights[j]);
            }
            ans = min(ans,max(sum,shipWithinDays(myweights, Ds)));
        }
        memory[ind] = ans;
        return ans;
    }
};

//属于二分查找，之前没见过，没想到
//什么情况下可用二分查找：目标是返回一个值，而且给定一个值，能够写一个函数，判断给定值和目标值的大小比较
class Solution {
public:
    bool judge(vector<int>& weights, int D, int ans){
        int sum = 0;
        int Days = 0;
        vector<int>::iterator it = weights.begin();
        while(it != weights.end()){
            while(sum <= ans && it != weights.end()){
                sum+=*it;
                ++it;
            }
            //如果是sum超出跳出循环的，则清零sum,增加Days,回退it;如果是到头了，则增加Days;如果到头时超了，一样清零回退
            if(sum > ans){
                sum = 0;
                ++Days;
                --it;
            }
            else ++Days;
        }
        return Days<=D ? true:false;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int l = 0;
        int r = 0;
        for(int i=0; i<weights.size(); ++i){
            r+=weights[i];
            l=max(l,weights[i]);
        }
        
        while(l<r-1){
            int m = (l+r)/2;
            if(judge(weights,D,m)) r=m;
            else l=m;
        }
        //注意边界条件
        return judge(weights,D,l)? l:r;      
    }
};