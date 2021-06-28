#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int l = s.size();
        if(s[0] == '0') return 0;
        else if(l == 1) return 1;
        else {
            int x = 1,y = 1,n = 1;
            while(n < l){
                if(s[n] == '0'){
                    if(s[n-1] == '1' || s[n-1] == '2'){
                        int z = y;
                        y = x;
                        x = z;
                    }
                    else{
                        int z = y;
                        y = 0;
                        x = z;
                    }
                }
                else{
                    if(s[n-1] == '1' || (s[n-1] == '2' && s[n] <= '6' )){
                        int z = y;
                        y = x+y;
                        x = z;
                    }
                    else{
                        x = y;
                    }
                }
                if(x == 0 && y == 0) return 0;
                n++;
            }
            return y;
        }

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
        
        int ret = Solution().numDecodings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}