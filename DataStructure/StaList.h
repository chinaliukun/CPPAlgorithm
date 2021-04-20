//
// Created by Kun on 2021/1/16.
// 静态链表 数据结构
//

#ifndef CPPALGORITHM_STALIST_H
#define CPPALGORITHM_STALIST_H
#include "iostream"
using namespace std;


template <typename DataType>
struct SNode {
    DataType data;
    int next;
};

template <typename DataType>
class StaList {
public:
    StaList();
    StaList(DataType a[], int n);
    int len();
    DataType get(int i);
    int locate(DataType x);
    void insert(DataType x, int p);
    DataType del(int i);
    int isEmpty();
    void printList();
private:
    const static int MaxSize = 1000;
    SNode<DataType> Slist[1000];
    int first, avail;
    int length;
};

// 因为是静态分配 所以不需要析构函数

template <typename DataType> StaList<DataType>::StaList(DataType a[], int n){
    if (n > MaxSize) throw "超过最大容量！";
    first = avail = 0;
    for (int i = 0; i < n; ++i) {
        Slist[i].data = a[i];
        Slist[i].next = i + 1;
    }
    Slist[n-1].next = -1;
}

template <typename DataType> StaList<DataType>::StaList(){
    first = avail = 0;
    for (int i = 0; i < MaxSize-1; ++i) {
        Slist[i].next = i+1;
    }
    Slist[MaxSize-1].next = -1;
}

template <typename DataType> int StaList<DataType>::len(){
    return length;
}

template <typename DataType> void StaList<DataType>::insert(DataType x, int p){
    if (Slist[avail].next == -1) throw "空间不足！";
    int s = avail;
    avail = Slist[avail].next;
    Slist[s].data = x;
    Slist[s].next = Slist[p].next;
    Slist[p].next = s;
}

template <typename DataType> DataType StaList<DataType>::del(int p) {
    if (avail == first) throw "静态链表为空！";
    DataType q = Slist[p].next;
    Slist[p].next = Slist[q].next;
    Slist[q].next = avail;
    avail = q;
    return q;
}

template <typename DataType> void StaList<DataType>::printList() {
    int s = 0;
    while (Slist[s].next != -1){
        cout << Slist[s].data << ' ';
        s ++;
    }
    cout << endl;
}

#endif //CPPALGORITHM_STALIST_H
