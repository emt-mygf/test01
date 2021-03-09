#include <string.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;


//解1，使用广度优先搜索，超时了（时间够的话能算出正确结果）
class Solution {
public:
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

    vector<vector<bool>> helper(string s){
        int len = s.length();
        vector<vector<bool>> h;
        vector<bool> e;
        for(int i = 0; i < len; i++){
            for(int j = 1; j <= len-i; j++){
                if(ispartition(s.substr(i,j))) e.push_back(true);
                else e.push_back(false);
            }
            h.push_back(e);
            e.clear();
        }
        return h;
    }

    int minCut(string s) {
        vector<vector<bool>> help = helper(s);
        int l = s.length();

        queue<int> search;
        int head;
        int count;

        search.push(0);
        search.push(0);

        head = search.front();
        search.pop();
        count = search.front();
        search.pop();

        while(head != l){
            if(help[head][l-head-1]){
                head = l;
                break;
            }
            count++;
            for(int i = l-head-1;i >= 1;i--){
                if(help[head][i-1]){
                    search.push(head+i);
                    search.push(count);
                }
            }
            head = search.front();
            search.pop();
            count = search.front();
            search.pop();
        }

        return count;
    }
};



//解2，用了别人的判断是否回文串的表，还是超时，看来这题广度优先不太行了
class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> isPalindromic(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] && (j - i <= 1 || isPalindromic[i + 1][j - 1])) {
                    isPalindromic[i][j] = true;
                }
            }
        }

        int l = s.length();

        queue<int> search;
        int head;
        int count;

        search.push(0);
        search.push(0);

        head = search.front();
        search.pop();
        count = search.front();
        search.pop();

        while(head != l){
            if(isPalindromic[head][l-1]){
                head = l;
                break;
            }
            count++;
            for(int i = l-1;i >= head+1;i--){
                if(isPalindromic[head][i-1]){
                    search.push(i);
                    search.push(count);
                }
            }
            head = search.front();
            search.pop();
            count = search.front();
            search.pop();
        }

        return count;
    }
};