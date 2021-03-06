//
// Created by buaawht on 2019-03-04.
//

/*
 * We are given two strings, A and B.

A shift on A consists of taking string A and moving the leftmost character to the rightmost position. For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. Return True if and only if A can become B after some number of shifts on A.

Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false
Note:

A and B will have length at most 100.
 *
 * **/

#include "util.h"

class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }

        u_long size = A.length();

        for (int i = 0; i < size; ++i) {
            if (B.substr(i, size - i) + B.substr(0, i) == A) {
                return true;
            }
        }

        return size == 0;
    }
};

int main() {
    string str = "hello";
    cout << str << str.length() << ", " << str.size() << endl;
    Solution solution;
    cout << "abcde: " << solution.rotateString("abbccd", "cdabbc") << endl;
};