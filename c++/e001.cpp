//
// Created by buaawht on 2019-01-28.
//
#include <vector>
#include <unordered_map>
#include <iostream>
#include "util.h"

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
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            int curr = nums[i];
            int other = target - curr;
            cout << "other   " << other << endl;
            show_unorder_map(map);
            if (map.count(other) == 1) {
                return vector<int> {i, map.at(other)};
            } else {
                map[curr] = i;
            }
        }
        return vector<int>();
    }
};

int main() {
    Solution solution;
    std::vector<int> v = {7, 5, 16, 8};
    vector<int> out = solution.twoSum(v, 15);
    for(int a : out) {
        std::cout << a << std::endl;
    }
}