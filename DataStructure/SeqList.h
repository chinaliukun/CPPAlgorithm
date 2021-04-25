//
// Created by Kun on 2021/1/14.
//
// C++ 的模板函数定义和声明需要放到一起！
#ifndef CPPALGORITHM_SEQLIST_H
#define CPPALGORITHM_SEQLIST_H
#include "iostream"
using namespace std;

template <typename DataType> class SeqList {
public:
    SeqList();
    SeqList(DataType a[], int n);
    int len();
    DataType get(int i);
    int locate(DataType x);
    void insert(int i, DataType x);
    DataType del(int i);
    int isEmpty();
    void printList();

private:
    const static int MaxSize = 1000;
    DataType data[MaxSize];
    int length = 0;
};


// 无参构造函数
template <typename DataType> SeqList<DataType>::SeqList() {
    length = 0;
}

// 有参构造函数
template <typename DataType> SeqList<DataType>::SeqList(DataType a[], int n) {
    if(n > MaxSize){
        throw "参数非法";
    }
    for(int i = 0; i < n; i++) {
        data[i] = a[i];
    }
    length = n;
}

// 判断当前长度
template <typename DataType> int SeqList<DataType>::len() {
    return length;
}

// 按位查找
template <typename DataType> DataType SeqList<DataType>::get(int i) {
    if(i>length || i<1) {
        throw "参数非法";
    }
    return data[i-1];
}

// 按值查找
template <typename DataType> int SeqList<DataType>::locate(DataType x) {
    for (int i = 0; i < length; i++) {
        if(data[i] == x)
            return i + 1;
    }
    // 如果查找失败返回0
    return 0;
}

// 插入操作
template <typename DataType> void SeqList<DataType>::insert(int i, DataType x) {
    if(length >= MaxSize) throw "顺序表上溢";
    if(i > length + 1 || i < 1) throw "参数不合法";
    // 移动元素
    for(int j = length - 1; j >= i - 1; j--){
        data[j + 1] = data[j];
    }
    // 插入元素
    data[i - 1] = x;
    length ++;
}

// 删除操作
template <typename DataType> DataType SeqList<DataType>::del(int i) {
    if(length == 0) throw "顺序表下溢";
    if(i <1 || i > length) throw "参数非法";
    // 保存好元素值
    DataType ret = data[i];
    // 移动元素值
    for(int j = i - 1; j < length - 1; j ++)
        data[j] = data[j + 1];
    length --;
    return ret;
}

// 判空操作
template <typename DataType> int SeqList<DataType>::isEmpty() {
    if(length == 0)
        return 1;
    else
        return 0;
}

// 打印列表
template <typename DataType> void SeqList<DataType>::printList() {
    for(int i = 0; i < length; i++){
        cout<< data[i] << "\t";
    }
    cout << endl;
}


#endif //CPPALGORITHM_SEQLIST_H
