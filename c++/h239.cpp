//
// Created by buaawht on 2019-02-23.
//

/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array
 to the very right. You can only see the k numbers in the window. Each time the sliding window moves
 right by one position. Return the max sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7]
Explanation:

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Note:
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
 */
#import "util.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> deque1;
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {

            if (!deque1.empty() && (i - k) == deque1.front()) {
                deque1.pop_front();
            }

            while (!deque1.empty() && nums[deque1.back()] < nums[i]) {
                deque1.pop_back();
            }

            deque1.push_back(i);
            if (i >= k - 1) {
                res.push_back(nums[deque1.front()]);
            }
        }

        return res;
    }
};

int main() {
    vector<int> v = {1, 3, -1, -3, 5, 3, 6, 7};
    show_vector(v);
    Solution s;
    vector<int> res = s.maxSlidingWindow(v, 3);
    show_vector(res);
}


/*
思路：

这道题本来我使用的是O(N^2)的方法，后来学习了LeetCode上别人的解法，在此记录一下。

这个方法使用了一个双端队列来保存来保存窗口中的数据的index，对这个队列的具体操作如下
 【虽然队列中保存的是index，但是为了方便描述，就直接描述为数据】：

1. 在插入新数据的时候，如果队列为空就直接插入

2. 如果队列不为空就判断新数据和队尾元素的大小，如果队尾元素小于新数据，那么我们可以确定，在包含队尾元素和新数据的窗口里面，
 一定是新数据最大，有了这个假设，我们就可以把队尾元素移除队列，然后重复这个比较，直到遇到一个比新数据大的数才停止出队列，
 然后再把新数据插入。

这个就保证了，在队首的数据一定是当前窗口中最大的，然后队首后面的是次大的数据，依次类推，我们只需要在每次更新窗口的时候
 【因为只有更新窗口才会有新数据插入】把队首元素提取出来，即可得到结果
*/
