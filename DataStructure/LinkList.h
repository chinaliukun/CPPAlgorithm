//
// Created by Fiber-Doctor-2020 on 2021/1/14.
//

#ifndef CPPALGORITHM_LINKLIST_H
#define CPPALGORITHM_LINKLIST_H
# include "iostream"
using  namespace  std;

// ����ڵ� node �ṹ
template <typename DataType>
struct Node {
    DataType data;
    Node<DataType> *next;
};

template <typename DataType>
class LinkList {
public:
    LinkList();
    LinkList(DataType a[], int n);
    ~LinkList();
    int len();
    DataType get(int i);
    int locate(DataType x);
    void insert(DataType x, int n);
    DataType del(int i);
    int isEmpty();
    void printList();

private:
    // ͷ���
    Node<DataType> *first;
    int length = 0;
};
// ����������

// ��ó���
template<typename DataType>  int LinkList<DataType>::len() {
    return length;
}

// �޲ι��캯��
template<typename DataType>  LinkList<DataType>::LinkList() {
    first = new Node<DataType>;
    first -> next = nullptr;
    length = 0;
}

// �вι��캯�� ͷ�巨
//template<typename DataType> LinkList<DataType>::LinkList(DataType a[], int n) {
//    first = new Node<DataType>;
//    first -> next = nullptr;
//    for( int i = 0; i < n; i ++ ) {
//        Node<DataType> *s = nullptr;
//        s = new Node<DataType>;
//        s -> data = a[i];
//        s -> next = first -> next;
//        first -> next = s;
//    }
//}

// �вι��캯�� β�巨
template<typename DataType> LinkList<DataType>::LinkList(DataType a[], int n) {
    length = 0;
    first = new Node<DataType>;
    first -> next = nullptr;
    Node<DataType> *r = first, *s = nullptr;
    for ( int i = 0; i < n; i++) {
        // �½�һ���ڵ�
        s = new Node<DataType>;
        s -> data = a[i];
        s -> next = nullptr;
        // ��β�ڵ� next ָ��ָ�� s
        r -> next = s;
        // ��βָ�����һ��Ԫ��
        r = s;
        // ����+1 ע��ó��Ȳ�����ͷ���
        length ++;
    }
}

// �������� ��̬����Ĵ洢�ռ������н���ǰһ��Ҫ����
template<typename DataType> LinkList<DataType>::~LinkList() {
    Node<DataType> *p = first -> next, *q = nullptr;
    for (int i = 0; i < length; ++i) {
        q = p -> next;
        delete p;
        p = q;
    }
}

// �������
template<typename DataType> void LinkList<DataType>::insert(DataType x, int i) {
    if ( i > length ) {
        throw "�����Ƿ�";
    }
    Node<DataType> *p = first, *s = nullptr;
    s = new Node<DataType>;
    // �ҵ�Ҫ����λ�õ�ǰһ���ڵ�
    for (int j = 0; j < i - 1; ++j) {
        p = p -> next;
    }
    s -> data = x;
    s -> next = p -> next;
    p -> next = s;
    length ++;
}

// ɾ������
template<typename DataType> DataType LinkList<DataType>::del(int i) {
    if ( i > length ) throw "�����Ƿ�";
    Node<DataType> *p = first, *t = nullptr;
    DataType x;
    // �ƶ�����ɾ���ڵ��ǰһ���ڵ�
    for (int j = 0; j < i - 1; ++j) {
        p = p -> next;
    }
    // ��ʱָ��ָ���ɾ���ڵ�
    t = p -> next;
    // ����ɾ����Ԫ��ֵ
    x = t -> data;
    p -> next = t -> next;
    // ɾ���ýڵ�
    delete t;
    length --;
    return x;
}

// ��λ����
template<typename DataType> DataType LinkList<DataType>::get(int i) {
    if( i > length ) throw "�����Ƿ�";
    Node<DataType> *p = first;
    for (int j = 0; j < i; ++j) {
        p = p -> next;
    }
    return p -> data;
}

// ��ֵ����
template<typename DataType> int LinkList<DataType>::locate(DataType x) {
    int pos = 0;
    Node<DataType> *p = first;
    for (int j = 0; j < length; ++j) {
        p = p -> next;
        if ( p -> data == x ) {
            pos = j + 1;
            break;
        }
    }
    return pos;
}

// �пղ���
template<typename DataType>  int LinkList<DataType>::isEmpty() {
    if( length == 0 ) {
        return 1;
    }else {
        return 0;
    }
}

// ��ӡ������
template<typename DataType> void LinkList<DataType>::printList() {
    Node<DataType> *p = first;
    for (int i = 0; i < length; ++i) {
        p = p -> next;
        cout << p -> data << "\t";
    }
    cout << endl;
}

#endif //CPPALGORITHM_LINKLIST_H
