//
// Created by buaawht on 2019-02-23.
//

/*
在一个栈中元素的类型为整型，现在想将该栈从栈顶到栈底按从大到小的顺序排序，只许申请一个栈，
 除此之外，可以申请其他变量，但是不能申请额外的数据结构，如何完成排序
 */

#include "util.h"
class Solution {
private:
    stack<int> stack2;
public:

    stack<int> sortStack(stack<int> &s) {
        while (!s.empty()) {
            int top = s.top();
            s.pop();

            if (stack2.empty()) {
                stack2.push(top);

            } else {
                int i = 0;
                while (!stack2.empty()) {
                    if (stack2.top() > top) {
                        s.push(stack2.top());
                        stack2.pop();
                        i++;
                    } else {
                        break;
                    }
                }

                stack2.push(top);

                while ((i--) > 0) {
                    stack2.push(s.top());
                    s.pop();
                }
            }

        }

        while (!stack2.empty()) {
            s.push(stack2.top());
            stack2.pop();
        }

        return s;
    }
};

int main() {
    Solution solution;
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(5);
    s.push(4);
    show_stack(s);
    solution.sortStack(s);
    show_stack(s);
}
