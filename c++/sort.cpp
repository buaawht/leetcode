//
// Created by buaawht on 2019-03-05.
//

/**
 * n种排序算法
 * 参考：https://www.cnblogs.com/onepixel/articles/7674659.html
 *
 * 插冒快速不同，快堆选谢不稳
 *
 * **/









#include "util.h"

void bubbleSort(vector<int> &a) {
    unsigned long n = a.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

void selectSort(vector<int> &a) {
    unsigned long n = a.size();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[i]) {
                swap(a[j], a[i]);
            }
        }
    }
}

void insertSort(vector<int> &a) {
    unsigned long n = a.size();

    for (int i = 1; i < n; ++i) {
        int tmp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > tmp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
    }
}

int partition(vector<int> &a, int low, int high) {
    int i = low;
    int j = high;
    int tmp = a[low];
    while (i < j) {
        while (a[j] >= tmp && i < j) j--;
        while (a[i] <= tmp && i < j) i++;
        swap(a[i], a[j]);
    }
    swap(a[low], a[i]);
    return i;
}

void quickSort(vector<int> &a, int low, int high) {
    if (low > high) {
        return;
    }

    int mid = partition(a, low, high);
    quickSort(a, low, mid - 1);
    quickSort(a, mid + 1, high);

}

void merge(vector<int> &a, int low, int mid, int high) {

    vector<int> left(a.begin() + low, a.begin() + mid + 1);
    vector<int> right(a.begin() + mid + 1, a.begin() + high + 1);

    int i = 0;
    int j = 0;
    while (i < left.size() && j < right.size()) {
        int temp;
        if (left[i] < right[j]) {
            temp = left[i++];
        } else {
            temp = right[j++];
        }
        a[low++] = temp;
    }
    while (i < left.size()) a[low++] = left[i++];
    while (j < left.size()) a[low++] = right[j++];
}

void mergeSort(vector<int> &a, int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);

}

void Merge(vector<int> &Array, int front, int mid, int end) {
    vector<int> LeftSubArray(Array.begin() + front, Array.begin() + mid + 1);
    vector<int> RightSubArray(Array.begin() + mid + 1, Array.begin() + end + 1);
    int idxLeft = 0, idxRight = 0;
    LeftSubArray.insert(LeftSubArray.end(), numeric_limits<int>::max());
    RightSubArray.insert(RightSubArray.end(), numeric_limits<int>::max());
    // Pick min of LeftSubArray[idxLeft] and RightSubArray[idxRight], and put into Array[i]
    for (int i = front; i <= end; i++) {
        if (LeftSubArray[idxLeft] < RightSubArray[idxRight]) {
            Array[i] = LeftSubArray[idxLeft];
            idxLeft++;
        } else {
            Array[i] = RightSubArray[idxRight];
            idxRight++;
        }
    }
}

void MergeSort(vector<int> &Array, int front, int end) {
    if (front >= end)
        return;
    int mid = (front + end) / 2;
    MergeSort(Array, front, mid);
    MergeSort(Array, mid + 1, end);
    Merge(Array, front, mid, end);
}

int main() {

    vector<int> v = {1, 2, 2, 1, 0, 4, 3, 8, 7, 6, 4, 2, 0};
    show_vector(v);
    bubbleSort(v);
    show_vector(v);
    cout << "------------------------------------------------------" << endl;


    v = {1, 2, 2, 1, 0, 4, 3, 8, 7, 6, 4, 2, 0};
    show_vector(v);
    selectSort(v);
    show_vector(v);
    cout << "------------------------------------------------------" << endl;


    v = {1, 2, 2, 1, 0, 4, 3, 8, 7, 6, 4, 2, 0};
    show_vector(v);
    insertSort(v);
    show_vector(v);
    cout << "------------------------------------------------------" << endl;

    v = {1, 2, 2, 1, 0, 4, 3, 8, 7, 6, 4, 2, 0};
    show_vector(v);
    quickSort(v, 0, v.size() - 1);
    show_vector(v);
    cout << "------------------------------------------------------" << endl;


    v = {1, 2, 2, 1, 0, 4, 3, 8, 7, 6, 4, 2, 0};
    show_vector(v);
    mergeSort(v, 0, v.size() - 1);
    show_vector(v);
    cout << "------------------------------------------------------" << endl;


    v = {1, 2, 2, 1, 0, 4, 3, 8, 7, 6, 4, 2, 0};
    show_vector(v);
    MergeSort(v, 0, v.size() - 1);
    show_vector(v);
    cout << "------------------------------------------------------" << endl;

}