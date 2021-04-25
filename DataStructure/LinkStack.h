//
// Created by Kun on 2021/4/25.
// 链栈 Link Stack
//

#ifndef CPPALGORITHM_LINKSTACK_H
#define CPPALGORITHM_LINKSTACK_H

template <typename DataType>
struct Node {
    DataType data;
    Node<DataType> *next;
};

template <typename DataType>
class LinkStack{
public:
    LinkStack();
    ~LinkStack();
    void Push(DataType x);
    DataType Pop();
    DataType GetTop();
    int Empty();
private:
    Node<DataType> *top;
};

template<typename DataType>
DataType LinkStack<DataType>::GetTop() {
    if(top == nullptr) throw "下溢";
    return top->data;
}

template<typename DataType>
int LinkStack<DataType>::Empty() {
    if(top == nullptr)
        return 1;
    else
        return 0;
}

template<typename DataType>
DataType LinkStack<DataType>::Pop() {
    if(top == nullptr) throw "下溢";
    Node<DataType> *s = top;
    DataType x = s->data;
    top = top->next;
    delete s;
    return x;
}

template<typename DataType>
LinkStack<DataType>::LinkStack() {
    top = nullptr;
}

template<typename DataType>
void LinkStack<DataType>::Push(DataType x) {
    Node<DataType> *s = new Node<DataType>;
    s->data = x;
    s->next = top;
    top = s;
}

template<typename DataType>
LinkStack<DataType>::~LinkStack() {
    Node<DataType> *p = nullptr;
    while(top != nullptr){
        p = top;
        top = top -> next;
        delete p;
    }
}


#endif //CPPALGORITHM_LINKSTACK_H
