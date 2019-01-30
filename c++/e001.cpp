//
// Created by buaawht on 2019-01-28.
//
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

/*1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

        Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] = i;
        }

        for (int j = 0; j < nums.size() ; ++j) {
            int other = target-nums[j];
            if ((m.find(other) != m.end()) && (j != m[other])) {
                res.push_back(j);
                res.push_back(m[other]);
                break;
            }
        }
        return res;
    }
};

int main() {

    Solution solution;
    std::vector<int> v = {7, 5, 16, 8};
    solution.twoSum(v, 15);
    for(int a : v) {
        std::cout << a << std::endl;
    }
}