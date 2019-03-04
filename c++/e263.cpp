//
// Created by buaawht on 2019-03-03.
//
#include "util.h"
class Solution {
public:

    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        }

        while (num > 1) {
            if (num % 2 == 0) {
                num = num / 2;
            } else if (num % 3 == 0) {
                num = num / 3;
            } else if (num % 5 == 0) {
                num = num / 5;
            } else {
                return false;
            }
        }
        return true;

    }
};

int main() {
    Solution s;
    cout << s.isUgly(14) << endl;
    cout << s.isUgly(60) << endl;
}

