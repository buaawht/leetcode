//
// Created by buaawht on 2019-03-03.
//

/*
 * Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process:
 Starting with any positive integer, replace the number by the sum of the squares of its digits,
 and repeat the process until the number equals 1 (where it will stay),
 or it loops endlessly in a cycle which does not include 1.
 Those numbers for which this process ends in 1 are happy numbers.

Example:

Input: 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
 * **/


#include "util.h"

class Solution {
public:
    int cal(string s) {
        int res = 0;
        for (char n : s) {
            res = res + (n-'0') * (n-'0');
        }
        return res;
    }
    bool isHappy(int n) {
        if (n == 1) {
            return true;
        }
        set<int> set1;
        while(true) {

            string s = to_string(n);
            int tmp = cal(s);
            if (tmp == 1) {
                return true;
            }
            if (set1.count(tmp)) {
                return false;
            } else{
                set1.insert(tmp);
            }
            n = tmp;
        }
    }
};

int main() {
    Solution s;

    cout << "isHappy:" << s.isHappy(11) << endl;
    cout << "sss" << endl;
}

