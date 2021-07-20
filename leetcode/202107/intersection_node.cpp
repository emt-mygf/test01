/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
    //关键是两链表公共节点之后就一直走一块一直到结尾，属于是公共尾端
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ans(0);
        //边界条件
        if(headA == NULL || headB == NULL) return ans;

        //统计信息
        int lA = 1, lB = 1;
        auto pA = headA;
        auto pB = headB;
        while(pA->next != NULL) {
            pA = pA->next;
            ++lA;
        }
        while(pB->next != NULL) {
            pB = pB->next;
            ++lB;
        }

        //修剪+遍历
        auto gA = headA;
        auto gB = headB;
        if(lA > lB) {
            for(int i = 0; i<lA-lB; ++i) gA = gA->next;
        }
        else if(lB > lA) {
            for(int i = 0; i<lB-lA; ++i) gB = gB->next;
        }

        while(gA != gB) {
            if(gA->next == NULL) break;
            gA = gA->next;
            gB = gB->next;
        }

        if(gA == gB) ans = gA;

        return ans;
    }
};
class Solution2 {
public:
    //本质一样，但是好看
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ans(0);
        //边界条件
        if(headA == NULL || headB == NULL) return ans;

        //双指针遍历
        auto pA = headA;
        auto pB = headB;
        int flag = 0;

        while(pA != pB) {
            if(pA->next == NULL) {
                ++flag;
                if(flag == 2) break;
                pA = headB;
            }
            else pA = pA->next;
            
            if(pB->next == NULL) {
                pB = headA;
            }
            else pB = pB->next;
        }

        if(pA == pB) ans = pA;

        return ans;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int intersectVal = stringToInteger(line);
        getline(cin, line);
        ListNode* listA = stringToListNode(line);
        getline(cin, line);
        ListNode* listB = stringToListNode(line);
        getline(cin, line);
        int skipA = stringToInteger(line);
        getline(cin, line);
        int skipB = stringToInteger(line);
        
        ListNode* ret1 = Solution1().getIntersectionNode(listA, listB);
        ListNode* ret2 = Solution2().getIntersectionNode(listA, listB);

        string out1 = listNodeToString(ret1);
        string out2 = listNodeToString(ret2);
        cout << out1 << endl;
        cout << out2 << endl;

    }
    return 0;
}