//
// Created by Fiber-Doctor-2020 on 2021/1/14.
//

#ifndef CPPALGORITHM_LINKLIST_H
#define CPPALGORITHM_LINKLIST_H
# include "iostream"
using  namespace  std;

// 链表节点 node 结构
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
    // 头结点
    Node<DataType> *first;
    int length = 0;
};
// 函数定义区

// 获得长度
template<typename DataType>  int LinkList<DataType>::len() {
    return length;
}

// 无参构造函数
template<typename DataType>  LinkList<DataType>::LinkList() {
    first = new Node<DataType>;
    first -> next = nullptr;
    length = 0;
}

// 有参构造函数 头插法
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

// 有参构造函数 尾插法
template<typename DataType> LinkList<DataType>::LinkList(DataType a[], int n) {
    length = 0;
    first = new Node<DataType>;
    first -> next = nullptr;
    Node<DataType> *r = first, *s = nullptr;
    for ( int i = 0; i < n; i++) {
        // 新建一个节点
        s = new Node<DataType>;
        s -> data = a[i];
        s -> next = nullptr;
        // 将尾节点 next 指针指向 s
        r -> next = s;
        // 将尾指针后移一个元素
        r = s;
        // 长度+1 注意该长度不包含头结点
        length ++;
    }
}

// 析构函数 动态申请的存储空间在运行结束前一定要销毁
template<typename DataType> LinkList<DataType>::~LinkList() {
    Node<DataType> *p = first -> next, *q = nullptr;
    for (int i = 0; i < length; ++i) {
        q = p -> next;
        delete p;
        p = q;
    }
}

// 插入操作
template<typename DataType> void LinkList<DataType>::insert(DataType x, int i) {
    if ( i > length ) {
        throw "参数非法";
    }
    Node<DataType> *p = first, *s = nullptr;
    s = new Node<DataType>;
    // 找到要插入位置的前一个节点
    for (int j = 0; j < i - 1; ++j) {
        p = p -> next;
    }
    s -> data = x;
    s -> next = p -> next;
    p -> next = s;
    length ++;
}

// 删除操作
template<typename DataType> DataType LinkList<DataType>::del(int i) {
    if ( i > length ) throw "参数非法";
    Node<DataType> *p = first, *t = nullptr;
    DataType x;
    // 移动到待删除节点的前一个节点
    for (int j = 0; j < i - 1; ++j) {
        p = p -> next;
    }
    // 临时指针指向待删除节点
    t = p -> next;
    // 保存删除的元素值
    x = t -> data;
    p -> next = t -> next;
    // 删除该节点
    delete t;
    length --;
    return x;
}

// 按位查找
template<typename DataType> DataType LinkList<DataType>::get(int i) {
    if( i > length ) throw "参数非法";
    Node<DataType> *p = first;
    for (int j = 0; j < i; ++j) {
        p = p -> next;
    }
    return p -> data;
}

// 按值查找
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

// 判空操作
template<typename DataType>  int LinkList<DataType>::isEmpty() {
    if( length == 0 ) {
        return 1;
    }else {
        return 0;
    }
}

// 打印单链表
template<typename DataType> void LinkList<DataType>::printList() {
    Node<DataType> *p = first;
    for (int i = 0; i < length; ++i) {
        p = p -> next;
        cout << p -> data << "\t";
    }
    cout << endl;
}

#endif //CPPALGORITHM_LINKLIST_H
