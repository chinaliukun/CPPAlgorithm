//
// Created by Fiber-Doctor-2020 on 2021/4/20.
//

#ifndef CPPALGORITHM_SEQSTACK_H
#define CPPALGORITHM_SEQSTACK_H
const int SeqStackSize = 100;
template <typename DataType>
class SeqStack{
public:
    SeqStack();
    void Push(DataType x);
    DataType Pop();
    DataType GetTop();
    int Empty();
private:
    DataType data[SeqStackSize];
    int top;
};

template <typename DataType>
SeqStack<DataType>::SeqStack() {
    top = -1;
}

template <typename DataType>
void SeqStack<DataType>::Push(DataType x) {
    if(top == SeqStackSize - 1) throw "上溢";
    data[++top] = x;
}

template <typename DataType>
DataType SeqStack<DataType>::Pop() {
    if(top == -1) throw "下溢";
    DataType x = data[top--];
    return x;
}

template <typename DataType>
int SeqStack<DataType>::Empty() {
    if(top == -1)
        return 1;
    else
        return 0;
}

template <typename DataType>
DataType SeqStack<DataType>::GetTop() {
    if(top == -1) throw "下溢";
    return data[top];
}

#endif //CPPALGORITHM_SEQSTACK_H
