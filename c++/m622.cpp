//
// Created by buaawht on 2019-02-26.
//

/*
622. Design Circular Queue
Share
Design your implementation of the circular queue.
 The circular queue is a linear data structure in which the operations are performed based on
 FIFO (First In First Out) principle and the last position is connected back to the first position
 to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue.
 In a normal queue, once the queue becomes full, we cannot insert the next element even if
 there is a space in front of the queue. But using the circular queue, we can use the space to
 store new values.

Your implementation should support following operations:

MyCircularQueue(k): Constructor, set the size of the queue to be k.
Front: Get the front item from the queue. If the queue is empty, return -1.
Rear: Get the last item from the queue. If the queue is empty, return -1.
enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
isEmpty(): Checks whether the circular queue is empty or not.
isFull(): Checks whether the circular queue is full or not.


Example:

MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3
circularQueue.enQueue(1);  // return true
circularQueue.enQueue(2);  // return true
circularQueue.enQueue(3);  // return true
circularQueue.enQueue(4);  // return false, the queue is full
circularQueue.Rear();  // return 3
circularQueue.isFull();  // return true
circularQueue.deQueue();  // return true
circularQueue.enQueue(4);  // return true
circularQueue.Rear();  // return 4

Note:

All values will be in the range of [0, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in Queue library.*/

#include "util.h"

class MyCircularQueue {
public:
    vector<int> q;
    int head;
    int rear;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : q(k+1, 0), head(0), rear(0) {

    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        q[rear] = value;
        rear = (++rear) % q.size();
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        head = ++head % q.size();
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return q[head];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        cout << "(rear - 1) % q.size()" << (rear - 1) % q.size() << endl;
        return q[(rear - 1) < 0 ? q.size()-1 : (rear - 1) % q.size()];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == rear;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (rear + 1) % q.size() == head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int show_ele(MyCircularQueue *q) {
    cout << "head=" << q->head << ", rear=" << q->rear << endl;
    show_vector(q->q);
    cout << "---------------" <<endl;
    return 0;
}

int main() {

    MyCircularQueue* obj = new MyCircularQueue(4);
    show_ele(obj);
    cout << "out:" << obj->enQueue(3) << " enQueue(3)"<< endl;
    show_ele(obj);

    cout << "out:" << obj->enQueue(7) << " enQueue(7)" << endl;
    show_ele(obj);

    cout << "out:" << obj->enQueue(2) << " enQueue(2)"<< endl;
    show_ele(obj);

    cout << "out:" << obj->enQueue(5) << " enQueue(5)"<< endl;
    show_ele(obj);

    cout << "out:" << obj->deQueue() << " deQueue()" << endl;
    show_ele(obj);

    cout << "out:" << obj->enQueue(4) << " enQueue(4)" << endl;
    show_ele(obj);

    cout << "out:" << obj->enQueue(2) << " enQueue(2)" << endl;
    show_ele(obj);

    cout << "out:" << obj->Rear() <<" Rear()"<< endl;
    show_ele(obj);

    cout << -1 %100 << endl;

}
