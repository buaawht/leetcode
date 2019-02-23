//
// Created by buaawht on 2019-02-23.
//

/**
Given a string S and a string T, find the minimum window in S which will contain
 all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANCE", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
 */


#include "util.h"

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int>map1;
        for (char j : t) {
            map1[j] = 0;
        }

        int left, right = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (map1.count(c)) {
                map1[c] += 1;
            }


        }
    }
};