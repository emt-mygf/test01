//子集个数为(每种元素个数+1)求积
//统计每种元素个数用字典来做

class Solution {
public:
    map<int,int> mydict;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //建一个统计元素个数的字典
        vector<int>::iterator it1 = nums.begin();
        map<int,int>::iterator it2;
        while(it1 != nums.end()){
            it2 = mydict.find(*it1);
            if(it2 != mydict.end()) it2->second += 1;
            else mydict.insert(pair<int,int>(*it1,1));
            it1++;
        }
        
        map<int,int>::iterator it3 = mydict.begin();
        vector<vector<int>> answer;
        vector<int> nu;
        answer.push_back(nu);

        while(it3!=mydict.end()){
            int k = it3->first;
            int count = it3->second;
            int l = answer.size();
            for(int j = 0; j < l; j++){
                vector<int> s = answer[j];
                for(int i = 0; i < count; i++){
                    s.push_back(k);
                    answer.push_back(s);
                }
            }
            it3++;
        }

        return answer;        
    }
};