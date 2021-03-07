#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

//解1，使用迭代，时间空间占用都大

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> a;
        
        int len = s.length();
        //迭代终止条件
        if(len == 1){
            vector<string> b;
            b.push_back(s);
            a.push_back(b);
            return a;
        }
        //cout<<"len="<<len<<endl;
        for(int i = 1; i < len; i++)
        {
            //cout<<"i="<<i<<endl;
            if(ispartition(s.substr(0,i)))
            {
                //cout<<s.substr(0,i)<<endl;
                vector<vector<string>> a1 = partition(s.substr(i));
                vector<vector<string>>::iterator v1 = a1.begin();
                while(v1 != a1.end())
                {
                    (*v1).insert((*v1).begin(),s.substr(0,i));
                    a.push_back(*v1);
                    v1++;
                }
            }
        }
        //s.substr()==[]的特殊情况
        if(ispartition(s)){
            vector<string> b;
            b.push_back(s);
            a.push_back(b);
        }

        return a;
    }

    bool ispartition(string s){
        bool c = true;
        string::iterator p = s.begin();
        string::iterator q = s.end()-1;
        while(p < q){
            if(*p != *q){
                c = false;
                break;
            }
            p++;
            q--;
        }

        return c;
    }
};



//解2，不直接使用得出的结果递归，用单独的一个函数来写，更方便
class Solution {
public:
    vector<vector<string>> a;
    vector<string> b;

    void kernel(string s) {
        
        int len = s.length();
        //迭代终止条件
        if(len == 1){
            b.push_back(s);
            a.push_back(b);
            b.pop_back();
            return;
        }
        if(len == 0){
            a.push_back(b);
            return;
        }
        for(int i = 1; i <= len; i++)
        {
            if(ispartition(s.substr(0,i)))
            {
                b.push_back(s.substr(0,i));
                kernel(s.substr(i));
                b.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        kernel(s);
        return a;
    }

    bool ispartition(string s){
        string::iterator p = s.begin();
        string::iterator q = s.end()-1;
        while(p < q){
            if(*p != *q){
                return false;
            }
            p++;
            q--;
        }

        return true;
    }
};