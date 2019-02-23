//
// Created by buaawht on 2019-02-12.
//

#ifndef C_UTIL_H
#define C_UTIL_H

#endif //C_UTIL_H

#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <iostream>
#include <stack>
using namespace std;


template <typename T>
void show_vector(vector<T> v)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << ", ";
    }
    cout << endl;
}

template <typename T>
void show_set(set<T> v) {
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << ", ";
    }
    cout << endl;
}

template <typename T, typename P>
void show_map(map<T , P> v)
{
    for (auto it = v.begin(); it!= v.end(); it++)
    {
        //注意用法，不是用*it来访问了。first表示的是key，second存的是value
        cout << it->first << "  " << it->second << endl;
    }
    cout << endl;
}

template <typename T, typename P>
void show_unorder_map(unordered_map <T , P> v)
{
    for (auto &it : v) {
        //注意用法，不是用*it来访问了。first表示的是key，second存的是value
        cout << it.first << ": " << it.second << endl;
    }
    cout << endl;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

void show_list_node(ListNode *head)
{
    while (head!= nullptr) {
        cout << head->val << " ---> ";
        head = head ->next;
    }
    cout << endl;
}

void show_stack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << ", ";
        s.pop();
    }
    cout << endl;
}
