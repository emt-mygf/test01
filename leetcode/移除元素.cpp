//两个指针
//1、都从前往后，q用于记数和改变向量，p用于寻找非val的值
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()){
            return 0;
        }
        int n = 0;
        vector<int>::iterator p = nums.begin();
        vector<int>::iterator q = nums.begin();
        while(p != nums.end()){
            while(*p == val){
                p++;
                if(p == nums.end()) return n;
            }
            *q = *p;
            p++;
            q++;
            n++;
        }
        return n;

    }
};

//1、从前往后与从后往前，p用于记数和改变向量，q用于寻找非val的值
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()){
            return 0;
        }
        int n = 0;
        vector<int>::iterator p = nums.begin();
        vector<int>::iterator q = nums.end()-1;
        while(p != nums.end()){
            n++;
            if(*p == val){
                n--;
                while(q > p){
                    if(*q != val){
                        *p = *q;
                        q--;
                        break;
                    }
                    q--;
                }
            }
            p++;
        }
        return n;

    }
};