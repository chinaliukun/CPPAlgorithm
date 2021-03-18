//
// Created by Fiber-Doctor-2020 on 2021/1/16.
//

#ifndef CPPALGORITHM_STALIST_H
#define CPPALGORITHM_STALIST_H

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
    ~StaList();
    StaList(DataType a[], int n);
    int len();
    DataType get(int i);
    int locate(DataType x);
    void insert(DataType x, int n);
    DataType del(int i);
    int isEmpty();
    void printList();
private:
    SNode
};

template <typename DataType> StaList::StaList() {

}

template <typename DataType> StaList::~StaList() {

}

#endif //CPPALGORITHM_STALIST_H
