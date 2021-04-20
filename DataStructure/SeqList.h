//
// Created by Kun on 2021/1/14.
//
// C++ ��ģ�庯�������������Ҫ�ŵ�һ��
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


// �޲ι��캯��
template <typename DataType> SeqList<DataType>::SeqList() {
    length = 0;
}

// �вι��캯��
template <typename DataType> SeqList<DataType>::SeqList(DataType a[], int n) {
    if(n > MaxSize){
        throw "�����Ƿ�";
    }
    for(int i = 0; i < n; i++) {
        data[i] = a[i];
    }
    length = n;
}

// �жϵ�ǰ����
template <typename DataType> int SeqList<DataType>::len() {
    return length;
}

// ��λ����
template <typename DataType> DataType SeqList<DataType>::get(int i) {
    if(i>length || i<1) {
        throw "�����Ƿ�";
    }
    return data[i-1];
}

// ��ֵ����
template <typename DataType> int SeqList<DataType>::locate(DataType x) {
    for (int i = 0; i < length; i++) {
        if(data[i] == x)
            return i + 1;
    }
    // �������ʧ�ܷ���0
    return 0;
}

// �������
template <typename DataType> void SeqList<DataType>::insert(int i, DataType x) {
    if(length >= MaxSize) throw "˳�������";
    if(i > length + 1 || i < 1) throw "�������Ϸ�";
    // �ƶ�Ԫ��
    for(int j = length - 1; j >= i - 1; j--){
        data[j + 1] = data[j];
    }
    // ����Ԫ��
    data[i - 1] = x;
    length ++;
}

// ɾ������
template <typename DataType> DataType SeqList<DataType>::del(int i) {
    if(length == 0) throw "˳�������";
    if(i <1 || i > length) throw "�����Ƿ�";
    // �����Ԫ��ֵ
    DataType ret = data[i];
    // �ƶ�Ԫ��ֵ
    for(int j = i - 1; j < length - 1; j ++)
        data[j] = data[j + 1];
    length --;
    return ret;
}

// �пղ���
template <typename DataType> int SeqList<DataType>::isEmpty() {
    if(length == 0)
        return 1;
    else
        return 0;
}

// ��ӡ�б�
template <typename DataType> void SeqList<DataType>::printList() {
    for(int i = 0; i < length; i++){
        cout<< data[i] << "\t";
    }
    cout << endl;
}


#endif //CPPALGORITHM_SEQLIST_H
