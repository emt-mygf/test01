#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

//解1，简单题，没啥，把string可以当成栈来用，学了下c++的string模板的一点相关函数
class Solution {
public:
    string removeDuplicates(string S) {
        string result;
        result.push_back(S.at(0));
        int l = S.length();
        if(l == 1) return result;
        for(int i = 1;i < l;i++){
            string::iterator e = result.end()-1;
            if((*e) == S.at(i)) result.erase(e);
            else result.push_back(S.at(i));
        }
        return result;
    }
};