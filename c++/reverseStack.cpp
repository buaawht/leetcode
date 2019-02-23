//
// Created by buaawht on 2019-02-23.
//

/*

一个栈依次压入1,2,3,4,5那么从栈顶到栈底分别为5,4,3,2,1。将这个栈转置后，
从栈顶到栈底为1,2,3,4,5，也就是实现了栈中元素的逆序，请设计一个算法实现逆序栈的操作，
但是只能用递归函数来实现，而不能用另外的数据结构。

给定一个栈Stack，请返回逆序后的栈。

测试样例：
[1,2,3,4,5]
返回：[5,4,3,2,1]*/

#include "util.h"
class Solution {
public:
    int getRemoveLastElement(stack<int> &s) {
        if (s.empty()) {
            return -1;
        }

        int tmp = s.top();
        s.pop();
        if (s.empty()) {
            return tmp;
        }
        int last = getRemoveLastElement(s);
        s.push(tmp);
        return last;
    }


    stack<int> sortStack(stack<int> &s) {
        if (s.empty()) {
            return s;
        }

        int last = getRemoveLastElement(s);
        sortStack(s);
        s.push(last);

        return s;
    }
};

int main() {
    Solution soulution;
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    show_stack(s);
    soulution.sortStack(s);
    show_stack(s);
}
