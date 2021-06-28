#include <cassert>
#include <stack>
#include <iostream>
#include <string>
using namespace std;


//利用栈进行后序遍历，不需要写一个树结构
class Solution {
public:
    stack<int> s1;
    stack<char> s2;
    stack<int> n;
    int cal(int a,int b,char x){
        if(x == '+') return a+b;
        else return a-b;
    }
    int calculate(string s) {
        int m = 0;
        bool flag = false;
        string::iterator st = s.end()-1;
        while(st >= s.begin()){
            switch(*st){
                case '+':
                    while(!n.empty()){
                        flag = true;
                        m = 10*m+n.top();
                        n.pop();
                    }
                    //检查是否为连续运算符，若是，则没必要给操作数栈压栈
                    if(flag){
                        s1.push(m);
                        m=0;
                        flag = false;
                    }
                    s2.push('+');
                    break;
                case '-':
                    while(!n.empty()){
                        flag = true;
                        m = 10*m+n.top();
                        n.pop();
                    }
                    if(flag){
                        s1.push(m);
                        m=0;
                        flag = false;
                    }
                    s2.push('-');
                    break;
                case ')':
                    s2.push(')');
                    break;
                case ' ':
                    break;
                case '(':
                    if((*(st+1) == '-')||(*(st+1) == '+')) s1.push(0);
                    while(!n.empty()){
                        flag = true;
                        m = 10*m+n.top();
                        n.pop();
                    }
                    if(flag){
                        s1.push(m);
                        m=0;
                        flag = false;
                    }
                    while(s2.top() != ')'){
                        int a = s1.top();
                        s1.pop();
                        int b = s1.top();
                        s1.pop();
                        char x = s2.top();
                        s2.pop();
                        s1.push(cal(a,b,x));
                    }
                    s2.pop();
                    break;
                default :
                    //注意这是ascll码
                    n.push(int(*st)-48);
                    break;
            }
            st--;
        }
        if((*(st+1) == '-')||(*(st+1) == '+')) s1.push(0);
        while(!n.empty()){
            flag = true;
            m = 10*m+n.top();
            n.pop();
        }
        if(flag){
            s1.push(m);
            m=0;
            flag = false;
        }
        while(!s2.empty()){
                        int a = s1.top();
                        s1.pop();
                        int b = s1.top();
                        s1.pop();
                        char x = s2.top();
                        s2.pop();
                        s1.push(cal(a,b,x));
                    }
        if(s1.empty()) return 0;
        return s1.top();
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().calculate(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}



//这题可以不用先算括号内，而是直接去括号（二则运算简单）
class Solution {
public:
    int calculate(string s) {
        stack<int> op;
        op.push(1);
        int sign=1;
        long num;
        int i=0;
        int res=0;
        while(i<s.size())
        {
            if(s[i]==' ')
            {
                i++;
            }
            else if(s[i]=='+')
            {
                sign=op.top();
                i++;
            }
            else if(s[i]=='-')
            {
                sign=-op.top();
                i++;
            }
            else if(s[i]=='(')
            {
                op.push(sign);
                i++;
            }
            else if(s[i]==')')
            {
                op.pop();
                i++;
            }
            num=0;
            while(i<s.size()&&isdigit(s[i]))
            {
                num=num*10+s[i]-'0';
                i++;
            }
            res+=sign*num;
        }
        return res;
    }
};