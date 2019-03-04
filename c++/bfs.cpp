//
// Created by buaawht on 2019-02-28.
//

/**
 * Return the length of the shortest path between root and target node.
 */

#include <tclDecls.h>
#include "util.h"

struct Node {
    int val;
    vector<Node> neighbors;
};

int BFS(Node root, Node target) {
    // store all nodes which are waiting to be processed
    queue<Node> q;
    // number of steps neeeded from root to current node
    int step = 0;
    // initialize
    q.push(root);

    // BFS
    while (!q.empty()) {
        step = step + 1;
        // iterate the nodes which are already in the queue
        int size = q.size();

        Node cur = q.front();
        q.pop();

        if (cur.val == target.val) {
            return step;
        }

        for (Node next : cur.neighbors) {
            q.push(next);
        }
    }
    return -1;// there is no path from root to target
}